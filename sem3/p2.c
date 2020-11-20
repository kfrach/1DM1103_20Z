#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    char n[100];

    int i;

    char n2[] = "Wielki i dlugi napis.";
    char tab[10][10];
    strcpy(n,"Ala");
    printf("%s",n);

    for (i=0;i<3;i++)
    {
        printf("[%d] %c\n",i ,n[i]);
    }
    printf("Hello World\n");
    return 0;
}