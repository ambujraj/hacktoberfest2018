import java.net.*;
import java.io.*;
public class tcp_serv{
	public static void main(String [] args) throws Exception{
		ServerSocket sersock = new ServerSocket(4000);
		System.out.println("Server ready for connection");
		Socket sock = sersock.accept();
		System.out.println("Connection is successfull and waiting for chat");
		InputStream istream = sock.getInputStream();
		BufferedReader fileRead = new BufferedReader(new InputStreamReader(istream));
		String fname = fileRead.readLine();
		BufferedReader contentRead = new BufferedReader(new FileReader(fname));
		OutputStream ostream = sock.getOutputStream();
		PrintWriter pwrite = new PrintWriter(ostream,true);
		String str;
		while((str=contentRead.readLine())!=null){
			pwrite.println(str);
		}
		sock.close();
		sersock.close();
		pwrite.close();
		fileRead.close();
		contentRead.close();
	}
}
