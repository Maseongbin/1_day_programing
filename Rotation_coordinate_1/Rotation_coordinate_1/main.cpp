#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

void main() 
{
    double x = 0, y = 0;
    double a;  
    double rad;  
    double new_X, new_Y; 

    printf("x��ǥ: ");
    scanf("%lf", &x);

    printf("y��ǥ: ");
    scanf("%lf", &y);

    printf("ȸ�� ����: ");
    scanf("%lf", &a);

    rad = a * M_PI / 180.0;

    new_X = x * cos(rad) - y * sin(rad);
    new_Y = x * sin(rad) + y * cos(rad);


    printf("��ȯ�� ��ǥ: (%.2lf, %.2lf)\n", new_X, new_Y);
}
