#include<stdio.h>
using namespace std;
int n;
int isEven(int n) {
	return n % 2 == 1 ? 0 : 1;
}
int main() {
	while (scanf("%d", &n)) {
		printf("%d\n", isEven(n));
	}
}