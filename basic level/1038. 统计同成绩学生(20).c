本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。
输入格式：
输入在第1行给出不超过105的正整数N，即学生总人数。随后1行给出N名学生的百分制整数成绩，中间以空格分隔。最后1行给出要查询的分数个数K（不超过N的正整数），随后是K个分数，中间以空格分隔。
输出格式：
在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。
输入样例：
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
输出样例：
3 2 0

#include<iostream>
#include<memory.h>
using namespace std;
int main() {
	int numOfScores[101];
	memset(numOfScores, 0, 101*sizeof(int));

	int numOfStudens;
	int cur_Score;
	cin >> numOfStudens;
	for (int i = 0; i < numOfStudens; i++) {
		cin >> cur_Score;
		numOfScores[cur_Score]++;
	}

	int query_time;
	cin >> query_time;
	int* query_score = new int[query_time];
	for (int i = 0; i < query_time; i++) {
		cin >> query_score[i];
	}
	for (int i = 0; i < query_time; i++) {
		if (i != query_time - 1)
			cout << numOfScores[query_score[i]] << " ";
		else
			cout << numOfScores[query_score[i]];
	}

}
