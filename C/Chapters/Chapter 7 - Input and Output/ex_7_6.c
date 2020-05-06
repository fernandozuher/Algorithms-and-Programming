/*
Author: Fernando Zuher
Place: Brazil
Date: 6 May 2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 7 - Input and Output
*/

/*
Exercise 7-6. Write a program to compare two files, printing the first line
where they differ.
*/

#include <stdio.h>
#include <string.h> // strchr(), strcmp()

char* compare_files(char *file1_name, char *file2_name, int *lines);

int main(int argc, char const *argv[])
{	
	int line;
	char file1_name[] = "file1.txt";
	char file2_name[] = "file2.txt";
	char *flag = compare_files(file1_name, file2_name, &line);

	if (flag) {
		if (strcmp(flag, "equal") == 0)
			printf("The files are equal. Total lines = %d.\n", line);
		else {
			printf("At line %d the files are different:", line);
			printf("\n%s\n", flag);
		}
	}
	else // else NULL, the files couldn't be opened.
		printf("Error opening files.\n");

	return 0;
}

#include <stdlib.h> // malloc()
#define SIZE_LINE_MAX 300

char* compare_files(char *file1_name, char *file2_name, int *lines) {

	FILE *ptr_f1, *ptr_f2;	
	if ((ptr_f1 = fopen(file1_name, "r")) && (ptr_f2 = fopen(file2_name, "r"))) {

		char *temp1, *temp2;

		// This initialization is important in the case when both files are empty.
		// Thus they can be compared correctly as equal.
		char string1[SIZE_LINE_MAX] = "", string2[SIZE_LINE_MAX] = "";

		int flag = 1;
		*lines = 0;

		do {
			temp1 = fgets(string1, SIZE_LINE_MAX, ptr_f1);
			temp2 = fgets(string2, SIZE_LINE_MAX, ptr_f2);
			(*lines)++;

			// Remove '\n' in order not to "disturb" the strcmp()
			if (string1[strlen(string1) - 1] == '\n')
				string1[strlen(string1) - 1] = '\0';

			if (string2[strlen(string2) - 1] == '\n')
				string2[strlen(string2) - 1] = '\0';

			// != 0 when both strings are different
			if (strcmp(string1, string2)) {

				// To avoid stating same last lines as equal
				if(temp1 == NULL && temp2 != NULL)
					strcpy(string1, "empty (End of File)");
				else if(temp2 == NULL && temp1 != NULL)
					strcpy(string2, "empty (End of File)");

				// +6 because:
					// f1_name: ---> ": " = +2 characters
					// '\n' (after string1) = +1 character
					// f2_name: ---> ": " = +2 characters
					// '\0' (after string2) = +1 character
				int size = strlen(file1_name) + strlen(string1) +
							strlen(file2_name) + strlen(string2) + 6;
				
				char *temp = (char *) malloc(sizeof(char) * size);
				strcpy(temp, file1_name);
				strcat(temp, ": ");
				strcat(temp, string1);
				strcat(temp, "\n");
				strcat(temp, file2_name);
				strcat(temp, ": ");
				strcat(temp, string2);
				return temp;
			}
			
		// if both files are equal, EOF is reached...
		} while (temp1 != NULL && temp2 != NULL);

		(*lines)--;
		return "equal";
	}
	else {
		*lines = -1;
		return NULL;
	}
}