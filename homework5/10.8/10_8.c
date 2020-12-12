#include <stdio.h>

union integer
{
    char c;
    short s;
    int i;
    long b;
};


int main()
{
    union integer a, b, c, d;
    scanf("%c%d%d%ld", &a, &b, &c, &d);
    printf("%c%d%d%ld", a, b, c, d);
    
    return 0;
}