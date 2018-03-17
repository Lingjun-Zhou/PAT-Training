#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define INF 999999
#define MAX_CITY 500
int graph[MAX_CITY][MAX_CITY];
int edge_weight[MAX_CITY][MAX_CITY];
int dist[MAX_CITY];
bool isVisited[MAX_CITY];
vector<int> pre[MAX_CITY];
vector<int>temp_path, path;
int optimal_path_cost = INF;
int get_path_cost(vector<int>path) {
	int head, tail;
	tail = head = path[0];
	int cost = 0;
	for (int i = 1; i < path.size(); i++) {
		head = path[i];
		cost += edge_weight[head][tail];
		tail = head;
	}
//	cout << cost << endl;
	return cost;
}

void print_path(vector<int>path) {
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";
}

void dfs(int start, int end) {
	temp_path.push_back(end);
	if (end == start) {
		if (get_path_cost(temp_path) < optimal_path_cost) {
			optimal_path_cost = get_path_cost(temp_path);
			path = temp_path;
		}
		temp_path.pop_back();
		return;
	}
	for (int i = 0; i < pre[end].size(); i++)
		dfs(start, pre[end][i]);
	temp_path.pop_back();
}

int main() {
	int vertex_num, edge_num, start, end;
	cin >> vertex_num >> edge_num >> start >> end;
	//初始化图
	for (int i = 0; i < vertex_num; i++) {
		for (int j = 0; j < vertex_num; j++) {
			if (i == j) {
				graph[i][j] = 0;
				edge_weight[i][j] = 0;
			}
			else {
				graph[i][j] = INF;
				edge_weight[i][j] = INF;
			}
		}
	}

	//初始化边的距离和权重
	for ( int i = 0; i < edge_num; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		graph[a][b] = c;
		graph[b][a] = c;
		edge_weight[a][b] = d;
		edge_weight[b][a] = d;
	}

	//初始化dist数组
	for (int i = 0; i < vertex_num; i++) {
		dist[i] = graph[start][i];
	}
	//Dijkstra算法
	for (int i = 0; i < vertex_num; i++) {
		int u = -1, minn = INF;
		for (int j = 0; j < vertex_num; j++) {
			if (!isVisited[j] && minn > dist[j]) {
				minn = dist[j];
				u = j;
			}
		}
		if (u == -1)break;
		isVisited[u] = true;
		for (int k = 0; k < vertex_num; k++) {
			if (!isVisited[k] && graph[u][k] != INF&&dist[k]>dist[u] + graph[u][k]) {
				pre[k].clear();
				pre[k].push_back(u);
				dist[k] = dist[u] + graph[u][k];
			}
			else if (!isVisited[k] && graph[u][k] != INF&&dist[k] == dist[u] + graph[u][k]) {
				pre[k].push_back(u);
			}
			else;
		}
	}
	//深度优先遍历
	dfs(start, end);
	//输出结果
	print_path(path);
	cout << dist[end] << " " << optimal_path_cost;

}
