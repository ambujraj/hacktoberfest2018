import asyncio
import json
import argparse
import os
from datetime import datetime

addr = "127.0.0.1"
port = 50000

class ProxyProtocol(asyncio.Protocol):
    def __init__(self, connections, users, loop):
        self.connections = connections
        self.users = users
        self.loop = loop
        self.peername = ""
        
    def connection_made(self, transport):
        print(transport.get_extra_info('sockname'))
        self.connections += [transport]
        peername = transport.get_extra_info('sockname')
        self.transport = transport

    def connection_lost(self, exc):
        self.connections.remove(self.transport)
        
    def data_received(self, data):
        if data:
            host = self.parse(data)
            if host.startswith(b"https://"):
                port = 443
                host = host[8:]
            elif host.startswith(b"http://"):
                port = 90
                host = host[7:]
            else:
                port = 90
            host = host.split(b"/")[0]
            split = host.split(b":")
            #if len(split) > 1:
            #    port = int(split[1])
            host = split[0]
            ptcl = ConnectionProtocol(self, data)
            coro = loop.create_connection(lambda: ptcl, addr, port)
            server = asyncio.ensure_future(coro)            

    def parse(self, data):
        return data.split()[4]

    def proxy_data_recv(self, data):
        self.transport.write(data)
        self.transport.close()

class ConnectionProtocol(asyncio.Protocol):
    def __init__(self, proxy, data):
        self.proxy = proxy
        self.data = data

    def connection_made(self, transport):
        self.transport = transport
        self.transport.write(self.data)

    def data_received(self, data):
        self.proxy.proxy_data_recv(data)
        self.transport.close()

connections = []
users = []
loop = asyncio.get_event_loop()
print("{}:{}".format(addr, port))
coro = loop.create_server(lambda: ProxyProtocol(connections, users, loop), addr, port)
server = loop.run_until_complete(coro)
loop.run_forever()
server.close()
loop.run_until_complete(server.wait_closed())
loop.close()
