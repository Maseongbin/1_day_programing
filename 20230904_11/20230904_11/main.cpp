#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	FILE* fp = NULL;
	
	char name[50], name2[50];
	int num, num2;
	double score, score2;

	printf("학생의 이름, 학번, 점수 입력: ");
	scanf_s("%s %d %lf", name, 50, &num, &score);

	fopen_s(&fp, "score.txt", "wt");
	fprintf(fp, "%s %d %f", name, num, score);
	fclose(fp);
	fopen_s(&fp, "score.txt", "rt");

	if (fp == NULL) 
	{
		fprintf(stderr, "파일 열기 오류\n");
		exit(1);
	}

	int c = fscanf_s(fp, "%s %d %lf", name2, 50, &num2, &score2);
	printf("파일로부터 입력받은 학생 정보(입력에 성공한 데이터 수 : %d)\n이름: %s\n학번: %d\n학점: %f\n", c, name2, num2, score2);

	fclose(fp);

	return 0;
}