#include <stdio.h>
#include <string.h>

int main()
{
	char string[1000];
	int counter[100] = { 0 };
	int n = 0;
	printf("Enter the number of the line(must less than 20):");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", string);
		for (int k = 0; k < strlen(string); k++)
		{
			counter[string[k] - 'A']++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%c:%d\n", i + 'A', counter[i] + counter[i + 26 + 6]);
	}

	return 0;
}
