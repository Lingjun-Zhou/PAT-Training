C语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：
0. 冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
1. 排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
2. 其他人将得到巧克力。
给定比赛的最终排名以及一系列参赛者的ID，你要给出这些参赛者应该获得的奖品。
输入格式：
输入第一行给出一个正整数N（<=10000），是参赛者人数。随后N行给出最终排名，每行按排名顺序给出一位参赛者的ID（4位数字组成）。接下来给出一个正整数K以及K个需要查询的ID。
输出格式：
对每个要查询的ID，在一行中输出“ID: 奖品”，其中奖品或者是“Mystery Award”（神秘大奖）、或者是“Minion”（小黄人）、或者是“Chocolate”（巧克力）。如果所查ID根本不在排名里，打印“Are you kidding?”（耍我呢？）。如果该ID已经查过了（即奖品已经领过了），打印“ID: Checked”（不能多吃多占）。
输入样例：
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
输出样例：
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?

#include<iostream>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;

typedef struct {
	int player_id;
	int rank;
	bool selected;
	bool checked;
}player;

bool isPrime(int a) {
	if (a ==2)
		return true;
	for (int i = 2; i <= sqrt(a); i++)
	//	return (a%i == 0) ? false : true;????
		if (a%i == 0)
			return false;
	return true;

}

int main() {
	int num_of_players;
	//cout << isPrime(6) << endl;
	cin >> num_of_players;
	//player* all_players = new player[num_of_players];
	player all_poss_players[10001];
	memset(all_poss_players, 0, sizeof(all_poss_players));
	//cout << sizeof(all_poss_players)<<" "<<sizeof(player) << endl;

	for (int i = 0; i < num_of_players; i++) {
		int cur_player_id;
		cin >> cur_player_id;
		all_poss_players[cur_player_id].rank = i + 1;
		all_poss_players[cur_player_id].checked = false;
		all_poss_players[cur_player_id].selected = true;
	}

	int num_of_query;
	cin >> num_of_query;
	int* queries = new int[num_of_query];
	for (int i = 0; i < num_of_query; i++)
		cin >> queries[i];

	for (int i = 0; i < num_of_query; i++) {
		int query_id = queries[i];
		cout << setw(4) << setfill('0') << query_id;
		cout << ": ";

		if (all_poss_players[query_id].checked) {
			cout << "Checked" << endl;
			continue;
		}

		if (!all_poss_players[query_id].selected) {
			cout << "Are you kidding?" << endl;
			continue;
		}

		if(!all_poss_players[query_id].checked){
			all_poss_players[query_id].checked = true;
			int rank = all_poss_players[query_id].rank;
			if (rank == 1)
				cout << "Mystery Award" << endl;
			else if (isPrime(rank))
				cout << "Minion" << endl;
			else
				cout << "Chocolate" << endl;
			continue;
		}

	}

}
