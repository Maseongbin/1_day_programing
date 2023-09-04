#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	FILE* fp = NULL;
	int c;

	fopen_s(&fp, "text.txt", "wt");
	fputc('a', fp);
	fclose(fp);

	fopen_s(&fp, "text.txt", "rt");
	c = fgetc(fp);
	printf("%d: %c\n", c, c);
	fclose(fp);

	return 0;
}