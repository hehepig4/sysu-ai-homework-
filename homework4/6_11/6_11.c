#include<stdio.h>

#define true 1
#define false 0
int a[10000];
/*void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}*/
void paopao(int n) {
	for (int i = 0; i < n-1; i++) {
		char trans = 0,temp=false;
		for (int j = 0; j < n-1 - i; j++) {
			if (a[i] > a[i+1]) temp=a[i],a[i]=a[i+1],a[i+1]=temp,trans=true;
		}
		if (!trans) break;
	}
}
int n;//对有n个数的从小到大排序
int main() {

	paopao(n);
}