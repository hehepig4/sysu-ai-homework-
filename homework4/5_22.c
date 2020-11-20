//(a) a / b
//(b) a % b
#include <stdio.h>

void separate(int input)
{
	int i = 10;
	for (; input / i > 10; i *= 10)
		;
	while (i)
	{
		printf("%d   ", input / i);
		input %= i, i /= 10;
	}
}
/*
int main()
{
	int input = 0;
	scanf("%d", &input);
	separate(input);     //usage
	return 0;
}*/