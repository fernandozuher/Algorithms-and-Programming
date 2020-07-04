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

class ShowFileFinally {
	public static void main(String[] args) {
		int i;
		FileInputStream fin = null;

		// First, confirm that a filename has been specified.
		if (args.length != 1) {
			System.out.println("Usage: ShowFile filename");
			return;
		}

		try {
			// Attempt to open the file.
			try {
				fin = new FileInputStream(args[0]);
			}
			catch (FileNotFoundException e) {
				System.out.println("Cannot Open File");
				return;
			}

			// At this point, the file is open and can be read.
			// The following reads characters until EOF is encountered.
			try {
				while ((i = fin.read()) != -1)
					System.out.print((char) i);
			}
			catch (IOException e) {
				System.out.println("Error Reading File");
			}
		}
		finally {
			// Close the file.
			try {
				if (fin != null) fin.close();
			}
			catch (IOException e) {
				System.out.println("Error Closing File");
			}
		}
	}
}