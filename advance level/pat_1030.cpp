
1030 Travel Plan (30)
A traveler s map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.
Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:
City1 City2 Distance Cost
where the numbers are all integers no more than 500, and are separated by a space.
Output Specification:
For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.
Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40



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
