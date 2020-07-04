// Use a BufferedReader to read characters from the console.
import java.io.*;

class BRRead {
	public static void main(String[] args) throws IOException
	{
		char c;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter characters, 'q' to quit.");
		// read characters
		while ((c = (char) br.read()) != 'q')
			System.out.println(c);
	}
}