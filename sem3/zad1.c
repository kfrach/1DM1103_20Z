#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    int n = argc -1;
    float s = 0;
    float x =0;
    float v[n];

    for (i=0; i<n; i++){
        v[i]=atof(argv[i+1]);
    }

    for (i=0; i<n;i++)
    {
        s= v[i]*v[i];
        x = v[i];
    }

    printf("Wartość %lf do kwadratu to %lf.\n",x,s);
}