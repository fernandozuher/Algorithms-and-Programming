/* Display a text file.
   To use this program, specify the name
   of the file you want to see.
   For example, to see a file called TEST.TXT,
   use the following command line.

   java	ShowFile TEST.TXT

   This variation wraps the code that opens and
   accesses the file within a single try block.
   The file is closed by the finally block.
*/

import java.io.*;

class ShowFileFinally3 {
	public static void main(String[] args) {
		int i;
		FileInputStream fin = null;

		// First, confirm that a filename has been specified.
		if (args.length != 1) {
			System.out.println("Usage: ShowFile filename");
			return;
		}

		// The following code opens a file, reads characters until EOF
		// is encountered, and then closes the file via a finally block.
		try {
			fin = new FileInputStream(args[0]);

			while ((i = fin.read()) != -1)
					System.out.print((char) i);
		}
		catch (IOException e) {
			System.out.println("I/O Error: " + e);
		}
		finally {
			// Close file in all cases.
			try {
				if (fin != null) fin.close();
			}
			catch (IOException e) {
				System.out.println("Error Closing File");
			}
		}
	}
}