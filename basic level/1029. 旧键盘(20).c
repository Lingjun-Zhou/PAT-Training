旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。
输入格式：
输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过80个字符的串，由字母A-Z（包括大、小写）、数字0-9、以及下划线“_”（代表空格）组成。题目保证2个字符串均非空。
输出格式：
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有1个坏键。
输入样例：
7_This_is_a_test
_hs_s_a_es
输出样例：
7TI

(0.39)string的大小写转换，transform，::toupper
还可以用散列优化，让符合题意相同的字符只输出一次
用一个bool型数组HashTable[128]={false}（ASCII总共有128个）记录输出的情况

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	string original_input;
	string actual_input ;

	cin >> original_input;
	cin >> actual_input;

	transform(original_input.begin(), original_input.end(), original_input.begin(), ::toupper);
	transform(actual_input.begin(), actual_input.end(), actual_input.begin(), ::toupper);


	int actual_index = 0;
	vector<char>output;
	vector<char>::iterator it;

	for (int i = 0; i < original_input.length(); i++) {

		if (original_input.at(i) == actual_input.at(actual_index)) {
			if(actual_index!=actual_input.length()-1)
				actual_index++;
		}
		else
		{
			it = find(output.begin(), output.end(), original_input.at(i));
			if (it == output.end())
				output.push_back(original_input.at(i));

		}
	}
	for (it = output.begin(); it != output.end(); it++)
		cout << *it;

	cout << endl;
	//cout << original_input << endl;
	//cout << actual_input << endl;

}
