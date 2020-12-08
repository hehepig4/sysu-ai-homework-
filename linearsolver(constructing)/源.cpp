#include"matrix.h"
using namespace std;


int main() {
	int arr[3][4] = {
		{1,-5,2,-3},
		{5,3,6,-1},
		{2,4,2,1}
	};
	int tarr[3][1]{
		{11},
		{-1},
		{-6}
	};
	
	matrix m(arr[0], 3, 4);
	matrix n(tarr[0], 3, 1);
	cout << functions_solve(m, n);
}