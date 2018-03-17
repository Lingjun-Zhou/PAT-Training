#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
#define MY_MAX 10001
using namespace std;
int itsFather[MY_MAX];
bool isRoot[MY_MAX];
int depth[MY_MAX];
vector<int> all_nodes[MY_MAX];
bool isVisited[MY_MAX];
int deepest;

void init(int length) {
	for (int i = 1; i <= length; i++) {
		itsFather[i] = i;
		isRoot[i] = false;
	}
}

int findFather(int a) {
	int x = a;
	while (x != itsFather[x]) {
		x = itsFather[x];
	}
	//将当前节点到根节点之间的所有节点的itsFather都设置为根节点编号，减少之后的查询次数
	while (a != itsFather[a]) {
		int z = a;
		a = itsFather[a];
		itsFather[z] = x;
	}
	return x;
}

void Union(int a, int b) {
	int aFather = findFather(a);
	int bFather = findFather(b);
	if (aFather != bFather) {
		itsFather[aFather] = bFather;
	}
}

int dfs(int s) {//返回以s为起点所能到达的最大深度
	int ans = 0;
	if (isVisited[s])return 0;
	isVisited[s] = true;
	int m = all_nodes[s].size();
	for (int i = 0; i < m; i++) {
		if (!isVisited[all_nodes[s][i]]) {//比较当前点出发的各邻点的最大深度
			int temp = dfs(all_nodes[s][i]);
			ans = ans > temp ? ans : temp;
		}
	}
	return ans + 1;//当前点+各邻点中的最大深度，就是当前点出发的最大深度
}

int main() {
	int n;
	cin >> n;
	init(n);
	for (int i = 1; i < n; i++) {
		int a, b; 
		cin >> a >> b;
		Union(a, b);
		all_nodes[a].push_back(b);
		all_nodes[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		isRoot[findFather(i)] = true;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += isRoot[i];

	if (sum > 1) {
		printf("Error: %d components\n", sum);
		return 0;
	}
	else {
		for (int i = 1; i <= n; i++) {
			//一次遍历就将所有点都遍历了，所以开始每次新的遍历前需将isVisited数组置零
			memset(isVisited, 0, sizeof(isVisited));
			depth[i] = dfs(i);
			if (depth[i] >= deepest)
				deepest = depth[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (depth[i] == deepest)
			cout << i << endl;
	}

}