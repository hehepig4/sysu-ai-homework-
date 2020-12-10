#include <stdio.h>
#include <string.h>

int main()
{
	char string[1000], sToFind[100];
	int n = 0, counter = 0;
	printf("Enter the number of the line(must less than 20):");
	scanf("%d", &n);
	printf("Enter the string you want to find:");
	scanf("%s", sToFind);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", string);
		if (strstr(string, sToFind) != NULL)
			counter++;
	}
	
	printf("%d", counter);

	return 0;
}
