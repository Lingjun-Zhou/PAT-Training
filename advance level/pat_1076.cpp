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