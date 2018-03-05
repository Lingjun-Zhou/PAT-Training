如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。例如123和51就是朋友数，因为1+2+3 = 5+1 = 6，而6就是它们的朋友证号。给定一些整数，要求你统计一下它们中有多少个不同的朋友证号。注意：我们默认一个整数自己是自己的朋友。
输入格式：
输入第一行给出正整数N。随后一行给出N个正整数，数字间以空格分隔。题目保证所有数字小于104。
输出格式：
首先第一行输出给定数字中不同的朋友证号的个数；随后一行按递增顺序输出这些朋友证号，数字间隔一个空格，且行末不得有多余空格。
输入样例：
8
123 899 51 998 27 33 36 12
输出样例：
4
3 6 9 26

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int get_friend_num(int a) {
	int num = 0;
	while (a  != 0) {
		num += a % 10;
		a /= 10;
	}
	return num;
}

//最大数字 9999，最大朋友证号36，最小为1
int main() {
	int num;
	cin >> num;
	int* all_numbers = new int[num];
	for (int i = 0; i < num; i++)
		cin >> all_numbers[i];
	bool isFilled[36];
	memset(isFilled, 0, sizeof(bool) * 36);

	vector<int>friends_id;
	for (int i = 0; i < num; i++) {
		int first = get_friend_num(all_numbers[i]);
		for (int j = i; j < num; j++) {
			int second = get_friend_num(all_numbers[j]);
			if (first == second&&!isFilled[first]) {
				friends_id.push_back(first);
				isFilled[first] = true;
			}

		}
	}

	cout << friends_id.size() << endl;
	sort(friends_id.begin(), friends_id.end());
	for (vector<int>::iterator it = friends_id.begin(); it != friends_id.end(); it++) {
		if (it == friends_id.begin())
			cout << *it;
		else
			cout << " " << *it;
	}

}


/*
运行超时

int main() {
	int num;
	cin >> num;
	int* all_numbers = new int[num];
	for (int i = 0; i < num; i++)
		cin >> all_numbers[i];

	vector<int>friends_id;

	for (int i = 0; i < num; i++) {
		int first = get_friend_num(all_numbers[i]);
		for (int j = i; j < num; j++) {
			int second = get_friend_num(all_numbers[j]);
			if (first == second && find(friends_id.begin(),friends_id.end(),first)==friends_id.end()) {
				friends_id.push_back(first);
			}
		}
	}
	cout << friends_id.size() << endl;
	sort(friends_id.begin(), friends_id.end());
	for (vector<int>::iterator it = friends_id.begin(); it != friends_id.end(); it++) {
		if (it == friends_id.begin())
			cout << *it;
		else
			cout << " " << *it;
	}


}

*/
