小明PAT考了满分，高兴之余决定发起微博转发抽奖活动，从转发的网友中按顺序每隔N个人就发出一个红包。请你编写程序帮助他确定中奖名单。
输入格式：
输入第一行给出三个正整数M（<= 1000）、N和S，分别是转发的总量、小明决定的中奖间隔、以及第一位中奖者的序号（编号从1开始）。随后M行，顺序给出转发微博的网友的昵称（不超过20个字符、不包含空格回车的非空字符串）。
注意：可能有人转发多次，但不能中奖多次。所以如果处于当前中奖位置的网友已经中过奖，则跳过他顺次取下一位。
输出格式：
按照输入的顺序输出中奖名单，每个昵称占一行。如果没有人中奖，则输出“Keep going...”。
输入样例1：
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
输出样例1：
PickMe
Imgonnawin!
TryAgainAgain
输入样例2：
2 3 5
Imgonnawin!
PickMe
输出样例2：
Keep going...

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int total_num, step, first;
	cin >> total_num >> step >> first;

	if (first > total_num) {
		cout << "Keep going..." << endl;
		return 0;
	}

	vector<string> lucky_guys;

	vector<string> all_guys;
	for (int i = 0; i < total_num; i++) {
		string cur_string;
		cin >> cur_string;
		all_guys.push_back(cur_string);
	}
	for (int i = first - 1; i < total_num; i += step) {
		while (i<total_num&&find(lucky_guys.begin(), lucky_guys.end(), all_guys[i]) != lucky_guys.end()) {
			i++;
		}
		cout << all_guys[i] << endl;
		lucky_guys.push_back(all_guys[i]);
	}



}
