地球人习惯使用十进制数，并且默认一个数字的每一位都是十进制的。而在PAT星人开挂的世界里，每个数字的每一位都是不同进制的，这种神奇的数字称为“PAT数”。每个PAT星人都必须熟记各位数字的进制表，例如“……0527”就表示最低位是7进制数、第2位是2进制数、第3位是5进制数、第4位是10进制数，等等。每一位的进制d或者是0（表示十进制）、或者是[2，9]区间内的整数。理论上这个进制表应该包含无穷多位数字，但从实际应用出发，PAT星人通常只需要记住前20位就够用了，以后各位默认为10进制。
在这样的数字系统中，即使是简单的加法运算也变得不简单。例如对应进制表“0527”，该如何计算“6203+415”呢？我们得首先计算最低位：3+5=8；因为最低位是7进制的，所以我们得到1和1个进位。第2位是：0+1+1（进位）=2；因为此位是2进制的，所以我们得到0和1个进位。第3位是：2+4+1（进位）=7；因为此位是5进制的，所以我们得到2和1个进位。第4位是：6+1（进位）=7；因为此位是10进制的，所以我们就得到7。最后我们得到：6203+415=7201。
输入格式：
输入首先在第一行给出一个N位的进制表（0 < N <=20），以回车结束。 随后两行，每行给出一个不超过N位的非负的PAT数。
输出格式：
在一行中输出两个PAT数之和。
输入样例：
30527
06203
415
输出样例：
7201

#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main() {
	string table_num;
	cin >> table_num;
	string first_num;
	cin >> first_num;
	int first_length = first_num.size();
	string second_num;
	cin >> second_num;
	int second_length = second_num.size();

	if (first_length < second_length) {
		first_num.insert(0, second_length - first_length, '0');
	}
	else {
		second_num.insert(0, first_length - second_length, '0');
	}

	int table_length = table_num.size();
	int total_length = first_num.size();
	vector<int>result;
	int cnt = 0;
	bool plus_one = false;
	for (int i = total_length - 1; i >= 0; i--) {
		cnt++;
		int sum = first_num[i] - '0' + second_num[i] - '0';
		if (plus_one)
			sum++;
		if (cnt <= 20) {
			int k = table_num[table_length - cnt] - '0';
			if (k == 0) {
				result.push_back(sum % 10);
				if (sum >= 10)
					plus_one = true;
				else
					plus_one = false;
			}
			else {
				result.push_back(sum%k);
				if (sum >= k)
					plus_one = true;
				else
					plus_one = false;
			}
		}
		else {
			result.push_back(sum % 10);
			if (sum >= 10)
				plus_one = true;
			else
				plus_one = false;
		}
	}
	if (plus_one)
		result.push_back(1);

	vector<int>::reverse_iterator it = result.rbegin();
	bool flag = true;
	for (; it != result.rend(); it++) {
		if (flag&&*it == 0) {
			continue;
		}
		else {
			flag = false;
		}
		cout << *it;
	}

	//测试点5,000+0000=0
	int i = 0;
	while (result[i] == 0&&i<result.size()) {
		i++;
	}
	if(i==result.size())
		cout<< 0;

}
