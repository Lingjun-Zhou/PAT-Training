萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：
[左手]([左眼][口][右眼])[右手]
现给出可选用的符号集合，请你按用户的要求输出表情。
输入格式：
输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号[]内。题目保证每个集合都至少有一个符号，并不超过10个符号；每个符号包含1到4个非空字符。
之后一行给出一个正整数K，为用户请求的个数。随后K行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从1开始），数字间以空格分隔。
输出格式：
对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出“Are you kidding me? @\/@”。
输入样例：
[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
输出样例：
╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@


#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
//scanf的正则表达式总结：https://yq.aliyun.com/articles/53552
//vector遍历的犯法
int main() {
	vector<vector<string>> v;

	for (int i = 0; i < 3; i++) {
		string cur_string;
		getline(cin, cur_string);
		vector<string>cur_strings;
		int start = 0, stop = 0;
		while (start < cur_string.length()) {
			if (cur_string[start] == '[') {
				while (stop < cur_string.length()) {
					if (cur_string[stop] == ']') {
						cur_strings.push_back(cur_string.substr(start + 1, stop - start - 1));
						start = stop++;
						break;
					}
					stop++;
				}

			}
			else
				start++;
		}
		v.push_back(cur_strings);
	}

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		if (a > v[0].size() || b>v[1].size() || c > v[2].size() || d > v[1].size() || e > v[0].size() ||
			a < 1 || b< 1 || c < 1 || d < 1 || e < 1) {
			cout << "Are you kidding me? @\\/@" << endl;
			continue;
		}

		cout << v[0][a - 1] << "(" << v[1][b - 1] << v[2][c - 1] << v[1][d - 1] << ")" << v[0][e - 1] << endl;

	}

	//for (int i = 0; i < v[2].size(); i++)
	//  cout << v[2][i] << endl;

	//vector<string>::iterator it = v[0].begin();
	//for (; it != v[0].end(); ++it)
	//  cout << *it << endl;
	return 0;

}
