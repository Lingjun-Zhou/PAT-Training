为了用事实说明挖掘机技术到底哪家强，PAT组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。
输入格式：
输入在第1行给出不超过105的正整数N，即参赛人数。随后N行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从1开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。
输出格式：
在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。
输入样例：
6
3 65
2 80
1 100
2 70
3 40
3 0
输出样例：
2 150

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> PAIR;
bool cmp(const PAIR&a, const PAIR&b) {
	return a.second > b.second;
}

int main() {
	int numOfPlayer;
	cin >> numOfPlayer;
	map<int, int> schoolMap;
	for (int i = 0; i < numOfPlayer; i++) {
		int cur_school_id, cur_score;
		cin >> cur_school_id >> cur_score;
		map<int, int>::iterator it;
		it = schoolMap.find(cur_school_id);
		if (it != schoolMap.end()) {
			schoolMap[cur_school_id] += cur_score;
		}
		else {
			schoolMap[cur_school_id] = cur_score;
		}
	}
	vector<pair<int, int>> temp;
	for (auto mapping : schoolMap) {
		temp.push_back(mapping);
	}

	sort(temp.begin(), temp.end(), cmp);

	cout << temp[0].first<< " " << temp[0].second << endl;


}
