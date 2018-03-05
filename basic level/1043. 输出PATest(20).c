给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，直到所有字符都被输出。
输入格式：
输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。
输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。
输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

void printChar(int i) {
	switch (i)
	{
	case 0:
		cout<<'P';
		break;
	case 1:
		cout << 'A';
		break;
	case 2:
		cout << 'T';
		break;
	case 3:
		cout << 'e';
		break;
	case 4:
		cout << 's';
		break;
	case 5:
		cout << 't';
		break;
	default:
		break;
	}
}


int main() {
	int numOfChar[6];
	memset(numOfChar, 0, sizeof(int) * 6);

	char cur_char;
	while ((cur_char = getchar()) != '\n') {
		switch (cur_char)
		{
		case 'P':
			numOfChar[0]++;
			break;
		case 'A':
			numOfChar[1]++;
			break;
		case 'T':
			numOfChar[2]++;
			break;
		case 'e':
			numOfChar[3]++;
			break;
		case 's':
			numOfChar[4]++;
			break;
		case 't':
			numOfChar[5]++;
			break;
		default:
			break;
		}
	}

	int min = numOfChar[0];
	int max = numOfChar[0];
	for (int i = 1; i < 6; i++) {
		if (numOfChar[i] < min)
			min = numOfChar[i];
		if (numOfChar[i] > max)
			max = numOfChar[i];
	}
	int temp = min;
	while ((temp--)>0) {
		cout << "PATest";
	}

	for (int i = 0; i < 6; i++) {
		numOfChar[i] -= min;
	}

	while ((max--) > 0) {
		for (int i = 0; i < 6; i++) {
			if (numOfChar[i] > 0) {
				printChar(i);
				numOfChar[i]--;
			}
		}
	}
}
