import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server = input('Input server IP address: ')

def pscan(port):
	try:
		s.connect((server,port))
		return True
	except:
		return False

for x in range(1,26):
	if pscan(x):
		print('Port ',x,' is open')
	else:
		print('Port ',x,' is closed')
