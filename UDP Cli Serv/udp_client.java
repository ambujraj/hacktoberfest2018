import java.io.*;
import java.net.*;

class udp_client {
	public static void main(String args[]) throws IOException {
		int i = 5000;
		while (true) {
			byte buf[] = new byte[1024];
			DatagramSocket ds = new DatagramSocket(i);
			DatagramPacket dp = new DatagramPacket(buf, buf.length);
			ds.receive(dp);
			String str2 = new String(dp.getData(), 0, dp.getLength());
			System.out.println("Server:" + str2);
			System.out.println("*******");
			i = i + 1;
		}
	}
}
