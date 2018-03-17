#include<iostream>
#include<vector>
using namespace std;
#define MAX_N 501
#define INF	999999
int bikesInStation[MAX_N];
int graph[MAX_N][MAX_N];
int dist[MAX_N];
bool isVisited[MAX_N];
int perfect_num;
vector<vector<int>> pre;
vector<int>path, temp_path;
int minNeed = INF, minBack = INF;

void print_path(vector<int>path) {
	for (int i = path.size() - 1; i >= 0; i--) {
		if (i == path.size() - 1)
			cout << path[i];
		else
			cout << "->"<<path[i];
	}
}
void dfs(int target_point) {
	//temp_path其实是用来回溯的，走完所有可能路径，temp_path归于空白的状态
	temp_path.push_back(target_point);
	if (target_point == 0) {
		int need = 0, back = 0;
		for (int i = temp_path.size() - 1; i >= 0; i--) {
			int id = temp_path[i];
			if (bikesInStation[id] > 0) {
				back += bikesInStation[id];
			}
			else {
				if (back > (0 - bikesInStation[id])) {
					back += bikesInStation[id];
				}
				else {
					need += ((0 - bikesInStation[id]) - back);
					back = 0;
				}
			}
		}
		if (need < minNeed) {
			minNeed = need;
			minBack = back;
			path = temp_path;
		}
		else if (need == minNeed && back < minBack) {
			minBack = back;
			path = temp_path;
		}

		temp_path.pop_back();
		return;
	}

	for (int i = 0; i < pre[target_point].size(); i++)
		dfs(pre[target_point][i]);
	temp_path.pop_back();

}

int main() {
	int full_num, total_num, target_num, edge_num;
	cin >> full_num >> total_num >> target_num >> edge_num;
	perfect_num = full_num / 2;
	//初始化每一个节点的前一个节点
	pre.resize(total_num+1 );
	//初始化节点权重
	for (int i = 1; i <= total_num; i++) {
		int bikes;
		cin >> bikes;
		bikesInStation[i] = bikes-perfect_num;
	}
	//初始化边权重
	for (int i = 0; i <= total_num; i++) {
		for (int j = 0; j <= total_num; j++) {
			if (i == j)graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}
	for (int i = 0; i < edge_num; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	//初始化距离
	for (int i = 0; i < MAX_N; i++)
		dist[i] = graph[0][i];
	//Dijkstra计算出最短路径
	for (int i = 0; i <= total_num; i++) {
		int u = -1, minn = INF;
		for (int j = 0; j <= total_num; j++) {
			if (isVisited[j] == false && dist[j] < minn) {
				u = j;
				minn = dist[j];
			}
		}
		//u==-1说明该点与起点不连通，距离为INF
		if (u == -1)break;
		isVisited[u] = true;
		for (int k = 0; k <= total_num; k++) {
			if (!isVisited[k] && graph[u][k]!=INF &&  dist[k] > dist[u] + graph[u][k]) {
				pre[k].clear();
				pre[k].push_back(u);
				dist[k] = dist[u] + graph[u][k]; //优化dist[]
			}
			else if (!isVisited[k] && graph[u][k] != INF &&  dist[k] == dist[u] + graph[u][k]) {
				pre[k].push_back(u);
			}
			else
				;
		}
	}
	//获得最短路径长度

	int shortest_path_length = dist[target_num];
	dfs(target_num);

	printf("%d ", minNeed);
	print_path(path);
	printf(" %d", minBack);
	//cout << "==" << temp_path.size() << endl;
	return 0;
	
}


