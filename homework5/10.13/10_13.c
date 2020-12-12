#include <stdio.h>

void unpackCharacters(char *a, char *b, char *c, char *d, unsigned int i)
{
    *a = (i & 4278190080) >> 24;
    *b = (i & 16711680) >> 16;
    *c = (i & 65280) >> 8;
    *d = i & 255;
}

int main()
{
    unsigned int temp;
    scanf("%u", &temp);
    char a, b, c, d;
    unpackCharacters(&a, &b, &c, &d, temp);
    printf("%c%c%c%c", a, b, c, d);

    return 0;
}