
To store English words, one method is to use linked lists and store a word letter by letter. To save some space, we may let the words share the same sublist if they share the same suffix. For example, "loading" and "being" are stored as showed in Figure 1.

Figure 1
You are supposed to find the starting position of the common suffix (e.g. the position of "i" in Figure 1).
Input Specification:
Each input file contains one test case. For each case, the first line contains two addresses of nodes and a positive N (<= 105), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes. The address of a node is a 5-digit positive integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is the letter contained by this node which is an English letter chosen from {a-z, A-Z}, and Next is the position of the next node.
Output Specification:
For each case, simply output the 5-digit starting position of the common suffix. If the two words have no common suffix, output "-1" instead.
Sample Input 1:
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
Sample Output 1:
67890
Sample Input 2:
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
Sample Output 2:
-1


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
