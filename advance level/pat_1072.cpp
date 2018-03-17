#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<map>
#include<algorithm>
#include<iomanip>

//第一个待选加油站的节点编号为n+1，n为总共的房屋数
//这个图的总节点数为n+m，m为总共的待选加油站
using namespace std;
#define MAX_NODE 1011
#define INF 99999999
//#define DEBUG
int graph[MAX_NODE][MAX_NODE];
int dist[MAX_NODE];
bool isVisited[MAX_NODE];

map<string, int> gas_station;
double min_distance = 0;
int house_num, gas_num, edge_num, threshold, nodes_num;
int string2int(string s) {
	istringstream in(s);
	int x;
	in >> x;
	return x;
}
string int2string(int x) {
	stringstream os;
	os << x;
	return os.str();
}

int get_node_id(string s) {
	int id;
	string temp = s;
	if (s[0] == 'G') {
		s = s.substr(1);
		id = string2int(s)+house_num;
		if (gas_station[temp] == 0)
			gas_station[temp] = id;
	}
	else {
		id = string2int(s);
	}
	return id;
}


int Dijkstra(int start_point) {
	//初始化节点距离
	for (int i = 1; i <= nodes_num; i++)
		dist[i] = graph[start_point][i];

	//计算并更新dist[]
	for (int i = 1; i <= nodes_num; i++) {
		int u = -1, minn = INF;
		for (int j = 1; j <= nodes_num; j++) {
			if (!isVisited[j] && dist[j] < minn) {
				minn = dist[j];
				u = j;
			}
		}
		if (u == -1)return -1;
		isVisited[u] = true;
		for (int k = 1; k <= nodes_num; k++) {
			if (!isVisited[k] && graph[u][k] != INF&&dist[k]>dist[u] + graph[u][k]) {
				dist[k] = dist[u] + graph[u][k];
			}
		}
	}
	int cur_min = INF;
	for (int i = 1; i <= house_num; i++) {
		if (dist[i] > threshold) {
			return -1;
		}
		if (dist[i] < cur_min)
			cur_min = dist[i];
	}
	return cur_min;
}

int main() {

	cin >> house_num >> gas_num >> edge_num >> threshold;
	nodes_num = house_num + gas_num;
	//初始化图
	for (int i = 1; i <= nodes_num; i++) {
		for (int j = 1; j <= nodes_num; j++) {
			if (i == j)graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}
	for (int i = 0; i < edge_num; i++) {
		int id1, id2, distance;
		string s1, s2;
		cin >> s1 >> s2 >> distance;
		id1 = get_node_id(s1);
		id2 = get_node_id(s2);
		graph[id1][id2] = distance;
		graph[id2][id1] = distance;
	}

	string result;
	double sum;
	for (int i = 1; i <= gas_num;i++) {

		memset(isVisited, false, MAX_NODE);
		memset(dist, INF, MAX_NODE);

		string cur_station = "G" + int2string(i);
		int id = gas_station[cur_station];

		int cur_min =Dijkstra(id);
		if (cur_min == -1)
			continue;
		if (cur_min > min_distance) {
			sum = 0;
			min_distance = cur_min;
			result = cur_station;
			for (int i = 1; i <= house_num; i++)
				sum += dist[i];
		}
		else if (cur_min == min_distance) {
			double temp_sum = 0;
			for (int i = 1; i <= house_num; i++)
				temp_sum += dist[i];
			if (temp_sum < sum) {
				sum = temp_sum;
				result = cur_station;
			}
		}
		else;
	}

	if (result.empty())
		cout << "No Solution" << endl;
	else {
		cout << result << endl;
		cout << setiosflags(ios::fixed) << setprecision(1) << 1.0*min_distance << " " << sum*1.0 / house_num << endl;
	}
	return 0;
}
