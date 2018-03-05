根据维基百科的定义：
插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。
归并排序进行如下迭代操作：首先将原始序列看成N个只包含1个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下1个有序的序列。
现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？
输入格式：
输入在第一行给出正整数N (<=100)；随后一行给出原始序列的N个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。
输出格式：
首先在第1行中输出“Insertion Sort”表示插入排序、或“Merge Sort”表示归并排序；然后在第2行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行末不得有多余空格。

输入样例1：
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
输出样例1：
Insertion Sort
1 2 3 5 7 8 9 4 6 0
输入样例2：
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
输出样例2：
Merge Sort
1 2 3 8 4 5 7 9 0 6

#include<iostream>
#include<algorithm>
using namespace std;

bool isSame(int* numbers, int* sorted_numbers, int numOfArray) {
	int count = 0;
	for (int i = 0; i < numOfArray; i++) {
		if (numbers[i] == sorted_numbers[i])
			count++;
	}
	return count == numOfArray;
}


int main() {
	int numOfArray;
	cin >> numOfArray;
	int* unsorted_numbers = new int[numOfArray];
	int* sorted_numbers = new int[numOfArray];
	for (int i = 0; i < numOfArray; i++) {
		cin >> unsorted_numbers[i];
	}
	for (int i = 0; i < numOfArray; i++) {
		cin >> sorted_numbers[i];
	}
	//***find the start of disorder***
	int index1 = -1;
	for (int i = 1; i < numOfArray; i++) {
		if (sorted_numbers[i] < sorted_numbers[i - 1]) {
			index1 = i;
			break;
		}
	}

	bool isInsertion = true;
	for (int i = index1; i < numOfArray; i++) {
		if (sorted_numbers[i] != unsorted_numbers[i]) {
			isInsertion = false;
		}
	}

	//Insertion sort
	if (isInsertion) {
		cout << "Insertion Sort" << endl;
		sort(sorted_numbers, sorted_numbers + index1 + 1);
		for (int i = 0; i < numOfArray; i++) {
			if (i != numOfArray - 1)
				cout << sorted_numbers[i] << " ";
			else
				cout << sorted_numbers[i]<<endl;
		}
	}
	//Merge sort
	else {
		cout << "Merge Sort" << endl;
		int k = 1;
		bool flag = false;
		do {
			if (isSame(unsorted_numbers, sorted_numbers, numOfArray))
				flag = true;
			k *= 2;
			int i = 0;
			for (i = 0; i < numOfArray / k; i++)
				sort(unsorted_numbers + i*k, unsorted_numbers + (i + 1)*k);
			sort(unsorted_numbers + (numOfArray / k)*k, unsorted_numbers + numOfArray);
		} while (!flag);

		for (int i = 0; i < numOfArray; i++) {
			if (i != numOfArray - 1)
				cout << unsorted_numbers[i] << " ";
			else
				cout << unsorted_numbers[i] << endl;;
		}
	}
	return 0;
}
