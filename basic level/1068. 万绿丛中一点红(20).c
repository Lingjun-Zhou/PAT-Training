对于计算机而言，颜色不过是像素点对应的一个24位的数值。现给定一幅分辨率为MxN的画，要求你找出万绿丛中的一点红，即有独一无二颜色的那个像素点，并且该点的颜色与其周围8个相邻像素的颜色差充分大。
输入格式：
输入第一行给出三个正整数，分别是M和N（<= 1000），即图像的分辨率；以及TOL，是所求像素点与相邻点的颜色差阈值，色差超过TOL的点才被考虑。随后N行，每行给出M个像素的颜色值，范围在[0, 224)内。所有同行数字间用空格或TAB分开。
输出格式：
在一行中按照“(x, y): color”的格式输出所求像素点的位置以及颜色值，其中位置x和y分别是该像素在图像矩阵中的列、行编号（从1开始编号）。如果这样的点不唯一，则输出“Not Unique”；如果这样的点不存在，则输出“Not Exist”。
输入样例1：
8 6 200
0 	 0 	  0 	   0	    0 	     0 	      0        0
65280 	 65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280 	 65280    65280    65280    65280    65280    165280   165280
65280 	 65280 	  16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215
输出样例1：
(5, 3): 16711680
输入样例2：
4 5 2
0 0 0 0
0 0 3 0
0 0 0 0
0 5 0 0
0 0 0 0
输出样例2：
Not Unique
输入样例3：
3 3 5
1 2 3
3 4 5
5 6 7
输出样例3：
Not Exist

#include<iostream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
//一个二维数组，用于存储周围点相对于当前点的坐标偏差
int circle[8][2] = { { -1,-1 },{ 0,-1 },{ 1,-1 },{ 1,0 },{ 1,1 },{ 0,1 },{ -1,1 },{ -1,0 } };
int col, row, tol;
vector<vector<int>>matrix;

bool judge(int x, int y) {
	int jacent_x, jacent_y;
	//对于每个点的周围8个点都进行检查
	for (int i = 0; i < 8; i++) {
		jacent_x = x + circle[i][0];
		jacent_y = y + circle[i][1];
		if (jacent_x >= 0 && jacent_x < col&&jacent_y >= 0 && jacent_y < row
			&&abs(matrix[x][y] - matrix[jacent_x][jacent_y]) <= tol)return false;
	}
	return true;

}


int main() {

	cin >> col >> row >> tol;
	matrix.resize(row, vector<int>(col));
	map<int, int> num_times;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> matrix[i][j];
			num_times[matrix[i][j]]++;
		}
	}

	int cnt = 0;
	int x, y;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (num_times[matrix[i][j]] == 1 && judge(i, j)) {
				cnt++;
				x = j + 1;
				y = i + 1;
			}
		}
	}

	if (cnt == 1) {
		printf("(%d, %d): %d", x, y, matrix[y - 1][x - 1]);
	}
	else if (cnt > 1) {
		cout << "Not Unique";
	}
	else {
		cout << "Not Exist";
	}


}
