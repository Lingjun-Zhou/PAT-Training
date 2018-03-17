#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MY_MAX 1001

int isRoot[MY_MAX];
int itsFather[MY_MAX];

void init() {
	for (int i = 1; i < MY_MAX; i++) {
		itsFather[i] = i;
	}
}

int findFather(int a) {
	int z = a;
	while (itsFather[a] != a) {
		a = itsFather[a];
	}
	while (itsFather[z] != z) {
		int x = z;
		itsFather[x] = a;
		z = itsFather[z];
	}
	return a;
}

void Union(int a, int b) {
	int aFather = findFather(a);
	int bFather = findFather(b);
	if (aFather != bFather)
		itsFather[aFather] = bFather;
}

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int total_num;
	cin >> total_num;
	int hobbies[MY_MAX] = { 0 };
	init();
	
	for (int i = 1; i <= total_num; i++) {
		int cur_num;
		scanf_s("%d: ", &cur_num);
		for (int j = 0; j < cur_num; j++) {
			int cur_hobby_id;
			cin >> cur_hobby_id;
			if (hobbies[cur_hobby_id] == 0)
				hobbies[cur_hobby_id] = i;
			Union(i, findFather(hobbies[cur_hobby_id]));
		}
	}


	//isRoot数组存储的是以i为根节点的所有节点数量
	for (int i = 1; i <= total_num; i++)
		isRoot[findFather(i)]++;
	int count = 0;
	for (int i = 1; i <= total_num; i++) {
		if (isRoot[i] != 0)count++;
	}
	cout << count << endl;
	
	sort(isRoot, isRoot + MY_MAX, cmp);
	//cout << isRoot[0] << endl;
	for (int i = 0; i < count; i++)
		i == 0 ? cout << isRoot[i] : cout << " " << isRoot[i];
	
}