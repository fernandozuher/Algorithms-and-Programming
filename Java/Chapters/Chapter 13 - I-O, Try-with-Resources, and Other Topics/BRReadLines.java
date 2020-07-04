// Read a string from console using a BufferedReader
import java.io.*;

class BRReadLines {
	public static void main(String[] args) throws IOException
	{
		// create a BufferedReader using System.in
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str;
		System.out.println("Enter lines of text.");
		System.out.println("Enter 'stop' to quit.");
		// read characters
		while (!(str = br.readLine()).equals("stop"))
			System.out.println(str);
	}
}