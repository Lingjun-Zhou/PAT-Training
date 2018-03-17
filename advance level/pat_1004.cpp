#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//层序遍历，队列的使用
int main() {
	int total_num, non_leaf_num;
	cin >> total_num >> non_leaf_num;
	vector<int>* all_nodes = new vector<int>[total_num+1];
	bool* no_leaf_node = new bool[total_num+1]();
	for (int i = 0; i < non_leaf_num; i++) {
		int cur_parent, cur_child_num;
		cin >> cur_parent >> cur_child_num;
		no_leaf_node[cur_parent] = true;
		for (int j = 0; j < cur_child_num; j++) {
			int cur_child;
			cin >> cur_child;
			all_nodes[cur_parent].push_back(cur_child);
		}
	}
	int root_id = 1;
	queue<int> cur_queue,next_queue;
	cur_queue.push(root_id);
	int cur_level_num = 0;
	vector<int> outputs;
	while (!cur_queue.empty()) {
		int cur_node_id = cur_queue.front();
		if (!no_leaf_node[cur_node_id])
			cur_level_num++;
		else {
			for (int i = 0; i < all_nodes[cur_node_id].size(); i++) {
					int check_id = all_nodes[cur_node_id][i];
					next_queue.push(check_id);
				}
			}

		cur_queue.pop();
		if (cur_queue.empty()) {
			outputs.push_back(cur_level_num);
			cur_queue = next_queue;
			next_queue = queue<int>();
			cur_level_num = 0;
		}
	}
	
	//cout << 0 ;
	//for (int i = 1; i < outputs.size(); i++) {
	//	cout << " " << outputs[i];
	//}
	//上面那种写法有一个测试点没通过
	for (int i = 0; i < outputs.size(); i++) {
		i == 0 ? cout << outputs[i] : cout << " " << outputs[i];
	}
}
