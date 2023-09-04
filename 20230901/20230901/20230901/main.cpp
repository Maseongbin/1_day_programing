#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main()
{
	double k = 8.99 * pow(10, 9);
	double F;
	double q1;
	double q2;
	double r;

	printf("q1의 값을 입력하시오: ");
	scanf("%lf", &q1);

	printf("q2의 값을 입력하시오: ");
	scanf("%lf", &q2);

	printf("r의 값을 입력하시오: ");
	scanf("%lf", &r);

	F = k * (q1 * q2) / (r * r);

	printf("F = %.2lf N", F);
}