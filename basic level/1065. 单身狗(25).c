“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。
输入格式：
输入第一行给出一个正整数N（<=50000），是已知夫妻/伴侣的对数；随后N行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个ID号，为5位数字（从00000到99999），ID间以空格分隔；之后给出一个正整数M（<=10000），为参加派对的总人数；随后一行给出这M位客人的ID，以空格分隔。题目保证无人重婚或脚踩两条船。
输出格式：
首先第一行输出落单客人的总人数；随后第二行按ID递增顺序列出落单的客人。ID间用1个空格分隔，行的首尾不得有多余空格。
输入样例：
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
输出样例：
5
10000 23333 44444 55555 88888

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;


typedef struct {
	bool hasCouple;
	bool isSelected;
	int couple_id;
}party_member;

int main() {
	party_member all_members[100000];
	memset(all_members, 0, sizeof(party_member) * 100000);

	int couple_num, selected_num;
	cin >> couple_num;
	for (int i = 0; i < couple_num; i++) {
		int member_id_1, member_id_2;
		cin >> member_id_1 >> member_id_2;
		all_members[member_id_1].hasCouple = true;
		all_members[member_id_1].couple_id = member_id_2;
		all_members[member_id_2].hasCouple = true;
		all_members[member_id_2].couple_id = member_id_1;
	}
	cin >> selected_num;
	vector<int> single_dog;
	int* all_selected_numbers = new int[selected_num];
	for (int i = 0; i < selected_num; i++) {
		int cur_id;
		cin >> cur_id;
		all_selected_numbers[i] = cur_id;
		all_members[cur_id].isSelected = true;
	}
	for (int i = 0; i < selected_num; i++) {
		int cur_id = all_selected_numbers[i];
		int cur_couple = all_members[cur_id].couple_id;
		if (all_members[cur_id].hasCouple&&all_members[cur_couple].isSelected)
			;
		else
			single_dog.push_back(cur_id);
	}

	cout << single_dog.size() << endl;
	sort(single_dog.begin(), single_dog.end());
	for (vector<int>::iterator it = single_dog.begin(); it != single_dog.end(); it++) {
		if (it == single_dog.begin())
			cout << setw(5) << setfill('0') << *it;
		else
			cout <<" "<< setw(5) << setfill('0') << *it;
	}


}
