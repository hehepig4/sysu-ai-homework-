#include<iostream>
#include<cstdio>
using namespace std;
int a[10000];
void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}
void paopao(int n) {
	for (int i = 0; i < n-1; i++) {
		bool trans = false;
		for (int j = 0; j < n-1 - i; j++) {
			if (a[i] > a[i+1]) swap(a[i], a[j]),trans=true;
		}
		if (!trans) break;
	}
}
int n;//对有n个数的从小到大排序
int main() {

	paopao(n);
}