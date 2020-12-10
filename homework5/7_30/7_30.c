#include<stdio.h>
#define PI 3.141592653589793238462

void c(double r)
{
    printf("c of %lf is %lf",r,2*r*PI);  
}

void s(double r)
{
    printf("s of %lf is %lf",r,r*r*PI);
}

void v(double r)
{
    printf("v of %lf is %lf",r,r*r*r*4/3*PI);
}

int main()
{
    void (*pf[3])(double)={c,s,v};
    puts("1.c\n2.s\n3.v");
    int num=0;
    scanf("%d",&num);
    puts("please input r");
    double r=0;
    scanf("%lf",&r);
    pf[num-1](r);
}