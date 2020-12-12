#include <stdio.h>
#include <string.h>

char *mystrcpy1(char* s1, const char* s2)
{
    size_t len = strlen(s2);

    for(size_t i = 0; i < len; i++)
        s1[i] = s2[i];
    
    return s1;
}

char *mystrcpy2(char* s1, char* s2)
{
    char *temp = s1;

    while (*s2)
    {
        *(s1++) = *(s2++);
    }
    
    return temp;
}

char *mystrcat1(char* s1, const char* s2)
{
    size_t len1 = strlen(s1), len2 = strlen(s2);
    for(size_t i = len1; i <= len1 + len2; i++)
    {
        s1[i] = s2[i - len1];
    }

    return s1;
}

char *mystrcat2(char* s1, char* s2)
{
    char* temp = s1;
    s1 += strlen(s1);
    while (*s2)
    {
        *(s1++) = *(s2++);
    }
    *s1 = 0;    //字符串终止符

    return temp;
}

int main()
{
    char s1[100] = "12345", s2[100] = "67890", *s3;
    printf("%s\n%s\n", s1, s2);
    s3 = mystrcat2(s1, s2);
    printf("%s\n%s\n%s\n", s1, s2, s3);
    printf("%d\n%d\n%d\n", s1, s2, s3);

    return 0;
}