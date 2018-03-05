本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第1个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为m行n列，满足条件：m*n等于N；m>=n；且m-n取所有可能值中的最小值。
输入格式：
输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过104，相邻数字以空格分隔。
输出格式：
输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。
输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：
98 95 93
42 37 81
53 20 76
58 60 76


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
