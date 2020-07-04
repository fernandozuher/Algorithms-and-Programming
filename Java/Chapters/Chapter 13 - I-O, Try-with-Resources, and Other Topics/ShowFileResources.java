/* This version of the ShowFile program uses a try-with-resources
   statement to automatically close a file after it is no longer needed.
*/

import java.io.*;

class ShowFileResources {
	public static void main(String[] args) {
		int i;

		// First, confirm that a filename has been specified.
		if (args.length != 1) {
			System.out.println("Usage: ShowFile filename");
			return;
		}

		// The following code uses a try-with-resources statement to open
		// a file and then automatically close it when the try block is left.
		try (FileInputStream fin = new FileInputStream(args[0])) {
			while ((i = fin.read()) != -1)
				System.out.print((char) i);
		}
		catch(FileNotFoundException e) {
			System.out.println("File not Found.");
		}
		catch (IOException e) {
			System.out.println("An I/O Error Ocurred.");
		}
	}
}