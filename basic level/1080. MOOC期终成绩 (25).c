对于在中国大学MOOC（http://www.icourse163.org/）学习“数据结构”课程的学生，想要获得一张合格证书，必须首先获得不少于200分的在线编程作业分，然后总评获得不少于60分（满分100）。总评成绩的计算公式为 G = (G期中x 40% + G期末x 60%)，如果 G期中 > G期末；否则总评 G 就是 G期末。这里 G期中 和 G期末 分别为学生的期中和期末成绩。
现在的问题是，每次考试都产生一张独立的成绩单。本题就请你编写程序，把不同的成绩单合为一张。
输入格式：
输入在第一行给出3个整数，分别是 P（做了在线编程作业的学生数）、M（参加了期中考试的学生数）、N（参加了期末考试的学生数）。每个数都不超过10000。
接下来有三块输入。第一块包含 P 个在线编程成绩 G编程；第二块包含 M 个期中考试成绩 G期中；第三块包含 N 个期末考试成绩 G期末。每个成绩占一行，格式为：学生学号 分数。其中学生学号为不超过20个字符的英文字母和数字；分数是非负整数（编程总分最高为900分，期中和期末的最高分为100分）。
输出格式：
打印出获得合格证书的学生名单。每个学生占一行，格式为：
学生学号 G编程 G期中 G期末 G
如果有的成绩不存在（例如某人没参加期中考试），则在相应的位置输出“-1”。输出顺序为按照总评分数（四舍五入精确到整数）递减。若有并列，则按学号递增。题目保证学号没有重复，且至少存在1个合格的学生。
输入样例：
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
输出样例：
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84

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
