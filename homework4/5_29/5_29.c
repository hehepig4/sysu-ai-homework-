#include<stdio.h>
/*int a, b;
void swap(int& a, int& b) {			//c中并没有这种用法
	if (a < b) {
		int c = a;					
		a = b;
		b = c;
	}
}*/
int gcd(int a, int b) {
	while (a % b != 0) {
		if (a < b) {
			int temp = a;					
			a = b;
			b = temp;
		}
		a = a % b;
	}
	return b;
}
int main() {
	int a,b;
	scanf("%d%d", &a, &b);
	printf("%d", gcd(a, b));
}