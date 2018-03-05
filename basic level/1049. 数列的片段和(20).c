给定一个正数数列，我们可以从中截取任意的连续的几个数，称为片段。例如，给定数列{0.1, 0.2, 0.3, 0.4}，我们有(0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4) 这10个片段。
给定正整数数列，求出全部片段包含的所有的数之和。如本例中10个片段总和是0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0。
输入格式：
输入第一行给出一个不超过105的正整数N，表示数列中数的个数，第二行给出N个不超过1.0的正数，是数列中的数，其间以空格分隔。
输出格式：
在一行中输出该序列所有片段包含的数之和，精确到小数点后2位。
输入样例：
4
0.1 0.2 0.3 0.4
输出样例：
5.00

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int num;
	cin >> num;
	int m=0, n=0, min = num;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= i; j++) {
			if (i*j == num&&i - j < min) {
				min = i - j;
				m = i;
				n = j;
			}
		}
	}

	int* numbers = new int[num];
	for (int i = 0; i < num; i++)
		cin >> numbers[i];
	//降序排序

	sort(numbers, numbers + num,compare);

	int** screw = new int*[m];
	for (int i = 0; i < m; i++) {
		screw[i] = new int[n]();
	}
	//动态数组初始化问题
	//memset(screw, 0, sizeof(int)*num);

	int i=0,j=0,k = 0;
	screw[i][j] = numbers[k++];
	while (k < num) {
		while (j + 1 < n && !screw[i][j + 1]) screw[i][++j] = numbers[k++];	//right
		while (i + 1 < m && !screw[i + 1][j]) screw[++i][j] = numbers[k++];	//down
		while (j - 1 >= 0 && !screw[i][j - 1]) screw[i][--j] = numbers[k++];		//left
		while (i - 1 >= 0 && !screw[i - 1][j])screw[--i][j] = numbers[k++];		//up
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if(j==n-1)
				cout << screw[i][j] <<endl;
			else
				cout << screw[i][j] << " ";
		}
	}

}
