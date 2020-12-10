#include <stdio.h>

int main()
{
	char string[100000];
	size_t a;
	int counter = 0;
	a = fread(string, 1, 100000, stdin);

	for (int i = 0; i < a; i++)
	{
		if (string[i] == ' ' || string[i] == '\n')
		{
			counter++;
		}
	}

	printf("%d", counter);

	return 0;
}
