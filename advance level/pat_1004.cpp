1004. Counting Leaves (30)
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.

Input
Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID_s of its children. For the sake of simplicity, let us fix the root ID to be 01.

Output
For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.
Sample Input
2 1
01 1 02
Sample Output
0 1


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
