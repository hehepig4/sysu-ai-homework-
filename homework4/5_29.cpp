#include<iostream>
#include<cstdio>
using namespace std;
int a, b;
void swap(int& a, int& b) {
	if (a < b) {
		int c = a;
		a = b;
		b = c;
	}
}
int gcd(int a, int b) {
	while (a % b != 0) {
		swap(a, b);
		a = a % b;
	}
	return b;
}
int main() {
	scanf("%d%d", &a, &b);
	printf("%d", gcd(a, b));
}