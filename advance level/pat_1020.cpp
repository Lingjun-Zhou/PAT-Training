#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//后序遍历，最后一个元素是整棵树的根，从后往前分别是右、左子树的根
typedef struct Node{
	int value;
	struct Node* left;
	struct Node* right;
}treeNode;
#define MAX_N 30
//通过后序和中序序列生成一棵树，再将其层次序列输出
vector<int> postOrder( MAX_N );
vector<int> inOrder(MAX_N);
treeNode* creatTree(int left, int right);
void print_BFS(treeNode* tree);
int cur,left,right;
int nodes_num;
int main() {
	cin >> nodes_num;
	for (int i = 0; i < nodes_num; i++) 
		cin >> postOrder[i];
	for (int i = 0; i < nodes_num; i++)
		cin >> inOrder[i];
	cur = nodes_num-1;
	treeNode* tree = creatTree(0,cur);
	print_BFS(tree);
}

void print_BFS(treeNode* tree) {
	queue<treeNode*> my_queue;
	my_queue.push(tree);
	bool flag = true;
	while (!my_queue.empty()) {
		treeNode* cur_node = my_queue.front();
		my_queue.pop();
		if (flag) {
			flag = false;
			cout << cur_node->value;
		}
		else {
			cout << " " << cur_node->value;
		}
		if (cur_node->left != NULL) {
			my_queue.push(cur_node->left);
		}
		if (cur_node->right != NULL) {
			my_queue.push(cur_node->right);
		}
	}
}

int findRootIndex(int root_id) {
	for (int i = 0; i < nodes_num; i++) {
		if (inOrder[i] == root_id) {
			return i;
		}
	}
	return -1;
}

treeNode* creatTree(int left, int right) {
	if (left > right) return NULL;
	int root_id = postOrder[cur];
	cur--;
	int rootIndex = findRootIndex(root_id);
	treeNode* curNode = (treeNode*)malloc(sizeof(struct Node));
	curNode->value = root_id;
	if (left == right) {
		curNode->left = NULL;
		curNode->right = NULL;
	}
	else {
		curNode->right = creatTree(rootIndex + 1, right);
		curNode->left = creatTree(left, rootIndex - 1);
	}
	return  curNode;
}

