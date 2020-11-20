#include<stdio.h>
int n, ans;
void ptf(int i, int j) {
	printf("%d->%d\n", i, j);
	//ans++;
}
void hnt(int now, int f, int t, int l) { //当前要移动层数，起点，中点，临时堆放点�
	if (now > 2) {
		hnt(now - 1, f, l, t);
		ptf(f, t);
		hnt(now - 1, l, t, f);//汉诺塔问题是有固定策略的，思考一下，且有唯一最简方式，所需步骤次数2^n-1
	}
	else ptf(f, l), ptf(f, t), ptf(l, t);
}
int main() {
	scanf("%d", &n);
	hnt(n, 1, 3, 2);
	//printf("%d",ans);
}
