/* A version of CopyFile that uses try-with-resources.
   It demonstrates two resources (in this case files) being
   managed by a single try statement
*/

import java.io.*;

class CopyFileResources {
	public static void main(String[] args) throws IOException {
		
		// First, confirm that both files have been specified.
		if (args.length != 2) {
			System.out.println("Usage: CopyFile from to");
			return;
		}

		// Open and manage two files via the try statement.
		try (FileInputStream fin = new FileInputStream(args[0]);
			 FileOutputStream fout = new FileOutputStream(args[1])) {
			int i;
			while ((i = fin.read()) != -1)
				fout.write(i);
		}
		catch (IOException e) {
			System.out.println("I/O Error: " + e);
		}
	}
}