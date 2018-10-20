import java.io.*;
import java.net.*;

class udp_serv {
	public static void main(String[] args) {
		try {
			int i = 5000;
			String fooString1 = new String("Exit");
			while (true) {
				InetAddress clientIP = InetAddress.getByName("127.0.0.1");
				int clientPort = i;
				byte buf[] = new byte[1024];
				DatagramSocket ds = new DatagramSocket();
				BufferedReader dis = new BufferedReader(new InputStreamReader(System.in));
				System.out.println("Server is running...");
				String str1 = new String(dis.readLine());
				if (str1.equals(fooString1)) {
					ds.close();
					break;
				} else {
					buf = str1.getBytes();
					DatagramPacket packet = new DatagramPacket(buf, str1.length(), clientIP, clientPort);
					ds.send(packet);
					i = i + 1;
				}
			}
		} catch (Exception e) {
			System.out.println("ERROR! File not found: " + e);
		}
	}
}
