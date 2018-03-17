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
	//����ǰ�ڵ㵽���ڵ�֮������нڵ��itsFather������Ϊ���ڵ��ţ�����֮��Ĳ�ѯ����
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

int dfs(int s) {//������sΪ������ܵ����������
	int ans = 0;
	if (isVisited[s])return 0;
	isVisited[s] = true;
	int m = all_nodes[s].size();
	for (int i = 0; i < m; i++) {
		if (!isVisited[all_nodes[s][i]]) {//�Ƚϵ�ǰ������ĸ��ڵ��������
			int temp = dfs(all_nodes[s][i]);
			ans = ans > temp ? ans : temp;
		}
	}
	return ans + 1;//��ǰ��+���ڵ��е������ȣ����ǵ�ǰ�������������
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
			//һ�α����ͽ����е㶼�����ˣ����Կ�ʼÿ���µı���ǰ�轫isVisited��������
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