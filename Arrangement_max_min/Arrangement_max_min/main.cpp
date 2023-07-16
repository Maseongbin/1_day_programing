#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 5

void main()
{
    int arr[SIZE];
    int max;
    int min;

    printf("¹è¿­ÀÇ °ª: \n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    max = arr[0]; 
    min = arr[0]; 

    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("\n");
    printf("ÃÖ´ñ°ª: %d\n", max);
    printf("ÃÖ¼Ú°ª: %d\n", min);
}