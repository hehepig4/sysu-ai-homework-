#include<stdio.h>
int card[601][3]; //卡片编号，内容
int ren[4][5],a,b,c,n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d%d", &card[i][0], &card[i][1], &card[i][2]);
	for (int i = 0; i < n; i++) {
		ren[card[i][0]-1][card[i][1]-1] += card[i][2];
	}
	for (int i = 0; i < 4; i++) {
		int ans = 0;
		for (int j = 0; j < 5; j++) {
			ans += ren[i][j];
			printf("%d\t", ren[i][j]);
		}
		printf("%d\n", ans);
	}
	for (int i = 0; i < 5; i++) {
		int ans = 0;
		for (int j = 0; j < 4; j++) {
			ans += ren[j][i];
		}
		printf("%d\t", ans);
	}

}