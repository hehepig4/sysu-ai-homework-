#include<stdio.h>
int n;
int p[11],have=0;
char s[];
int main() {
	printf("Please type 1 for \"first class\"\nPlease type 2 for \"economy\"");
	scanf("%d", &n);
	if (n == 1) {
		for (int i = 1; i <= 5; i++) if (p[i] == 0) have = i;
		if (have != 0) printf("your class: first class \n your seat: %d", have); else {
			if (have == 0) printf("Oops,no seat,do you want a economy seat?(yes/no)");
			scanf("%s", &s);
			if (s == "yes") {
				for (int i = 6; i <= 10; i++) if (p[i] == 0) have = i;
				printf("your class: economy \n your seat: %d", have);
			}
			else printf("Next flight leaves in 3 hours");
		}
		have = 0;
	}
	else if (n == 2) {
		for (int i = 6; i <= 10; i++) if (p[i] == 0) have = i;
		if (have != 0) printf("your class: economy \n your seat: %d", have); else {
			if (have == 0) printf("Oops,no seat,do you want a first class seat?(yes/no)");
			scanf("%s", &s);
			if (s == "yes") {
				for (int i = 1; i <= 5; i++) if (p[i] == 0) have = i;
				printf("your class: first class \n your seat: %d", have);
			}
			else printf("Next flight leaves in 3 hours");
		}
		have = 0;
	}
}