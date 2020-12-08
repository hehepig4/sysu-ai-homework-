#ifndef _MATRIX_H_
#define _MATRIX_H_
#define NWR
#ifdef WR
#define ROW_SWAP(__,___) cout << "r" << __<< "<=>" << "r" <<___ << '\n';
#define ROW_MUIT(__,___) cout << "r" << __ << "*" << ___ << '\n';
#define ROW_DIVI(__,___) cout << "r" << __ << "/" << ___ << '\n';
#define ROW_ADD(__,___,____) cout << "r" << __ << "+" <<___<< "r" << ____<< '\n';
#define ROW_SUB(__,___,____) cout << "r" << __ << "-" <<___<< "r" << ____ <<'\n';
#define PRT_NOW cout<<*this<<endl;
#define CROSS_SWAP(__,___) cout << "l" << __<< "<=>" << "l" <<___ << '\n';
#define CROSS_MUIT(__,___) cout << "l" << __ << "*" << ___ << '\n';
#define CROSSW_DIVI(__,___) cout << "l" << __ << "/" << ___ << '\n';
#define CROSS_ADD(__,___,____) cout << "l" << __ << "+" <<___<< "l" << ____<< '\n';
#define CROSS_SUB(__,___,____) cout << "l" << __ << "-" <<___<< "l" << ____ <<'\n';
#endif
#ifdef NWR
#define ROW_SWAP(__,___)
#define ROW_MUIT(__,___)
#define ROW_DIVI(__,___)
#define ROW_ADD(__,___,____)
#define ROW_SUB(__,___,____)
#define PRT_NOW  
#define CROSS_SWAP(__,___)
#define CROSS_MUIT(__,___)
#define CROSS_DIVI(__,___)
#define CROSS_ADD(__,___,____)
#define CROSS_SUB(__,___,____)
#endif
#include"libratio.h"
//#include"_VEC.h"
#include<vector>
#include<algorithm>
#include<time.h>
#include<cstdlib>
#define _INIT_MATRIX_VARS 
using namespace std;
class matrix { //[row][cross]
public:
//���캯��
	matrix()= default;
	matrix(int a);											//ά�ȷ����ʼ��
	template<typename T> matrix(T* ao ,int row,int cross);				//�����ʼ��
	matrix(int,int);										//ά�ȳ�ʼ��
	matrix(matrix a1, matrix a2);
public:
//�������������

public:
//���������ʵ��
	vector<ratio>& operator [] ( int i) {
		return _mat[i];
	}
public:
//����
	int			rank();											//�������
	matrix		inv();											//�����
	ratio		det();											//����ʽ
	void		rref();											//�н����;���
	inline void resize();										//�ı��������¼����С
	matrix		transfer();										//ת�þ��� 
	inline void row();											//�����������ߣ�
	inline void cross();										//������������
	void		simplfied();									//������ξ���
	void		Gauss_elimination();							//��˹Լ����Ԫ��
public:
//��������
	int _row, _cross,_rank;
	bool _has_Gauss;
	ratio _det;
	vector<vector<ratio> > _mat;
	
};

//���������
bool operator == (matrix a1, matrix a2);					//a1,a2�ȼ�
bool operator != (matrix a1, matrix a2);					//a1,a2���ȼ�
matrix operator + ( matrix a1, matrix a2);
matrix operator - ( matrix a1, matrix a2);
matrix operator * ( matrix a1, matrix a2);					//����˷�
matrix operator * (matrix a1, ratio con);					//����
matrix operator * (ratio con, matrix a1);
matrix operator / (matrix a1, ratio con);
bool operator >=(matrix a1, matrix a2);					//a1�������Ա�ʾa2
bool operator <=(matrix a1, matrix a2);					//a1����a2���Ա�ʾ
ostream& operator<<(std::ostream& os, const matrix& r);		// <<matrix�������

//�ⲿ��������
matrix functions_solve(matrix coefficient, matrix constant);	//AX=B;�����Է�����
matrix eye(int level);											//n�׵�λ��������
matrix rand_matrix(int row, int cross, ratio sup, ratio inf);	//n�������������
matrix matrix_function_solve(matrix coefficient, matrix target);//AX=B;����󷽳���

