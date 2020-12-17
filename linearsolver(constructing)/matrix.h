#ifndef _MATRIX_H_
#define _MATRIX_H_
#define NWR
#ifdef WR
#define ROW_SWAP(__,___) cout << "r" << __<< "<=>" << "r" <<___ << '\n';
#define ROW_MUIT(__,___) cout << "r" << __ << "*" << ___ << '\n';
#define ROW_DIVI(__,___) cout << "r" << __ << "/" << ___ << '\n';
#define ROW_CADD(__,___,____) cout << "r" << __ << "+" <<___<< "r" << ____<< '\n';
#define ROW_CSUB(__,___,____) cout << "r" << __ << "-" <<___<< "r" << ____ <<'\n';
#define ROW_ADD(__,___) cout << "r" << __ << "+" <<"r" << ___<< '\n';
#define ROW_SUB(__,___) cout << "r" << __ << "-" <<"r" << ___<<'\n';
#define PRT_NOW cout<<*this<<endl;
#define CROSS_SWAP(__,___) cout << "l" << __<< "<=>" << "l" <<___ << '\n';
#define CROSS_MUIT(__,___) cout << "l" << __ << "*" << ___ << '\n';
#define CROSSW_DIVI(__,___) cout << "l" << __ << "/" << ___ << '\n';
#define CROSS_CADD(__,___,____) cout << "l" << __ << "+" <<___<< "l" << ____<< '\n';
#define CROSS_CSUB(__,___,____) cout << "l" << __ << "-" <<___<< "l" << ____ <<'\n';
#define CROSS_ADD(__,___) cout << "l" << __ << "+" << "l" << ___<< '\n';
#define CROSS_SUB(__,___) cout << "l" << __ << "-" << "l" << ___ <<'\n';
#endif
#ifdef NWR
#define ROW_SWAP(__,___)
#define ROW_MUIT(__,___)
#define ROW_DIVI(__,___)
#define ROW_CADD(__,___,____)
#define ROW_CSUB(__,___,____)
#define ROW_ADD(__,___)
#define ROW_SUB(__,___)
#define PRT_NOW  
#define CROSS_SWAP(__,___)
#define CROSS_MUIT(__,___)
#define CROSS_DIVI(__,___)
#define CROSS_CADD(__,___,____)
#define CROSS_CSUB(__,___,____)
#define CROSS_ADD(__,___)
#define CROSS_SUB(__,___)
#endif
#include"libratio.h"
#include<vector>
#include<algorithm>
#include<time.h>
#include<cstdlib>
#define _INIT_MATRIX_VARS 
using namespace std;
class matrix { //[row][cross]
public:
//构造函数
	matrix()= default;								//维度方阵初始化
	template<typename T> matrix(T* ao ,int row,int cross);				//数组初始化
	matrix(int,int);										//维度初始化
	matrix(matrix a1, matrix a2);
	explicit matrix(int n);
public:
//运算符重载声明

public:
//运算符重载实现
	vector<ratio>& operator [] ( int i) {
		return _mat[i];
	}
public:
//运算
	int			rank();											//矩阵的秩
	matrix		inv();											//逆矩阵
	ratio		det();											//行列式
	void		rref();											//行阶梯型矩阵
	inline void resize();										//改变矩阵后重新计算大小
	matrix		transfer();										//转置矩阵 
	inline void row();											//重载行数（高）
	inline void cross();										//重载列数（宽）
	void		simplfied();									//行最简形矩阵
	void		Gauss_elimination();							//高斯约当消元法
	matrix      cross_vector(int);								//返回某一列列向量
	matrix      row_vector(int);								//返回某一行行向量
inline	void    cross_add(matrix a,ratio coe, int b);           //从第b列开始加矩阵（向量）a
inline	void    row_add(matrix a, ratio coe,int b);
inline	void    row_muti(int a,ratio b);
inline	void    cross_muti(int a, ratio b);
inline	void    row_divi(int a, ratio b);
inline	void    cross_divi(int a, ratio b);
inline	void    cross_swap(int a, int b);
inline	void    row_swap(int a, int b);
inline	void    row_sub(int a, int b);
inline	void    cross_sub(int a, int b);
inline	void    cross_add(int a, int b);
inline	void    row_add(int a ,int b);
inline	void    row_sub(int a,ratio coe, int b);
inline	void    cross_sub(int a, ratio coe, int b);
inline	void    cross_add(int a, ratio coe, int b);
inline	void    row_add(int a, ratio coe, int b);
public:
//变量储存
	int _row=0, _cross=0,_rank=0;
	bool _has_Gauss=false;
	ratio _det=0;
	vector<vector<ratio> > _mat;
	
};

