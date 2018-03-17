1034. Head of a Gang (30)
One way that the police finds the head of a gang is to check people''s phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.
Input Specification:
Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threshold, respectively. Then N lines follow, each in the following format:
Name1 Name2 Time
where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.
Output Specification:
For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.
Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0


#include<iostream>
#include<map>
#include<string>
//节点不是数字表示，多次用到map转换
//连通分支计算方法
using namespace std;
map<string, int>stringToInt;
map<int, string>intToString;
map<string, int> ans;
int idNumber = 1,threshold;
int graph[2001][2001];
int weight[2001];
bool isVisited[2001];
int stoiFunc(string s) {
	//map对于不存在的键值对，会根据该键值创建一个，其value为对应类型的默认值，这里是0；
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
