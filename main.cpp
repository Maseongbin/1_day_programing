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

	printf("학생 이름: %s\n", person.name);
	printf("학생 나이: %d\n", person.age);
	printf("학생 성적(국어): %.2lf\n", person.grade[0]);
	printf("학생 성적(수학): %.2lf\n", person.grade[1]);
	printf("학생 성적(영어): %.2lf\n", person.grade[2]);
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
	TEXTBOOK my_book = { "HTML과 CSS", "홍길동", 28000 };
	TEXTBOOK java_book = {"Java language", "고길동" ,30000};

	printf("첫 번째 책의 제목은 %s이고, 저자는 %s이며, 가격은 %d원입니다.\n",
	my_book.title, my_book.author, my_book.price);

	printf("두 번째 책의 제목은 %s이고, 저자는 %s이며, 가격은 %d원입니다.\n",
	java_book.title, java_book.author, java_book.price);

	return 0;
}

