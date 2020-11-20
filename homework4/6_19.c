#include<time.h>
#include<stdlib.h>
#include<stdio.h>
int ans;
int main() {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 36000; i++) {
		int a1 = (rand() % 6) + 1;
		int a2 = (rand() % 6) + 1;
		if (a1 + a2 == 7) ans++;
	}
	if ((float)ans / 36000. < 1. / 6. + 1. / 20. && (float)ans / 36000. > 1. / 6. - 1. / 20.) printf("����"); else printf("������");
}