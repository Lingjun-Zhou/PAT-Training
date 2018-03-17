#include<iostream>
#include<map>
#include<string>
//�ڵ㲻�����ֱ�ʾ������õ�mapת��
//��ͨ��֧���㷽��
using namespace std;
map<string, int>stringToInt;
map<int, string>intToString;
map<string, int> ans;
int idNumber = 1,threshold;
int graph[2001][2001];
int weight[2001];
bool isVisited[2001];
int stoiFunc(string s) {
	//map���ڲ����ڵļ�ֵ�ԣ�����ݸü�ֵ����һ������valueΪ��Ӧ���͵�Ĭ��ֵ��������0��
	if (stringToInt[s] == 0) {
		stringToInt[s] = idNumber;
		intToString[idNumber] = s;
		return idNumber++;
	}
	else {
		return stringToInt[s];
	}
}

void dfs(int u, int &head, int &numMember, int &totalweight) {
	isVisited[u] = true;
	numMember++;
	if (weight[u] > weight[head])
		head = u;
	for (int v = 1; v < idNumber; v++) {
		if (graph[u][v]>0) {
			totalweight += graph[u][v];
			graph[u][v] = graph[v][u] = 0;
			if (!isVisited[v])
				dfs(v, head, numMember, totalweight);
		}
	}
}

int main() {
	int edge_num;
	cin >> edge_num >> threshold;
	string s1, s2;
	int w;
	for (int i = 0; i < edge_num; i++) {
		cin >> s1 >> s2 >> w;
		int id1 = stoiFunc(s1);
		int id2 = stoiFunc(s2);
		weight[id1] += w;
		weight[id2] += w;
		graph[id1][id2] += w;
		graph[id2][id1] += w;
	}

	for (int i = 1; i < idNumber; i++) {
		if (!isVisited[i]) {
			int head = i, numMember = 0, total_weight = 0;
			dfs(i, head, numMember, total_weight);
			if (numMember > 2 && total_weight > threshold)
				ans[intToString[head]] = numMember;
		}
	}

	cout << ans.size() << endl;
	for (auto it = ans.begin(); it != ans.end(); it++)
		cout << it->first << " " << it->second << endl;
	return 0;

}