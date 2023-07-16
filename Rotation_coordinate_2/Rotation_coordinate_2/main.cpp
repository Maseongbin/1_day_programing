#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double x_new, y_new;

void Rotation_Coordinates(double x, double y, double angle_degree) 
{ 
    double radian = angle_degree * M_PI / 180.0;  
     
    x_new = x * cos(radian) - y * sin(radian);   
    y_new = x * sin(radian) + y * cos(radian);   
}

void main()
{
    double x = 0;
    double y = 0;
    double angle_degree;
    

    printf("x��ǥ: ");
    scanf("%lf", &x);

    printf("y��ǥ: ");
    scanf("%lf", &y);

    printf("ȸ�� ����: ");
    scanf("%lf", &angle_degree);

    Rotation_Coordinates(x, y, angle_degree); 

    printf("��ȯ�� ��ǥ: (%.2lf, %.2lf)\n", x_new, y_new); 
}