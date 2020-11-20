int recursiveMinimum(int a[], int n) {
	int min = 2147483647;
	for (int i = 0; i < n; i++) min = min > a[i] ? a[i] : min;
	return min;
}