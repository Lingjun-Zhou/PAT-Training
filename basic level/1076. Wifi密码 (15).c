下面是微博上流传的一张照片：“各位亲爱的同学们，鉴于大家有时需要使用wifi，又怕耽误亲们的学习，现将wifi密码设置为下列数学题答案：A-1；B-2；C-3；D-4；请同学们自己作答，每两日一换。谢谢合作！！~”—— 老师们为了促进学生学习也是拼了…… 本题就要求你写程序把一系列题目的答案按照卷子上给出的对应关系翻译成wifi的密码。这里简单假设每道选择题都有4个选项，有且只有1个正确答案。

输入格式：
输入第一行给出一个正整数N（<= 100），随后N行，每行按照“编号-答案”的格式给出一道题的4个选项，“T”表示正确选项，“F”表示错误选项。选项间用空格分隔。
输出格式：
在一行中输出wifi密码。
输入样例：
8
A-T B-F C-F D-F
C-T B-F A-F D-F
A-F D-F C-F B-T
B-T A-F C-F D-F
B-F D-T A-F C-F
A-T C-F B-F D-F
D-T B-F C-F A-F
C-T A-F B-F D-F
输出样例：
13224143


#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
	string name_id;
	int code_score;
	int mid_score;
	int final_score;
	double total_score;
}student;

bool cmp(student a, student b) {
	if (a.total_score == b.total_score)
		return a.name_id < b.name_id;

	return a.total_score > b.total_score;
}

int main() {
	//cout << ("dx86w" < "wehu8") << endl;
	int code_num, mid_num, final_num;
	cin >> code_num >> mid_num >> final_num;
	map<string,student> all_poss_students;
	for (int i = 0; i < code_num; i++) {
		string cur_name;
		int code_score;
		cin >> cur_name >> code_score;
		if (code_score >= 200) {
			student cur_student;
			cur_student.name_id = cur_name;
			cur_student.code_score = code_score;
			cur_student.mid_score = -1;
			cur_student.final_score = -1;
			cur_student.total_score = 0;
			all_poss_students[cur_name]=cur_student;
		}
	}

	for (int i = 0; i < mid_num; i++) {
		string cur_name;
		int mid_score;
		cin >> cur_name >> mid_score;
		if (all_poss_students.find(cur_name) != all_poss_students.end()) {
			all_poss_students[cur_name].mid_score = mid_score;
		}
	}

	for (int i = 0; i < final_num; i++) {
		string cur_name;
		int final_score;
		cin >> cur_name >> final_score;
		if (all_poss_students.find(cur_name) != all_poss_students.end()) {
			all_poss_students[cur_name].final_score = final_score;
		}
	}

	vector<student>output_student;
	map<string, student>::iterator it = all_poss_students.begin();

	for (; it != all_poss_students.end(); it++) {
		student cur = (*it).second;
		if (cur.final_score >= cur.mid_score)
			cur.total_score = cur.final_score;
		else {
			cur.total_score = cur.mid_score*0.4 + cur.final_score*0.6;
			cur.total_score = (int)(cur.total_score + 0.5);
		}

		if (cur.total_score >= 60) {
			output_student.push_back(cur);
		}

	}

	sort(output_student.begin(), output_student.end(), cmp);

	for (vector<student>::iterator it = output_student.begin(); it != output_student.end(); it++) {

		cout << (*it).name_id << " " << (*it).code_score << " " << (*it).mid_score << " " << (*it).final_score<<" ";
		cout <<(*it).total_score<< endl;
	}

}
