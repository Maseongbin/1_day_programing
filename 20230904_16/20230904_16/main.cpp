#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX	100

struct  student 
{
	char name[20];        
	int kor, eng, mat; 
};

int read_file(struct student list[], int* n)  
{
	FILE* fp;
	int i = 0;

	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		printf("File read error...\n");

		return -1;
	}

	while (!feof(fp))
	{
		fscanf(fp, "%s %d %d %d",
			list[i].name, &list[i].kor, &list[i].eng, &list[i].mat);
		i++;
	}
	*n = i;
	fclose(fp);
}

void print(struct student list[], int n)
{
	int i, tot, ttot = 0;

	printf("\n�̸�     ���� ���� ����   ���\n");
	printf("--------------------------------\n");
	for (i = 0; i < n; i++)
	{
		tot = list[i].kor + list[i].eng + list[i].mat;
		ttot += tot;

		printf("%-10s %3d  %3d  %3d  %6.2f\n",
			list[i].name, list[i].kor, list[i].eng, list[i].mat,
			(float)tot / 3);
	}
	printf("--------------------------------\n");
	printf("��ü ��� : %.2f\n", (float)ttot / (3 * n));
}

int main()
{
	struct student list[MAX];
	int n = 0;
	int result = read_file(list, &n);

	if (result == -1)
	{
		// ���� ���� ���� ó��
		return 1; // ���и� ��Ÿ���� �ڵ�
	}

	print(list, n);

	return 0;
}