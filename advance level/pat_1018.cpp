1018 Public Bike Management (30)

There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.
The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.
When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.

Figure 1
Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S3, we have 2 different shortest paths:
1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.
2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.
Input Specification:
Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), the total number of stations; Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0->S1->...->Sp. Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.
Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judges data guarantee that such a path is unique.
Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0

//Dijkstra算法 + DFS,回溯法找最优解
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
