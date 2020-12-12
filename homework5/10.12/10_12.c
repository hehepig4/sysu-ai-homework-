#include <stdio.h>

unsigned int packCharacters(char a, char b, char c, char d)
{
    return (a << 24) + (b << 16) + (c << 8) + d;
}

int main()
{
    char a, b, c, d;
    scanf("%c%c%c%c", &a, &b, &c, &d);
    unsigned int temp = packCharacters(a, b, c, d);
    printf("%c%c%c%c\n%u", a, b, c, d, temp);

    return 0;
}