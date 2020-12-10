#include <stdio.h>
#include <string.h>

int main()
{
	char s[100], sToSearch[100], *searchPtr;
	scanf("%s%s", s, sToSearch);
	searchPtr = strstr(s, sToSearch);
	puts(searchPtr);	//和printf基本一样
	searchPtr = strstr(searchPtr + 1, sToSearch);
	puts(searchPtr);

	return 0;
}