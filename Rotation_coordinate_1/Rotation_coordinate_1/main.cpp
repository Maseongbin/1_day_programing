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

    printf("x좌표: ");
    scanf("%lf", &x);

    printf("y좌표: ");
    scanf("%lf", &y);

    printf("회전 각도: ");
    scanf("%lf", &a);

    rad = a * M_PI / 180.0;

    new_X = x * cos(rad) - y * sin(rad);
    new_Y = x * sin(rad) + y * cos(rad);


    printf("변환된 좌표: (%.2lf, %.2lf)\n", new_X, new_Y);
}
