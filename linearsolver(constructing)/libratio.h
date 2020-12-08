#ifndef _LIBRATIO_H_
#define _LIBRATIO_H_ 
#define JQD 3
#include <iostream>
#include <cstdio>
#include<fstream>
unsigned long long gcd(unsigned long long x,unsigned long long y)
{
	unsigned long long factor = 0;   //计数器
	unsigned long long temp;

	//大数赋给x，小数赋给y
	if (x < y) {
		temp = x;
		x = y;
		y = temp;
	}
	if (0 == y) {
		return 0;
	}
	while (x != y) {
		if (x & 0x1) {
			if (y & 0x1) {   //x,y都为奇数
				y = (x - y) >> 1;
				x -= y;
			}
			else {    // x为奇数，y为偶数
				y >>= 1;
			}
		}
		else {
			if (y & 0x1) {   // x为偶数，y为奇数
				x >>= 1;
				if (x < y) {
					temp = x;
					x = y;
					y = temp;
				}
			}
			else {   //x,y均为偶数
				x >>= 1;
				y >>= 1;
				++factor;
			}
		}
	}
	return (x << factor);
}
struct ratio
{
	unsigned long long num = 0;
	unsigned long long den = 1;
	bool negative = false;
	ratio(double);
	ratio() = default;
	ratio(int);
	ratio(long long num1);
	ratio(long long num1, long long den1);
	ratio(unsigned long long num1, unsigned long long den1, bool isNegative);
	ratio(double a, int i);
	ratio &read(unsigned long long num1, unsigned long long den1, bool isNegative);
	ratio &print();
	ratio &simplify();
	ratio &makeItselfreciprocal();
	ratio reciprocal();

	operator long double() {return (negative ? -1 : 1) * (long double)num / den;}
};
//类外函数定义开始
inline ratio makeRatio(long long num, long long den)
{
	return ratio(num, den);
}
inline ratio makeRatio(unsigned long long num, unsigned long long den, bool negative)
{
	return ratio(num, den, negative);
}
inline ratio abs(ratio a1) {
	return ratio(a1.num, a1.den, false);
}
ratio ratioAdd(const ratio &r1, const ratio &r2)
{
	if(!r1.negative && !r2.negative)    //都为正
	{
		return ratio(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den, false);
	}
	else if(r1.negative && !r2.negative) //r1为负，r2为正
	{
		if(r2.num * r1.den < r1.num * r2.den)   //如果减为负
		{
			return ratio(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den, true);
		}
		else    //减完还为正
		{
			return ratio(r2.num * r1.den - r1.num * r2.den, r1.den * r2.den, false);
		}
	}
	else if(!r1.negative && r2.negative) //r1为正，r2为负
	{
		if(r1.num * r2.den < r2.num * r1.den)   //如果减为负
		{
			return ratio(r2.num * r1.den - r1.num * r2.den, r1.den * r2.den, true);
		}
		else    //减完还为正
		{
			return ratio(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den, false);
		}
	}
	else    //都为负
	{
		return ratio(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den, true);
	}
}
ratio ratioMinus(const ratio &r1, const ratio &r2)
{
	if(!r1.negative && !r2.negative)    //都为正
	{
		if(r1.num * r2.den < r2.num * r1.den)   //如果减为负
		{
			return ratio(r2.num * r1.den - r1.num * r2.den, r1.den * r2.den, true);
		}
		else    //减完还为正
		{
			return ratio(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den, false);
		}
	}
	else if(r1.negative && !r2.negative) //r1为负，r2为正
	{
		return ratio(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den, true);
	}
	else if(!r1.negative && r2.negative) //r1为正，r2为负
	{
		return ratio(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den, false);
	}
	else    //都为负
	{
		if(r2.num * r1.den < r1.num * r2.den)   //如果减为负
		{
			return ratio(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den, true);
		}
		else    //减完还为正
		{
			return ratio(r2.num * r1.den - r1.num * r2.den, r1.den * r2.den, false);
		}
	}
}
ratio ratioMultiply(const ratio &r1, const ratio &r2)
{
	return ratio(r1.num * r2.num, r1.den * r2.den, ((int)r1.negative + (int)r2.negative)%2);
}
ratio ratioDivide(const ratio &r1, const ratio &r2)
{
	return ratio(r1.num * r2.den, r1.den * r2.num, (int)r1.negative ^ (int)r2.negative);
}

