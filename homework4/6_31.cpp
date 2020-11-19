//循环实现，看不太出有递归的必要
//string类型可以近似看为char[]
#include<string>
#include<stdio.h>
using namespace std;
string s;
int isornot(string ss) {
	for (int i = 0; i < ss.length(); i++) {
		if (ss[i] != ss[ss.length() - 1 - i]) return 0;
	}
	return 1;
}
int main() {
	scanf("%s", &s[0]);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') s.erase(s.begin()+i, s.begin()+i+1);//移除空格
	}

}