著名的快速排序算法里有一个经典的划分过程：我们通常采用某种方法取一个元素作为主元，通过交换，把比主元小的元素放到它的左边，比主元大的元素放到它的右边。 给定划分后的N个互不相同的正整数的排列，请问有多少个元素可能是划分前选取的主元？
例如给定N = 5, 排列是1、3、2、4、5。则：

1的左边没有元素，右边的元素都比它大，所以它可能是主元；
尽管3的左边元素都比它小，但是它右边的2它小，所以它不能是主元；
尽管2的右边元素都比它大，但其左边的3比它大，所以它不能是主元；
类似原因，4和5都可能是主元。

因此，有3个元素可能是主元。
输入格式：
输入在第1行中给出一个正整数N（<= 105）； 第2行是空格分隔的N个不同的正整数，每个数不超过109。
输出格式：
在第1行中输出有可能是主元的元素个数；在第2行中按递增顺序输出这些元素，其间以1个空格分隔，行末不得有多余空格。
输入样例：
5
1 3 2 4 5
输出样例：
3
1 4 5

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//思路：对于每一个主元来说，它大于左边所有数中的最大值，小于右边所有数中的最小值
int main() {
	int num;
	cin >> num;
	bool* leftToR = new bool[num];
	int* numbers = new int[num];
	vector<int>pivot_numbers;
	cin >> numbers[0];
	int cur_max = numbers[0];
	leftToR[0] = true;
	//从左到右遍历
	for (int i = 1; i < num; i++) {
		cin >> numbers[i];
		if (numbers[i] > cur_max) {
			cur_max = numbers[i];
			leftToR[i] = true;
		}
		else
		{
			leftToR[i] = false;
		}
	}

	int cur_min = numbers[num - 1];
	for (int i = num - 1; i > -1; i--) {
		if (numbers[i] <= cur_min) {
			cur_min = numbers[i];
			if (leftToR[i]) {
				pivot_numbers.push_back(numbers[i]);
			}
		}
	}

	int pivot_num = pivot_numbers.size();
	cout << pivot_num << endl;
	sort(pivot_numbers.begin(), pivot_numbers.end());
	if (!pivot_numbers.size())
		cout << endl;
	else {
		for (int i = 0; i < pivot_num; i++) {
			if (i == pivot_num - 1)
				cout << pivot_numbers[i] << endl;
			else
				cout << pivot_numbers[i] << " ";
		}
	}

}