//��Ա����ʵ��
ratio  matrix::det() {
	Gauss_elimination();
	if (_row == _cross) {
		for (int i = 1; i <= _row; i++) {
			_det *= _mat[i][i];
		}
		return _det;
	}
	return _det;
}
void   matrix::Gauss_elimination() {
	_has_Gauss = true;
	_det = makeRatio(1,1,false);
	int now = 1;
	for (int j = 1; j <= _cross;j++) {
		int k = now;
		for (int i = now + 1; i <= _row; i++) if ((abs(_mat[i][j]) > abs(_mat[k][j])&&_mat[i][j].num!=0)||(_mat[k][j].num==0&& _mat[i][j].num != 0)) k = i;
		if (_mat[k][j].num == 0) {
			j++;
			if (j == _cross) {
				_rank = now;
				return;
			}
			continue;
		}
		if (j != k) {
			_det = -_det;
			swap(_mat[k], _mat[now]);
			ROW_SWAP(k, now)
			PRT_NOW
		}
		_det *= _mat[now][j];
		ROW_MUIT(now, ratio(_mat[now][j].den,_mat[now][j].num,_mat[now][j].negative));
		for (int i = _cross; i >= now; i--) _mat[now][i] /= _mat[now][j];
		for (int i = now + 1; i <= _row; i++){
			ROW_SUB(i, _mat[i][j], now)
			for (int h = _cross; h >= j; h--) {
				_mat[i][h] -= _mat[i][j] * _mat[now][h];
			}
		}
		PRT_NOW
		if (now >= _row) {
			_rank = now;
			return;
		}
		_rank = now;
		now++;
	}
}
inline void   matrix::row() {
	_row = _mat.size()-1;
}
inline void   matrix::cross() {
	_cross = _mat[1].size() - 1;
}
int    matrix::rank() {
	if (!_has_Gauss) Gauss_elimination();
	return _rank;
}
inline void   matrix::resize() {
	row(); cross();
}
matrix matrix::inv() {
	matrix _mmax(*this, eye(_row));
	_mmax.simplfied();
	//cout << _mmax;
	matrix _ans(_row);
	for (int i = 1; i <= _row; i++) {
		for (int j = _cross + 1; j <= 2 * _cross; j++) _ans._mat[i][j - _cross] = _mmax[i][j];
	}
	_ans.resize();
	return _ans;
}
void   matrix::simplfied() {
	if (!_has_Gauss) Gauss_elimination();
	int now = _rank;
	while(now!=0) {
		int k = 1;
		for (int i = 1; i <= _cross; i++) if (_mat[now][i].num != 0) {
			k = i;
			break;
		}
		ROW_DIVI(now, _mat[now][k])
		if (_mat[now][k].num != 0) for (int j = _cross; j >= k; j--) _mat[now][j] /= _mat[now][k];
		PRT_NOW
		if (_mat[now][k].num != 0) for (int j = 1; j < now; j++) {
			ROW_SUB(j, _mat[j][k], now);
			for (int h = _cross; h >= k; h--) _mat[j][h] -= _mat[now][h] * _mat[j][k];
		}
		now--;
	}
	return;
} 
void   matrix::rref() {
	if (!_has_Gauss) Gauss_elimination();
	return;
}
matrix matrix::transfer() {
	matrix _tr(_cross,_row);
	for (int i = 0; i <= _row; i++) for (int j = 0; j <= _cross; j++) {
		_tr._mat[j][i] = _tr._mat[i][j];
	}
	return _tr;
}

