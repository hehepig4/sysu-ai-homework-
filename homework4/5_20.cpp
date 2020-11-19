#include<stdio.h>
using namespace std;
char x;
int n;
void matrix(int n, char fillCharacter) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", fillCharacter);
		}
		printf("\n");
	}
}
int main() {
	scanf("%d %c", &n, &x);
	matrix(n, x);
}