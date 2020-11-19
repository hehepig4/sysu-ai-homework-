#include<time.h>
#include<cstdlib>
#include<iostream>
#include<cstdio>
using namespace std;
int ans;
int main() {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 36000; i++) {
		int a1 = (rand() % 6) + 1;
		int a2 = (rand() % 6) + 1;
		if (a1 + a2 == 7) ans++;
	}
	if ((float)ans / 36000. < 1. / 6. + 1. / 20. && (float)ans / 36000. > 1. / 6. - 1. / 20.) printf("合理"); else printf("不合理");
}