//�����ʵ��
matrix operator + (matrix a1, matrix a2) {
	matrix ls(a1._row);
	ls._row = a1._row; ls._cross = a1._cross; ls._mat.clear();
	for (int i = 0; i <= ls._row; i++) for (int j = 0; j <= ls._cross; j++) ls._mat[i].push_back(a1._mat[i][j] + a2._mat[i][j]);
	return ls;
}
matrix operator - (matrix a1, matrix a2) {
	matrix ls(a1._row);
	ls._row = a1._row; ls._cross = a1._cross; ls._mat.clear();
	for (int i = 0; i <= ls._row; i++) for (int j = 0; j <= ls._cross; j++) ls._mat[i].push_back(a1._mat[i][j] - a2._mat[i][j]);
	return ls;
}
matrix operator * (matrix a1, matrix a2) {
	matrix ls(a1._row, a2._cross);
	for (int i = 1; i <= ls._row; i++) {
		for (int j = 1; j <= ls._cross; j++) {
			for (int h = 1; h <= a1._cross; h++) ls._mat[i][j] += a1[i][h] * a2[h][j];
		}
	}
	return ls;
}
ostream& operator<<(ostream& os, matrix const& matr){
	for (int i = 1; i <= matr._row; i++) {
		for (int j = 1; j <= matr._cross; j++) {
			os << matr._mat[i][j]<<' ';
		}
		os << '\n';
	}
	return os<<endl;
}
bool operator == (matrix a1, matrix a2) {
	if (a1._row != a2._row) return false;
	matrix a12(a1, a2);
	matrix a1t = a1, a2t = a2;
	a1t.Gauss_elimination(); a2t.Gauss_elimination(); a12.Gauss_elimination();
	if (a1t._rank == a2t._rank && a1t._rank == a12._rank) return true;
	else return false;
}
bool operator !=(matrix a1, matrix a2) {
	return !(a1 == a2);
}
bool operator >=(matrix a1, matrix a2) {
	if (a1._row != a2._row) return false;
	matrix a12(a1, a2);
	matrix a1t = a1;
	a1t.Gauss_elimination(); a12.Gauss_elimination();
	if (a1t._rank == a12._rank) return true;
	else return false;
}
bool operator <=(matrix a1, matrix a2) {
	return !(a2 >= a1);
}
matrix operator * (matrix a1, ratio con) {
	matrix a2 = a1;
	for (int i = 1; i <= a2._row; i++) for (int j = 1; j <= a2._cross; j++) {
		a2._mat[i][j] *= con;
	}
	return a2;
}
matrix operator * (ratio con, matrix a1) {
	return a1 * con;
}
matrix operator / (matrix a1, ratio con) {
	ratio con2 = con;
	con2.makeItselfreciprocal();
	return a1 * con2;
}
//���캯��ʵ��
matrix::matrix(int _n)
	:_row(_n),_cross(_n), _det(0), _rank(0), _has_Gauss(false) {
	vector<ratio> p;
	for (int i = 0; i <= _n; i++) p.push_back(0);
	for (int i = 0; i <= _n; i++) _mat.push_back(p);
}
matrix::matrix(int row,int cross) 
	: _row(row),_cross(cross), _det(0),_rank(0),_has_Gauss(false) {
	vector<ratio> p;
	for (int i = 0; i <= _cross; i++) p.push_back(0);
	for (int i = 0; i <= _row; i++) _mat.push_back(p);
}
template<typename T> matrix::matrix(T* mat, int row, int cross)
	:_row(row),_cross(cross), _det(0),_has_Gauss(false),_rank(-1) {
	vector<ratio> a;
	for (int j = 0; j <= cross; j++) a.push_back(0);
	_mat.push_back(a);
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < cross; j++) {
			ratio _ra(mat[i*_cross+j]);
			a[j+1] = _ra;
		}
		_mat.push_back(a);
	}
}
matrix::matrix(matrix a1,matrix a2) 
	:_cross(a1._cross+a2._cross),_row(a1._row), _det(0), _rank(0), _has_Gauss(false) {
	if (a1._row == a2._row) {
		vector<ratio> p;
		for (int i = 0; i <= _cross; i++) p.push_back(0);
		for (int i = 0; i <= _row; i++) _mat.push_back(p);
		for (int i = 1; i <= _row; i++) {
			for (int j = 1; j <= a1._cross; j++) _mat[i][j] = a1[i][j];
			for (int j = a1._cross + 1; j <= a1._cross + a2._cross; j++) _mat[i][j] = a2[i][j - a1._cross];
		}
	}
}
//���⺯��ʵ��
matrix  eye(int n) {
	matrix e(n);
	for (int i = 1; i <= n; i++) e._mat[i][i] = 1;
	return e;
}
matrix  functions_solve(matrix coe, matrix tar) {
	matrix _mmax(coe, tar);
	matrix _xs = coe;
	bool _none = false;
	_mmax.simplfied();
	for (int i = 1; i < _mmax._cross; i++) if (_mmax[_mmax._row][i].num != 0) {
		_none = true;
	}
	if (!_none && _mmax[_mmax._row][_mmax._cross].num != 0) return matrix(1);
	matrix _ans(coe._cross, coe._cross - _mmax._rank + 1);
	for (int i = _mmax._rank + 1; i <= _mmax._cross; i++) {
		if (i!=_mmax._cross)_ans._mat[i][i-_mmax._rank] = 1;
		for (int j = 1; j <= _mmax._rank; j++)
			_ans._mat[j][i - _mmax._rank] = ((i - _mmax._rank) != _ans._cross) ? -_mmax[j][i] : _mmax[j][i];
	}
	return _ans;
}
matrix  rand_matrix(int row, int cross, ratio sup, ratio inf) {
	srand((unsigned)time(NULL));
	matrix _ans(row, cross);
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= cross; j++) {
			_ans._mat[i][j].num=((ratio)(rand() % (inf.num - sup.num),2)+sup);
		}
	} 
	return _ans;
} 
matrix  matrix_function_solve(matrix coe, matrix tar) {
	return matrix(1);//ʩ����
}
#endif



