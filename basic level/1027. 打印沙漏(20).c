本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印
*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。
给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。
输入格式：
输入在一行给出1个正整数N（<=1000）和一个符号，中间以空格分隔。
输出格式：
首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。
输入样例：
19 *
输出样例：
*****
 ***
  *
 ***
*****
2
//
#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int num;
	char ch;
	cin >> num;
	cin >> ch;
	int n = sqrt((num + 1) / 2);
	int rest = num - 2 * n*n + 1;
	int row = 2 * n - 1;
	int max = row;
	//in 1-th row: there are 2n-1 characters and no space.
	//after that,character-2,space++ each row
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < i; k++)
			cout << " ";
		for (int j = 2*i+1; j <= max; j++)
			cout << ch;
		cout << endl;
	}
	//in n-th row: there are (n-1) spaces and only one character.
	//after that, character+2,space-- each row
	for (int i = n; i < 2 * n - 1; i++) {
		for (int k = 0; k<2*n-i-2;k++)
			cout << " ";
		for (int j = 0; j < 2 * (i - n + 1) + 1; j++)
			cout << ch;
		cout << endl;
	}
	cout << rest << endl;

}
