#include<stdio.h>
#include<math.h>
float roundToInterger(float num) {
	return floor(num + 0.5);
}
float roundToTenths(float num) {
	return floor(num * 10 + .5) / 10;
}
float roundToHundreths(float num) {
	return floor(num * 100 + .5) / 100;
}
float roundToThousandths(float num) {
	return floor(num * 1000 + .5) / 1000;
}
float s;
int main() {
	while (scanf("%f", &s)) {
		printf("%f %.0f %.1f %.2f %.3f\n", s, roundToInterger(s), roundToTenths(s), roundToHundreths(s), roundToThousandths(s));
	}
}