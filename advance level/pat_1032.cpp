#include<iostream>
#include<vector>
using namespace std;
#define MY_MAX 100001
//特殊情况，开始地址为-1；开始地址相同
struct Node {
	int address;
	int indegree;
	char value;
	int next;
};

Node all_nodes[MY_MAX];

int main() {

	int first_start, second_start,total_num;
	cin >> first_start >> second_start>>total_num;

	for (int i = 0; i < total_num; i++) {
		int index;
		cin >> index;
		all_nodes[index].address = index;
		all_nodes[index].indegree = 0;
		cin >> all_nodes[index].value >> all_nodes[index].next;
	}
	all_nodes[first_start].indegree++;
	all_nodes[second_start].indegree++;
	vector<Node> first, second;
	int first_cur = first_start;
	int second_cur = second_start;
	if (first_start == second_start) {
		printf("%05d\n", first_start);
		return 0;
	}
	if (first_start == -1 || second_start == -1) {
		cout << -1<<endl;
		return 0;
	}

	while (all_nodes[first_cur].next != -1) {
		//all_nodes[first_cur].indegree++;
		first_cur = all_nodes[first_cur].next;
		all_nodes[first_cur].indegree++;
	} 
	while (all_nodes[second_cur].next != -1) {
		second_cur = all_nodes[second_cur].next;
		all_nodes[second_cur].indegree++;
		if (all_nodes[second_cur].indegree == 2) {
			printf("%05d\n",second_cur);
			return 0;
		}	
	}

	cout << -1 << endl;
	return 0;
			

}