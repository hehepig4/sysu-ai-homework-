#include<stdio.h>
int a, b;			
int power(int b, int e) {
	if (e > 1) return b*power(b, e - 1);
	return b;
}
int main() {
	scanf("%d%d", &a, &b);
	printf("%d", power(a, b));
}