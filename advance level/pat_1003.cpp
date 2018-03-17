


//最短路径问题，采用Dijkstra算法，可算出任意两点间的最短距离
//深度优先遍历，回溯的方法找到最优解
#include<algorithm>
#include<iostream>
#include<vector>
#define MY_MAX 100000
//#define DEBUG
using namespace std;
int  path_num;
vector<int>path,temp_path;
int* vertex_value;
vector<vector<int>>pre;
int optimal_value;

int get_total_value(vector<int>path) {
	int sum = 0;
	for (int i = 0; i < path.size(); i++)
		sum += vertex_value[path[i]];
	return sum;
}
void print_path(vector<int>path) {
	for (int i = 0; i < path.size(); i++)
		cout << path[i] << "-->";
	cout << endl;
}

void dfs(int start_point, int end_point) {
	if (end_point == start_point) {
		temp_path.push_back(end_point);
		//print_path(temp_path);
		if (get_total_value(temp_path) > optimal_value) {
			optimal_value = get_total_value(temp_path);
			path = temp_path;
		}
		temp_path.pop_back();
		print_path(temp_path);
		path_num++;
		return;
	}
	temp_path.push_back(end_point);
	print_path(temp_path);
	for (int i = 0; i < pre[end_point].size(); i++) {
		dfs(start_point, pre[end_point][i]);
	}
	temp_path.pop_back();
	print_path(temp_path);

}

int main() {
	int vertex_num, edge_num, start_point, end_point;
	cin >> vertex_num >> edge_num >> start_point >> end_point;
	pre.resize(vertex_num);
	 vertex_value = new int[vertex_num];
	for (int i = 0; i < vertex_num; i++) {
		cin >> vertex_value[i];
	}

	//-------------create a graph--------------------
	int** map = new int*[vertex_num];
	for (int i = 0; i < vertex_num; i++) {
		map[i] = new int[vertex_num];
		for (int j = 0; j < vertex_num; j++) {
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = MY_MAX;

		}
	}
	while (edge_num--) {
		int i, j, weight;
		cin >> i >> j >> weight;
		map[i][j] = weight;
		map[j][i] = weight;
	}
	//------------the distance between start-point and all other points------------
	bool* visited = new bool[vertex_num](); //--->all initialized as false
	int* distance = new int[vertex_num];
	for (int i = 0; i < vertex_num; i++) {
		distance[i] = map[start_point][i];
	}
#ifdef DEBUG
	cout << map[start_point][start_point] << endl;

	for (int i = 0; i < vertex_num; i++)
	{
		for (int j = 0; j < vertex_num; j++) {
			printf("%010d ", map[i][j]);
		}
		cout << endl;
	}
#endif

	for (int i = 0; i < vertex_num; i++) {
		int cur_min = MY_MAX;
		int u = -1;
		for (int j = 0; j < vertex_num; j++) {
			if (!visited[j] && distance[j] < cur_min) {
				u = j;
				cur_min = distance[j];
			}
		}
		if (u == -1)return 0;
		visited[u] = true;
		for (int k = 0; k < vertex_num; k++) {
			if (!visited[k] && distance[k]>distance[u] + map[u][k]) {
				distance[k] = distance[u] + map[u][k];
				pre[k].clear();
				pre[k].push_back(u);
			}
			else if (!visited[k] && distance[k] == distance[u] + map[u][k]
				) {
				pre[k].push_back(u);
			}
			else;
		}
	}
	dfs(start_point, end_point);
	cout << path_num << " " << optimal_value << endl;
}