//运算符声明
bool operator == (matrix a1, matrix a2);					//a1,a2等价
bool operator != (matrix a1, matrix a2);					//a1,a2不等价
matrix operator + ( matrix a1, matrix a2);
matrix operator - ( matrix a1, matrix a2);
matrix operator * ( matrix a1, matrix a2);					//矩阵乘法
matrix operator * (matrix a1, ratio con);					//数乘
matrix operator * (ratio con, matrix a1);
matrix operator / (matrix a1, ratio con);
bool operator >=(matrix a1, matrix a2);					//a1可以线性表示a2
bool operator <=(matrix a1, matrix a2);					//a1可由a2线性表示
ostream& operator<<(std::ostream& os, const matrix& r);		// <<matrix输出矩阵

//外部函数声明
matrix functions_solve(matrix coefficient, matrix constant);	//AX=B;解线性方程组
matrix eye(int level);											//n阶单位矩阵生成
matrix rand_matrix(int row, int cross, ratio sup, ratio inf);	//n阶随机矩阵生成
matrix matrix_function_solve(matrix coefficient, matrix target);//AX=B;解矩阵方程组
matrix Schmidt_orthogonalization(matrix);						//施密特正交化
matrix Schmidt_orthogonalization_unitform(matrix);              //再单位化
ratio inner_product(matrix, matrix);							//内积，列向量
//成员函数实现
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
		for (int i = now + 1; i <= _row; i++) 
			if ((abs(_mat[i][j]) > abs(_mat[k][j])&&_mat[i][j].num!=0)||(_mat[k][j].num==0&& _mat[i][j].num != 0)) k = i;
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
			row_swap(k, now);
			PRT_NOW
		}
		_det *= _mat[now][j];
		ratio coe= _mat[now][j];
		row_divi(now,coe);
		for (int i = now + 1; i <= _row; i++){
			ratio coe = _mat[i][j];
			row_sub(i,coe,now);
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
	matrix _ans(_row,_row);
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
		ratio coe = _mat[now][k];
		row_divi(now, coe);
		PRT_NOW
		if (_mat[now][k].num != 0) for (int j = 1; j < now; j++) {
			ratio coe = _mat[j][k];
			row_sub(j, coe, now);
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
	for (int i = 1; i <= _row; i++) for (int j = 1; j <= _cross; j++) {
		_tr._mat[j][i] = _mat[i][j];
	}
	return _tr;
}
matrix matrix::cross_vector(int a) {
	if (a > _row) return matrix(1, 1);
	matrix _p(_row, 1);
	for (int i = 1; i <= _row; i++) _p._mat[i][1] = _mat[i][a];
	return _p;
}
matrix matrix::row_vector(int a) {
	if (a > _cross) return matrix(1, 1);
	matrix _p(1, _cross);
	for (int i = 1; i <= _row; i++) _p._mat[1][i] = _mat[a][i];
	return _p;
}
inline void matrix::cross_add(matrix a,ratio coe,int b) {
	for (int i = 1; i <= a._cross; i++) {
		for (int j = 1; j <= _row; j++) _mat[j][i+b-1] += a[j][i]*coe;
	}
}
inline void matrix::row_add(matrix a,ratio coe, int b) {
	for (int i = 1; i <= _cross; i++) {
		for (int j = 1; j <= a._row; j++) _mat[j+b-1][i] += a[j][i]*coe;
	}
}
inline void matrix::row_muti(int a, ratio b) {
	for (int i = 1; i <= _cross; i++) _mat[a][i] *= b;
	ROW_MUIT(a, b)
}
inline void matrix::row_divi(int a, ratio b) {
	for (int i = 1; i <= _cross; i++) _mat[a][i] /= b;
	ROW_DIVI(a, b)
}
inline void matrix::row_swap(int a, int b) {
	swap(_mat[a], _mat[b]);
	ROW_SWAP(a, b)
}
inline void matrix::row_add(int a, int b) { // a+b
	for (int i = 1; i <= _cross; i++) _mat[a][i] += _mat[b][i];
	ROW_ADD(a, b)
}
inline void matrix::row_sub(int a, int b) { // a-b
	for (int i = 1; i <= _cross; i++) _mat[a][i] -= _mat[b][i];
	ROW_SUB(a, b)
}
inline void matrix::row_sub(int a, ratio coe, int b) { // a-b
	for (int i = 1; i <= _cross; i++) _mat[a][i] -= _mat[b][i] * coe;
	ROW_CSUB(a, coe, b)
}
inline void matrix::row_add(int a, ratio coe, int b) { // a-coe*b
	for (int i = 1; i <= _row; i++) _mat[a][i] -= _mat[b][i] * coe;
	ROW_CADD(a, coe, b)
}
inline void matrix::cross_muti(int a, ratio b) {
	for (int i = 1; i <= _row; i++) _mat[i][a] *= b;
	CROSS_MUIT(a, b)
}
inline void matrix::cross_divi(int a, ratio b) {
	for (int i = 1; i <= _row; i++) _mat[i][a] /= b;
	CROSS_DIVI(a, b)
}
inline void matrix::cross_swap(int a, int b) {
	for (int i = 1; i <= _row; i++) swap(_mat[i][a],_mat[i][b]);
	CROSS_SWAP(a, b)
}
inline void matrix::cross_add(int a, int b) { // a+b
	for (int i = 1; i <= _row; i++) _mat[i][a] += _mat[i][b];
	CROSS_ADD(a, b)
}
inline void matrix::cross_sub(int a, int b) { // a-b
	for (int i = 1; i <= _row; i++) _mat[i][a] -= _mat[i][b];
	CROSS_SUB(a, b)
}
inline void matrix::cross_add(int a, ratio coe, int b) { // a+coe*b
	for (int i = 1; i <= _row; i++) _mat[i][a] += _mat[i][b]*coe;
	CROSS_CADD(a,coe, b)
}
inline void matrix::cross_sub(int a, ratio coe, int b) { // a-coe*b
	for (int i = 1; i <= _row; i++) _mat[i][a] -= _mat[i][b]*coe;
	CROSS_CSUB(a,coe, b)
}
//运算符实现
matrix operator + (matrix a1, matrix a2) {
	matrix ls(a1._row,a1._cross);
	for (int i = 1; i <= a1._row; i++) for (int j = 1; j <= a1._cross; j++) {
		ls._mat[i][j] = a1[i][j] + a2[i][j];
	}
	return ls;
}
matrix operator - (matrix a1, matrix a2) {
	matrix ls(a1._row, a1._cross);
	for (int i = 1; i <= a1._row; i++) for (int j = 1; j <= a1._cross; j++) {
		ls._mat[i][j] = a1[i][j] - a2[i][j];
	}
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
//构造函数实现

matrix::matrix(int row,int cross) {
	vector<ratio> p;
	for (int i = 0; i <= _cross; i++) p.push_back(0);
	for (int i = 0; i <= _row; i++) _mat.push_back(p);
}
template<typename T> matrix::matrix(T* mat, int row, int cross)
:_cross(cross),_row(row){
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
	:_cross(a1._cross+a2._cross), _row(a1._row) {
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
matrix::matrix(int n)
	:_cross(n), _row(n) {
	_cross = _row = n;
	vector<ratio> p;
	for (int i = 0; i <= _cross; i++) p.push_back(0);
	for (int i = 0; i <= _row; i++) _mat.push_back(p);
}
//类外函数实现
ratio   inner_product(matrix a, matrix b) {
	if ((a._cross != 1 || b._cross != 1) || a._row != b._row) return 0;
	ratio ans=0;
	for (int i = 1; i <= a._row; i++) ans += a[i][1] * b[i][1];
	return ans;
}
matrix  eye(int n) {
	matrix e(n,n);
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
	if (!_none && _mmax[_mmax._row][_mmax._cross].num != 0) return matrix(1,1);
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
	return matrix(1,1);//施工中
}
matrix  Schmidt_orthogonalization(matrix _in) {
	matrix _ans(_in._row, _in._cross);
	_ans.cross_add(_in.cross_vector(1),1, 1);
	for (int i = 2; i <= _ans._cross; i++) {
		matrix _nec(_in._row,1);
		_nec = _in.cross_vector(i);
		for (int j = 1; j < i; j++) {
				ratio cs = inner_product(_ans.cross_vector(j), _in.cross_vector(i)) / inner_product(_ans.cross_vector(j), _ans.cross_vector(j));
				_nec = _nec - cs * _ans.cross_vector(j);
		}
	_ans.cross_add(_nec, 1,i);
	}
	return _ans;
}
matrix  Schmidt_orthogonalization_unitform(matrix _in) {
	matrix inn=Schmidt_orthogonalization(_in);
	return matrix(1, 1); //施工中
}
#endif



