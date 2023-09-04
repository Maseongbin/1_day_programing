#include <stdio.h>

int main(void) 
{
	FILE* fp;
	char buffer[] = "hello";

	fopen_s(&fp, "text.txt", "wt");
	fputs(buffer, fp);
	fclose(fp);
	fopen_s(&fp, "text.txt", "rt");

	fseek(fp, 1, SEEK_SET); 
	printf("%c\n", fgetc(fp));

	fseek(fp, -1, SEEK_END); 
	printf("%c\n", fgetc(fp));

	fclose(fp);

	return 0;
}