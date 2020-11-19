#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;
int s[3][5] = {2,4,6,8,10,3,5,7,9,11,6,10,14,18,22};
int main() {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 3; i++)  {
		int r = (rand() % 5);
		printf("%d\n", s[i][r]);
	}
}
//虽说这道题好像不是程序题