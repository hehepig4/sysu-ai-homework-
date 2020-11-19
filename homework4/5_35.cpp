#include<iostream>
#include<cstdio>
using namespace std;
int n;
//unsigned long long f[100000];
unsigned long long feb(int n) {
	unsigned long long a=0,b=1;
	for (int i = 1; i < n-1; i++) {
		unsigned long long c = b;
		b = a + b;
		a = c;
	}
	return b;
}
int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("0");
		return 0;
	}
	printf("%lld", feb(n));
//maxÔ¼Îª12000×óÓÒ
}