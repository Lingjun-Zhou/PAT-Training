英国天文学家爱丁顿很喜欢骑车。据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数”E，即满足有E天骑车超过E英里的最大整数E。据说爱丁顿自己的E等于87。
现给定某人N天的骑车距离，请你算出对应的爱丁顿数E（<=N）。
输入格式：
输入第一行给出一个正整数N（<=105），即连续骑车的天数；第二行给出N个非负整数，代表每天的骑车距离。
输出格式：
在一行中给出N天的爱丁顿数。
输入样例：
10
6 7 6 9 3 10 8 2 7 8
输出样例：
6

#include<iostream>
#include<algorithm>
using namespace std;

int cmp(int a, int b) {
	return a > b;
}

int main() {

	int num_of_days;
	cin >> num_of_days;
	int * miles = new int[num_of_days];
	for (int i = 0; i < num_of_days; i++)
		cin >> miles[i];
	sort(miles, miles + num_of_days, cmp);

	int num_e = num_of_days;

	while (num_e) {
		if (miles[num_e - 1] > num_e)
			break;
		else
			num_e--;
	}
	cout << num_e << endl;
}
