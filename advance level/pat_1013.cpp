1013 Battle Over Cities (25)

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MAX_CITY 1000
//图的遍历（isVisited数组标识），统计连通个数，DFS
int graph[MAX_CITY][MAX_CITY];
bool isVisited[MAX_CITY];
int city_num, edge_num, check_num;
void dfs(int node) {
	isVisited[node] = true;
	for (int i = 1; i <= city_num; i++) {
		if (isVisited[i] == false && graph[node][i] == 1)
			dfs(i);
	}
}

int main() {
	cin >> city_num >> edge_num >> check_num;
	for (int i = 0; i < edge_num; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for (int i = 0; i < check_num; i++) {
		memset(isVisited, false, sizeof(isVisited));
		int cur;
		cin >> cur;
		isVisited[cur] = true;
		int cnt = 0;
		for (int j = 1; j <= city_num; j++) {
			if (isVisited[j] == false) {
				dfs(j);
				cnt++;
			}
		}
		cout << cnt-1 << endl;
	}
}
