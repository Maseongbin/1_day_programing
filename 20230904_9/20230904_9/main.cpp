#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
	FILE* fp = NULL;
	char buf1[100], buf2[100];

	printf("문장 입력: ");
	if (fgets(buf1, sizeof(buf1), stdin) == NULL) 
	{
		fprintf(stderr, "입력 오류\n");
		return 1;
	}


	fopen_s(&fp, "text.txt", "wt");
	fputs(buf1, fp);
	fclose(fp);

	fopen_s(&fp, "text.txt", "rt");
	if (fp == NULL) 
	{
		fprintf(stderr, "파일 열기 실패\n");
		exit(1);
	}

	char str[100];
	strcpy_s(str, 100, fgets(buf2, 100, fp));
	printf("%s 파일로부터 읽은 문자열 : %s\n", str, buf2);
	fclose(fp);

	return 0;
}