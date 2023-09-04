#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int year = 2021;
    int old = 21;
    FILE* fp;
    fp = fopen("Sunday.txt", "w");
    fprintf(fp, "This year is %d\nMy old is: %d", year, old);
    fclose(fp);
}