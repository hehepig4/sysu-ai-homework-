#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;//�ɱ����� ����˵visualc++�ò������ϵĿɱ����� ȷʵ�ò��� ���Բ�����
int x;
bool fx = false;
int main() {
	scanf("%d", &x);
	a.push_back(x);
	for (int i = 0; i < 19; i++) {
		scanf("%d", &x);
		for (vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter) { //�������飬��������ʵ��
			if (*iter == x) {
				fx = true;
				break;
			}
		}
		if (!fx) a.push_back(x);
		fx = false;
	}
	for (vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter) printf("%d ", *iter); //�������飬��������ʵ��
}