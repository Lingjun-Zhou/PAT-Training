批改多选题是比较麻烦的事情，本题就请你写个程序帮助老师批改多选题，并且指出哪道题错的人最多。
输入格式：
输入在第一行给出两个正整数N（<=1000）和M（<=100），分别是学生人数和多选题的个数。随后M行，每行顺次给出一道题的满分值（不超过5的正整数）、选项个数（不少于2且不超过5的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母a开始顺次排列。各项间以1个空格分隔。最后N行，每行给出一个学生的答题情况，其每题答案格式为“(选中的选项个数 选项1 ……)”，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。
输出格式：
按照输入的顺序给出每个学生的得分，每个分数占一行。注意判题时只有选择全部正确才能得到该题的分数。最后一行输出错得最多的题目的错误次数和编号（题目按照输入的顺序从1开始编号）。如果有并列，则按编号递增顺序输出。数字间用空格分隔，行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出“Too simple”。
输入样例：
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
输出样例：
3
6
5
2 2 3 4

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

typedef struct {
	int score;
	int total_choices;
	int correct_choices_num;
	char* correct_choices;
} question;

typedef struct {
	int num_of_answers;
	char* answer_choices;
}answer;

typedef struct {
	answer* my_answers;
}student;

typedef struct {
	int question_id;
	int error_times;
}quesetion_error_times;

bool cmp(quesetion_error_times a, quesetion_error_times b) {
	return a.error_times > b.error_times;
}

bool check_answer(answer ans, question ques) {
	if (ans.num_of_answers != ques.correct_choices_num)
		return false;
	else {
		for (int i = 0; i < ans.num_of_answers; i++) {
			if (ans.answer_choices[i] != ques.correct_choices[i])
				return false;
		}
	}
	return true;
}

void print_question(question ques) {
	cout << ques.score << " " << ques.total_choices << " " << ques.correct_choices_num;
	for (int i = 0; i < ques.correct_choices_num; i++) {
		cout << " " << ques.correct_choices[i];
	}
	cout << endl;
}

void print_answer(answer ans) {
	cout << "(" << ans.num_of_answers;
	for (int i = 0; i < ans.num_of_answers; i++)
		cout << " " << ans.answer_choices[i];
	cout << ")";
}

int main() {
	int num_of_student, num_of_question;
	cin >> num_of_student >> num_of_question;
	question* all_questions = new question[num_of_question];
	for (int i = 0; i < num_of_question; i++) {
		question cur_question;
		cin >> cur_question.score >> cur_question.total_choices >> cur_question.correct_choices_num;
		int temp_num = cur_question.correct_choices_num;
		cur_question.correct_choices = new char[temp_num];
		for (int j = 0; j < temp_num; j++) {
			cin >> cur_question.correct_choices[j];
		}
		all_questions[i] = cur_question;
	}

	getchar();

	student* all_students = new student[num_of_student];
	for (int i = 0; i < num_of_student; i++) {
		all_students[i].my_answers = new answer[num_of_question];
		char cur_ch;
		int count = 0;
		while ((cur_ch = getchar()) != '\n') {
			if (cur_ch == '(') {
				answer cur_answer;
				int temp_num;
				cin >> temp_num;
				cur_answer.num_of_answers = temp_num;
				cur_answer.answer_choices = new char[temp_num];
				for (int i = 0; i < temp_num; i++)
					cin >> cur_answer.answer_choices[i];
				all_students[i].my_answers[count++] = cur_answer;
			}
		}
	}

	int* total_scores = new int[num_of_student];
	quesetion_error_times* statistic = new quesetion_error_times[num_of_question];

	memset(total_scores, 0, sizeof(int)*num_of_student);
	memset(statistic, 0, sizeof(quesetion_error_times)*num_of_question);
	//第几个学生
	for (int i = 0; i < num_of_student; i++) {
		//第几道题
		for (int j = 0; j < num_of_question; j++) {
			statistic[j].question_id = j + 1;
			//print_answer(all_students[i].my_answers[j]);
			if (check_answer(all_students[i].my_answers[j], all_questions[j]))
				total_scores[i] += all_questions[j].score;
			else
				statistic[j].error_times++;
		}
	//	cout << endl;
	}
	for(int i = 0; i < num_of_student;i++){
		cout << total_scores[i] << endl;
	}

	sort(statistic, statistic + num_of_question, cmp);

	if (statistic[0].error_times == 0)
		cout << "Too simple" << endl;
	else {
		cout << statistic[0].error_times;
		int i = 0;
		vector<int> question_ids;
		question_ids.push_back(statistic[i].question_id);
		while (statistic[i].error_times == statistic[i + 1].error_times) {
			question_ids.push_back(statistic[i + 1].question_id);
			i++;
		}
		sort(question_ids.begin(), question_ids.end());
		for (vector<int>::iterator it = question_ids.begin(); it < question_ids.end();it++)
			cout << " " << *it;
		//for each (auto cur in question_ids)
		//	cout << " " << cur;
	}


	//for (int i = 0; i < num_of_question; i++)
	//	print_question(all_questions[i]);

}