//类外函数定义结束
//初始化重载定义开始
ratio::ratio(int num1) {
	if (num1 >= 0)
	{
		this->read(num1, 1, false);
	}
	else if (num1 < 0)
	{
		this->read(-num1, 1, true);
	}
}
ratio::ratio(long long num1)
{
	if(num1 >= 0)
	{
		this->read(num1, 1, false);
	}
	else if(num1 < 0)
	{
		this->read(-num1, 1, true);
	}
}
ratio::ratio(double a, int i) {
	if (a >= 0) {
		this->read((long long)(a*pow(10, i)), pow(10, i), false);
	}
	else {
		this->read((long long)-(a*pow(10, i)), pow(10, i), true);
	}
}
ratio::ratio(long long num1, long long den1)
{
	if(num1 >= 0 && den1 >= 0)
		this->read(num1, den1, false);
	else if(num1 <= 0 && den1 >= 0)
		this->read(-num1, den1, true);
	else if(num1 >= 0 && den1 <= 0)
		this->read(num1, -den1, true);
	else
		this->read(-num1, -den1, false);
}
ratio::ratio(double a) {
	int i = JQD;
	if (a >= 0) {
		this->read((long long)(a * pow(10, i)), pow(10, i), false);
	}
	else {
		this->read((long long)-(a * pow(10, i)), pow(10, i), true);
	}
}
ratio::ratio(unsigned long long num1, unsigned long long den1, bool isNegative)
{
	this->read(num1, den1, isNegative);
}
//初始化重载定义结束
//类内函数定义开始
//封装读取函数
ratio &ratio::read(unsigned long long num1, unsigned long long den1, bool isNegative)
{
	if(den1 == 0 || num1 == 0)   //什么都不改变，分数默认等于0
	{
		return *this;
	}

	unsigned long long _gcd = gcd(num1, den1);
	num = num1 / _gcd;
	den = den1 / _gcd;
	negative = isNegative;
	return *this;
}
//打印分数
ratio &ratio::print()
{
	if(den == 1)
	{
		std::cout << (negative ? "-" : "") << num;
	}
	else
	{
		std::cout << (negative ? "-" : "") << num << "/" << den;
	}
	return *this;
}
//化简
ratio &ratio::simplify()
{
	unsigned long long _gcd = gcd(num, den);
	num /= _gcd;
	den /= _gcd;

	return *this;
}
//返回分数的倒数
ratio ratio::reciprocal()
{
	if(num == 0)    //处理0取倒数的问题
	{
		return ratio();
	}
	return ratio(den, num, negative);
}
//使其自己反过来
ratio &ratio::makeItselfreciprocal()
{
	if(num == 0)    //处理要去0倒数的问题
	{
		return *this;
	}
	unsigned long long temp = num;
	num = den;
	den = temp;

	return *this;
}
//类内函数定义结束
//重载操作符开始
//重载输出操作符
std::ostream &operator<<(std::ostream &os, const ratio &r)
{
	if(r.den == 1)
	{
		os << (r.negative ? "-" : "") << r.num;
	}
	else
	{
		os << (r.negative ? "-" : "") << r.num << "/" << r.den;
	}
	return os;
}
//重载输入操作符
std::istream &operator>>(std::istream &is, ratio &r)
{
	long long num, den;
	int temp;
	temp = scanf_s("%lld/%lld", &num, &den);

	if(temp == 2)   //检查输入是否正确
	{
		r = ratio(num, den);
	}
	
	return is;
}

