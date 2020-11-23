#include<math.h>
#include<stdio.h>
int yz(int n) {
	int ans = 0;
	for (int i = 1; i <= (int)sqrt(n); i++) {
		if (n % i == 0) ans += i + n / i;
	        if (n % i == 0 && i == n / i) ans -= i; //特判完全平方数
	}
	return ans - n;
}
int main() {
	for (int i = 2; i <= 1000; i++) {
		if (i == yz(i)) printf("%d ", i);
	}
}
