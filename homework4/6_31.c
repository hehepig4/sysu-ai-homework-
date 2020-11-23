#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ChToIgnore[] = "~!@#$^&%*()_+`-=[]\\;',./{}|:\"<>? ";

int testPalindrome(char s[])
{
    int len = strlen(s);
    char *beg = s, *end = s + len - 1;

    while(beg < end)
    {
        if(strchr(ChToIgnore, *beg))
        {
            beg++;
            continue;
        }

        if(strchr(ChToIgnore, *end))
        {
            end--;
            continue;
        }

        if(*beg != *end)
            return 0;

        beg++;
        end--;
    }

    return 1;
}

int main(void)
{
    char s[1000];
    gets(s);

    if(testPalindrome(s))
        printf("%s is a palindrome!", s);
    else
    {
        printf("%s is not a palindrome!", s);
    }

    return 0;
}