//重载加号
ratio operator+(const ratio &r1, const ratio &r2)
{
	return ratioAdd(r1, r2);
}
ratio operator+=(ratio &r1, const ratio &r2)
{
	r1 = r1 + r2;
	return r1;
}
//重载减号
ratio operator-(const ratio &r1, const ratio &r2)
{
	return ratioMinus(r1, r2);
}
ratio operator-=(ratio &r1, const ratio &r2)
{
	r1 = r1 - r2;
	return r1;
}
//重载负号
ratio operator-(ratio &r1)
{
	return ratio(r1.num, r1.den, !r1.negative);
}
//重载乘号
ratio operator*(const ratio &r1, const ratio &r2)
{
	return ratioMultiply(r1, r2);
}
ratio operator*=(ratio &r1, const ratio &r2)
{
	r1 = r1 * r2;
	return r1;
}
//重载除号
ratio operator/(const ratio &r1, const ratio &r2)
{
	return ratioDivide(r1, r2);
}
ratio operator/=(ratio &r1, const ratio &r2)
{
	r1 = r1 / r2;
	return r1;
}
//重载判断符
bool operator==(const ratio &r1, const ratio &r2)
{
	if(r1.num == r2.num && r1.num == 0)
	{
		return true;
	}

	if(r1.num == r2.num && r1.den == r2.den && r1.negative == r2.negative)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator!=(const ratio &r1, const ratio &r2)
{
	return !(r1 == r2);
}
bool operator>(const ratio &r1, const ratio &r2)
{
	if(!r1.negative && r2.negative) //r1为正，r2为负
	{
		return true;
	}
	else if(r1.negative && !r2.negative) //r1为负，r2为正
	{
		return false;
	}
	else if(!r1.negative && !r2.negative) //都为正
	{
		return r1.num * r2.den < r2.num * r1.den;
	}
	else    //都为负
	{
		return r1.num * r2.den > r2.num * r1.den;
	}
}
bool operator>=(const ratio &r1, const ratio &r2)
{
	return (r1 > r2) || (r1 == r2);
}
bool operator<(const ratio &r1, const ratio &r2)
{
	return !(r1 >= r2);
}
bool operator<=(const ratio &r1, const ratio &r2)
{
	return !(r1 > r2);
}
template<typename Ty> bool operator == (const ratio& r1,const Ty &r2) {
	if (typeid(Ty) == typeid(double)||typeid(Ty)==typeid(float)) {
		Ty r3 = r1;
		return (r3 - r2)<(Ty)pow(10,-JQD);
	}
	ratio a = r2;
	return r1== a;
}
template<typename Ty> bool operator != (const ratio& r1, const Ty& r2) {
	ratio a = r2;
	return r1!= a;
}
template<typename Ty> bool operator > (const ratio& r1, const Ty& r2) {
	ratio a = r2;
	return r1 > a;
}
template<typename Ty> bool operator >= (const ratio& r1, const Ty& r2) {
	ratio a = r2;
	return r1 >= a;
}
template<typename Ty> bool operator <= (const ratio& r1, const Ty& r2) {
	ratio a = r2;
	return r1 <= a;
}
template<typename Ty> bool operator < (const ratio& r1, const Ty& r2) {
	ratio a = r2;
	return r1 < a;
}
template<typename Ty> bool operator != (const Ty& r2, const ratio& r1) {
	ratio a = r2;
	return r1 != a;
}
template<typename Ty> bool operator > (const Ty& r2, const ratio& r1) {
	ratio a = r2;
	return r1 > a;
}
template<typename Ty> bool operator >= (const Ty& r2, const ratio& r1) {
	ratio a = r2;
	return r1 >= a;
}
template<typename Ty> bool operator <= (const Ty& r2, const ratio& r1) {
	ratio a = r2;
	return r1 <= a;
}
template<typename Ty> bool operator < (const Ty& r2, const ratio& r1) {
	ratio a = r2;
	return r1 < a;
}
template<typename Ty> bool operator == (const Ty& r2, const ratio& r1) {
	ratio a = r2;
	return r1 == a;
}
//重载操作符结束
#endif /*_LIBRATIO_H_*/