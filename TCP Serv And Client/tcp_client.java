import java.io.*;
import java.net.*;

public class tcp_client {
	public static void main(String[] args) throws Exception {
		Socket sock = new Socket("127.0.0.1", 4000);
		System.out.println("Enter the file name");

		BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));
		String fname = keyRead.readLine();

		OutputStream ostream = sock.getOutputStream();
		PrintWriter pwrite = new PrintWriter(ostream, true);
		pwrite.println(fname);
		InputStream istream = sock.getInputStream();
		BufferedReader socketRead = new BufferedReader(new InputStreamReader(istream));
		String str;
		while ((str = socketRead.readLine()) != null) {
			System.out.println(str);
		}
		pwrite.close();
		socketRead.close();
		keyRead.close();
		sock.close();
	}
}
