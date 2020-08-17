#include <stdio.h>
#include <string.h> //strlen()

// For sleep function
#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#endif

int main(int argc, char const *argv[])
{
	printf("FILENAME_MAX = %d\nFOPEN_MAX = %d", FILENAME_MAX, FOPEN_MAX);

printf("\n\n/////////////////////////////////////////////////////////////\n");
	printf("\nTMP_MAX = %d", TMP_MAX);
	char *ptr_name1 = tmpnam(NULL);

	char temp_s[L_tmpnam];
	char *ptr_name2 = tmpnam(temp_s);

	printf("\n\tchar *ptr_name1 = tmpnam(NULL);");
	printf("\n\t\tlength(ptr_name1) = %ld", strlen(ptr_name1));

	printf("\n\tchar temp_s[L_tmpnam];");
		printf("\n\t\tL_tmpnam = %d", L_tmpnam);
	printf("\n\tchar *ptr_name2 = tmpnam(temp_s);");
	printf("\n\t\tptr_name2 = %s", ptr_name2);
	printf("\n\t\ttemp_s = %s", temp_s);
	
printf("\n\n/////////////////////////////////////////////////////////////\n");
	
	//FILE *ptr_file = fopen("temp_output.txt", "w");
	//setvbuf(ptr_file, NULL, _IONBF, 50);
	//setbuf(ptr_file, NULL);
	//fputs("\nfirst line", ptr_file);
	//fputs("\nsecond line", ptr_file);
	//fclose(ptr_file);

	//setvbuf(stdout, NULL, _IONBF, 50);
	setbuf(stdout, NULL);
	fputs("\nfirst line", stdout);
	fputs("\nsecond line", stdout);
	//sleep(5);

printf("\n\n/////////////////////////////////////////////////////////////\n");

	int size;
	printf("Este print tem a seguinte quantidade de caracteres: %n", &size);
	printf("%d", size);

printf("\n\n/////////////////////////////////////////////////////////////\n");

	printf("\n");

	remove("temp_output.txt");
	rename("old_name.c", "new_name.c");
	return 0;
}
