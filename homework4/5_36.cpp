#include<iostream>
#include<cstdio>
using namespace std;
int a[3][65], n, ans;
void ptf(int i, int j) {
	printf("%d->%d\n", i, j);
	//ans++;
}
void hnt(int now, int f, int t, int l) {
	if (now > 2) {
		hnt(now - 1, f, l, t);
		ptf(f, t);
		hnt(now - 1, l, t, f);
	}
	else ptf(f, l), ptf(f, t), ptf(l, t);
}
int main() {
	scanf("%d", &n);
	hnt(n, 1, 3, 2);
	//printf("%d",ans);
}