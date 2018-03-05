一个分数一般写成两个整数相除的形式：N/M，其中M不为0。最简分数是指分子和分母没有公约数的分数表示形式。
现给定两个不相等的正分数 N1/M1 和 N2/M2，要求你按从小到大的顺序列出它们之间分母为K的最简分数。
输入格式：
输入在一行中按N/M的格式给出两个正分数，随后是一个正整数分母K，其间以空格分隔。题目保证给出的所有整数都不超过1000。
输出格式：
在一行中按N/M的格式列出两个给定分数之间分母为K的所有最简分数，按从小到大的顺序，其间以1个空格分隔。行首尾不得有多余空格。题目保证至少有1个输出。
输入样例：
7/18 13/20 12
输出样例：
5/12 7/12

#include<iostream>

using namespace std;

int find_gcd(int a, int b) {
	int temp;
	while (a%b != 0) {
		temp = a;
		a = b;
		b = temp%b;
	}
	return b;
}

int find_lcm(int a, int b) {
	return a*b / find_gcd(a, b);
}


int main() {
	//cout << find_gcd(3, 5) << " " << find_lcm(999, 1000) << endl;
	int a_numerator, a_denominator, b_numerator, b_denominator, k;
	//"/不是转义"
	scanf_s("%d/%d %d/%d %d", &a_numerator, &a_denominator, &b_numerator, &b_denominator, &k);

	int same_denominator = find_lcm(a_denominator, b_denominator);
	int common_denominator = find_lcm(same_denominator, k);

	a_numerator = a_numerator * common_denominator / a_denominator;
	b_numerator = b_numerator * common_denominator / b_denominator;

	int start = a_numerator < b_numerator ? a_numerator : b_numerator;
	int end = a_numerator < b_numerator ? b_numerator : a_numerator;
	bool isFirst = true;
	for (int i = start + 1; i < end; i++) {
		int divisor_num = find_gcd(common_denominator, i);

		if (common_denominator / divisor_num == k) {
			if (isFirst) {
				cout << i / divisor_num << "/" << k;
				isFirst = false;
			}
			else {
				cout << " " << i / divisor_num << "/" << k;
			}
		}

	}
	cout << endl;
}
