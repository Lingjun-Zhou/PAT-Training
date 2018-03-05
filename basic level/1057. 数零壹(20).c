给定一串长度不超过105的字符串，本题要求你将其中所有英文字母的序号（字母a-z对应序号1-26，不分大小写）相加，得到整数N，然后再分析一下N的二进制表示中有多少0、多少1。例如给定字符串“PAT (Basic)”，其字母序号之和为：16+1+20+2+1+19+9+3=71，而71的二进制是1000111，即有3个0、4个1。
输入格式：
输入在一行中给出长度不超过105、以回车结束的字符串。
输出格式：
在一行中先后输出0的个数和1的个数，其间以空格分隔。
输入样例：
PAT (Basic)
输出样例：
3 4

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string input;
	getline(cin, input);
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	//cout << input << endl;
	int sum=0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'a'&&input[i] <= 'z')
			sum += input[i] - 'a'+1;
	}
	int num_of_one = 0, num_of_zero = 0;
	while (sum != 0) {
		if (sum % 2 == 1)
			num_of_one++;
		else
			num_of_zero++;
		sum = sum >> 1;
	}

	cout << num_of_zero<<" "<<num_of_one << endl;

}
