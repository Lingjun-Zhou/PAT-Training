本题要求编写程序，计算2个有理数的和、差、积、商。
输入格式：
输入在一行中按照“a1/b1 a2/b2”的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为0。
输出格式：
分别在4行中按照“有理数1 运算符 有理数2 = 结果”的格式顺序输出2个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式“k a/b”，其中k是整数部分，a/b是最简分数部分；若为负数，则须加括号；若除法分母为0，则输出“Inf”。题目保证正确的输出中没有超过整型范围的整数。
输入样例1：
2/3 -4/2
输出样例1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例2：
5/3 0/6
输出样例2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

#include<iostream>
#include<stdio.h>
using namespace std;
//attention：you'd better use long rather than int in case of overflow
//retrun a positive GCD
long findGCD(long a, long b) {
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a == b)
		return a;
	//this way is much more effective!
	long gcd = b;
	while (a%b != 0) {
		gcd = a%b;
		a = b;
		b = gcd;
	}
	return gcd;
}

//return a positive LCM
long findLCM(long a, long b) {
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	long lcm = a*b;
	return lcm/findGCD(a,b);
}

void prlongNumber(long numerator, long denominator) {

	if (numerator == 0) {
		cout << "0";
		return;
	}
	long GCD = findGCD(numerator, denominator);
	numerator /= GCD;
	denominator /= GCD;
	//div operation may result in negative denominator
	if (denominator < 0) {
		denominator = -denominator;
		numerator = -numerator;
	}

	//since denominator is always greater than zero, it needn't to be applied with abs function.
	if (denominator == 1) {
		if (numerator < 0) {
			cout << "(" << numerator << ")";
		}
		else {
			cout << numerator;
		}
	}
	else if (denominator == abs(numerator)) {
		if (numerator < 0) {
			cout << "(-1)";
		}
		else {
			cout << "1";
		}
	}
	else if (denominator>abs(numerator)) {
		if (numerator < 0) {
			cout << "(" << numerator << "/" << denominator << ")";
		}
		else {
			cout << numerator << "/" << denominator;
		}
	}
	else {
		long longegral_part = abs(numerator) / denominator;
		long rest_part = abs(numerator) % denominator;
		if (numerator < 0) {
			cout << "(-" << longegral_part << " " << rest_part<<"/"<<denominator << ")";
		}
		else {
			cout << longegral_part << " " << rest_part << "/" << denominator;
		}
	}
}

int main() {
	long aNumerator, aDenominator;
	long bNumerator, bDenominator;
	//if number is long type,then you should use "%ld" rather than "d"
	scanf_s("%ld/%ld %ld/%ld", &aNumerator, &aDenominator, &bNumerator, &bDenominator);

	//you can not compute a gcd between zero and any numbers.
	if (aNumerator != 0) {
		long aGCD = findGCD(aNumerator, aDenominator);
		aNumerator /= aGCD;
		aDenominator /= aGCD;
	}
	else {
		aNumerator = 0;
	}
	if (bNumerator != 0) {
		long bGCD = findGCD(bNumerator, bDenominator);
		bNumerator /= bGCD;
		bDenominator /= bGCD;
	}
	else {
		bNumerator = 0;
	}


	//add
	long LCM = findLCM(aDenominator, bDenominator);
	long addDenominator = LCM;
	long addNumerator = aNumerator * (LCM / aDenominator) + bNumerator * (LCM / bDenominator);
	prlongNumber(aNumerator, aDenominator);
	cout << " + ";
	prlongNumber(bNumerator, bDenominator);
	cout << " = ";
	prlongNumber(addNumerator, addDenominator);
	cout << endl;
	//sub
	long subNumerator = aNumerator * (LCM / aDenominator) - bNumerator * (LCM / bDenominator);
	long subDenominator = LCM;
	prlongNumber(aNumerator, aDenominator);
	cout << " - ";
	prlongNumber(bNumerator, bDenominator);
	cout << " = ";
	prlongNumber(subNumerator, subDenominator);
	cout << endl;

	//mul
	long mulNumerator = aNumerator * bNumerator;
	long mulDenominator = aDenominator* bDenominator;
	prlongNumber(aNumerator, aDenominator);
	cout << " * ";
	prlongNumber(bNumerator, bDenominator);
	cout << " = ";
	prlongNumber(mulNumerator, mulDenominator);
	cout << endl;
	//div
	prlongNumber(aNumerator, aDenominator);
	cout << " / ";
	prlongNumber(bNumerator, bDenominator);
	cout << " = ";
	if (bNumerator == 0) {
		cout << "Inf" << endl;
	}
	else {
		long divNumerator = aNumerator * bDenominator;
		long divDenominator = aDenominator * bNumerator;
		prlongNumber(divNumerator, divDenominator);
		cout << endl;
	}


}
