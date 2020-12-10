#include <stdio.h>
#define PI 3.1415926536

void C(double r)
{
	printf("%lf", 2 * r * PI);
}

void S(double r)
{
	printf("%lf", r * r * PI);
}

void V(double r)
{
	printf("%lf", 3 * r * r * r * PI / 4);
}

const void (*fPtr[3])(double) = { C, S, V };

int main()
{
	int temp;
	double r;
	printf("Enter r to output 0,C 1,S 2,V\n");
	scanf("%lf%d", &r, &temp);
	fPtr[temp](r);
}