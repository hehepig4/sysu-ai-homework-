int binarySearch(int a[],int l,int r,int key) {
	if (key == a[l]) return l;
	if (key == a[r]) return r;
	if (l == r) return -1;
	binarySearch(a, l, (l + r) / 2, key);
	binarySearch(a, (l + r) / 2, r, key);
}