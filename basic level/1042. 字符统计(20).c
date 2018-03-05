请编写程序，找出一段给定文字中出现最频繁的那个英文字母。
输入格式：
输入在一行中给出一个长度不超过1000的字符串。字符串由ASCII码表中任意可见字符及空格组成，至少包含1个英文字母，以回车结束（回车不算在内）。
输出格式：
在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。
输入样例：
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
输出样例：
e 7

#include<iostream>
#include<string.h>
using namespace std;
int main() {
	int* char_total = new int[26];
	memset(char_total, 0, sizeof(int) * 26);
	char cur_char;
	int cur_index=0;
	while ((cur_char = getchar()) != '\n') {
		if (cur_char >= 'A'&&cur_char <= 'Z')
			cur_char = cur_char - 'A' + 'a';
		if (cur_char >= 'a'&&cur_char <= 'z') {
			cur_index = cur_char - 'a';
			char_total[cur_index]++;
		}
	}

	int max_index = 0;
	int max = 0;
	for (int i = 0; i < 26; i++) {
		if (max < char_total[i]) {
			max = char_total[i];
			max_index = i;
		}
	}
	char answer = 'a' + max_index;
	cout << answer << " " << max << endl;





}
