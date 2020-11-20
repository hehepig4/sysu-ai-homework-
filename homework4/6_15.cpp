/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;//可变数组 书上说visualc++用不了书上的可变数组 确实用不了 所以不用了
int x;
bool fx = false;
int main() {
	scanf("%d", &x);
	a.push_back(x);
	for (int i = 0; i < 19; i++) {
		scanf("%d", &x);
		for (vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter) { //遍历数组，可以自行实现�
			if (*iter == x) {
				fx = true;
				break;
			}
		}
		if (!fx) a.push_back(x);
		fx = false;
	}
	for (vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter) printf("%d ", *iter); //遍历数组，可以自行实现�
}*/
//To do:用c实现类似于vector的动态数组&空间最优化(时间效率qtm)    以及定长数组方案
//我们叫它 vectorFucker 吧w