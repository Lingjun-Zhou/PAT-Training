拍集体照时队形很重要，这里对给定的N个人K排的队形设计排队规则如下：
每排人数为N/K（向下取整），多出来的人全部站在最后一排；
后排所有人的个子都不比前排任何人矮；
每排中最高者站中间（中间位置为m/2+1，其中m为该排人数，除法向下取整）；
每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧（例如5人身高为190、188、186、175、170，则队形为175、188、190、186、170。这里假设你面对拍照者，所以你的左边是中间人的右边）；
若多人身高相同，则按名字的字典序升序排列。这里保证无重名。
现给定一组拍照人，请编写程序输出他们的队形。
输入格式：
每个输入包含1个测试用例。每个测试用例第1行给出两个正整数N（<=10000，总人数）和K（<=10，总排数）。随后N行，每行给出一个人的名字（不包含空格、长度不超过8个英文字母）和身高（[30, 300]区间内的整数）。
输出格式：
输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。
输入样例：
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
输出样例：
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John

#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
//结构体四种初始化方式：http://blog.csdn.net/github_26672553/article/details/50382188
typedef struct {
	string name;
	int height;
}member;

bool compare(member a, member b) {
	return a.height != b.height ? a.height > b.height : a.name < b.name;
}

int main() {
	int total_num, rows, each_row_num;
	cin >> total_num >> rows;
	each_row_num = total_num / rows;
	member* members = new member[total_num];
	for (int i = 0; i < total_num; i++) {
		char* name = new char[9];
		int height;
		cin >> name >> height;
		members[i] = { name,height };
	}

	sort(members, members + total_num, compare);
	/*
	for (int i = 0; i < total_num; i++) {
	cout << members[i].name << " " ;
	}
	cout << endl;
	for (int i = 0; i < total_num; i++) {
	cout << members[i].height << " ";
	}
	cout << endl;
	*/
	int row_num =  total_num - each_row_num * (rows-1);
	int index = 0;
	//cout << row_num << endl;
	for (int i = 0; i < rows;i++) {
		member* cur_row = new member[row_num];
		bool isLeft = true;

		int m_index = row_num / 2 + 1 - 1;
		int right_num = row_num - m_index - 1;
		int left_num = m_index;
		cur_row[m_index] = members[index++];
		int temp = row_num - 1;

		while (temp--) {
			if (isLeft) {
				left_num--;
				cur_row[left_num] = members[index++];
			}
			else {
				cur_row[row_num - right_num] = members[index++];
				right_num--;
			}
			isLeft = !isLeft;
		}

		cout << cur_row[0].name;
		for (int i = 1; i < row_num; i++)
			cout << " " << cur_row[i].name;
		cout << endl;

		row_num = each_row_num;
	}

}
