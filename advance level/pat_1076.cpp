
1076 Forwards on Weibo (30)
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=1000), the number of users; and L (<=6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:
M[i] user_list[i]
where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that are followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.
Then finally a positive K is given, followed by K UserID''s for query.
Output Specification:
For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.
Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<int> all_nodes[1001];
int nodes_num, level_num;
bool isVisited[1001];

void bfs(int query_id) {
	fill(isVisited, isVisited + 1001, false);
	//for (int i = 1; i <= nodes_num; i++)
	//	isVisited[i] = false;
	int num = 0;
	int first = 0, last = 1, nowlevel = 0, cnt = 1;
	queue<int>my_queue;
	isVisited[query_id] = true;
	my_queue.push(query_id);
	while (!my_queue.empty()) {
		query_id = my_queue.front();
		my_queue.pop();
		first++;
		for (int i = 0; i < all_nodes[query_id].size(); i++) {
			if (!isVisited[all_nodes[query_id][i]]) {
				my_queue.push(all_nodes[query_id][i]);
				isVisited[all_nodes[query_id][i]] = true;
				cnt++;
			}
		}
		if (first == last) {
			last = cnt;
			nowlevel++;
		}
		if (nowlevel == level_num) {
			cout << cnt - 1 << endl;
			return;
		}
	}
	cout << cnt - 1 << endl;
}

int main() {
	cin >> nodes_num >> level_num;
	for (int i = 1; i <= nodes_num; i++) {
		int followers_num;
		cin >> followers_num;
		for (int j = 0; j < followers_num; j++) {
			int cur_id;
			cin >> cur_id;
			all_nodes[cur_id].push_back(i);
		}
	}

	int query_time;
	cin >> query_time;
	for (int i = 0; i < query_time; i++) {
		int query_id;
		cin >> query_id;
		 bfs(query_id);

	}


}
