#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

/*
struct student
{
	char name[20];
	int age;
	double grade[3];
};

int main()
{
	struct student person;

	strcpy(person.name, "MA SEONG BIN");
	person.age = 20;
	person.grade[0] = 90;
	person.grade[1] = 85;
	person.grade[2] = 77;

	printf("�л� �̸�: %s\n", person.name);
	printf("�л� ����: %d\n", person.age);
	printf("�л� ����(����): %.2lf\n", person.grade[0]);
	printf("�л� ����(����): %.2lf\n", person.grade[1]);
	printf("�л� ����(����): %.2lf\n", person.grade[2]);
}
*/



typedef struct
{
	char title[30];
	char author[30];
	int price;
}  TEXTBOOK;

int main(void)
{
	TEXTBOOK my_book = { "HTML�� CSS", "ȫ�浿", 28000 };
	TEXTBOOK java_book = {"Java language", "��浿" ,30000};

	printf("ù ��° å�� ������ %s�̰�, ���ڴ� %s�̸�, ������ %d���Դϴ�.\n",
	my_book.title, my_book.author, my_book.price);

	printf("�� ��° å�� ������ %s�̰�, ���ڴ� %s�̸�, ������ %d���Դϴ�.\n",
	java_book.title, java_book.author, java_book.price);

	return 0;
}

