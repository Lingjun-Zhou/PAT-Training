本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。
输入格式：
输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。
输出格式：
在一行中输出加密后的结果。
输入样例：
1234567 368782971
输出样例：
3695Q8118

#include<iostream>
#include<string.h>
using namespace std;

//字符串b长度小于字符串a时，要在b前面补0
int main() {
	char* string_a = new char[100];
	char* string_b = new char[100];
	cin >> string_a;
	cin >> string_b;
	int a_length = strlen(string_a);
	int b_length = strlen(string_b);
	if (a_length > b_length) {
		int diff = a_length - b_length;
		char* zeros = new char[100];
		for (int i = 0; i < diff; i++)
			zeros[i] = '0';
		zeros[diff] = '\0';
		b_length = a_length;
		strcat_s(zeros, sizeof(int)*strlen(string_b), string_b);
		//strcat_s(zeros, string_a);
		string_b = zeros;
	}
	cout << string_a<<" " <<b_length << endl;
	char* result = new char[b_length];

	bool isOdd = true;
	for (int i = 1; i < b_length+1;i++) {
		if (i > a_length) {
			result[b_length - i] = string_b[b_length - i];
			continue;
		}
		if (isOdd) {
			int num_value = (string_a[a_length - i] - '0' + string_b[b_length - i] - '0') % 13;
			char ch_value;
			switch (num_value)
			{
			case 10:
				ch_value = 'J';
				break;
			case 11:
				ch_value = 'Q';
				break;
			case 12:
				ch_value = 'K';
				break;
			default:
				ch_value = num_value + '0';
				break;
			}
			result[b_length - i] = ch_value;
		}
		else {
			int num_value = string_b[b_length - i] - string_a[a_length - i];
			if (num_value < 0)
				num_value += 10;
			result[b_length - i] = num_value + '0';
		}
		isOdd = !isOdd;

	}
	result[b_length] = '\0';
	cout <<  result << endl;
}
