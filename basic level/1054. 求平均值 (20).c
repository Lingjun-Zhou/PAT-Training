本题的基本要求非常简单：给定N个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是[-1000，1000]区间内的实数，并且最多精确到小数点后2位。当你计算平均值的时候，不能把那些非法的数据算在内。
输入格式：
输入第一行给出正整数N（<=100）。随后一行给出N个实数，数字间以一个空格分隔。
输出格式：
对每个非法输入，在一行中输出“ERROR: X is not a legal number”，其中X是输入。最后在一行中输出结果：“The average of K numbers is Y”，其中K是合法输入的个数，Y是它们的平均值，精确到小数点后2位。如果平均值无法计算，则用“Undefined”替换Y。如果K为1，则输出“The average of 1 number is Y”。
输入样例1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
输出样例1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
输入样例2：
2
aaa -9999
输出样例2：
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<sstream>
using namespace std;

//https://www.liuchuo.net/archives/617 sscanf和sprintf

#define MAX_VALID_LENGTH 7
#define PRECISION 2

bool check_valid(string cur_string) {

	//如果在非首位出现负号，为非合法字符串
	if (cur_string[0] == '-')
		cur_string = cur_string.substr(1, cur_string.size() - 1);
	if (cur_string.find('-') != -1)
		return false;
	//小数点, .25，000000.25合法
	int point_index = cur_string.find('.');
	if (point_index != -1 && cur_string.size() - point_index - 1 > PRECISION)
		return false;
	bool isNumber=true;
	for (int i = 0; i < cur_string.size(); i++) {
		if (i == point_index)
			continue;
		if (cur_string[i] >= '0'&&cur_string[i] <= '9')
			;
		else {
			isNumber = false;
			break;
		}

	}
	return isNumber;
}

//模板函数：将string类型变量转换为常用的数值类型
template <class Type>
Type stringToNum(const string& str) {
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

int main() {
	int num;
	//cout << check_valid("-000025") << endl;
	cin >> num;

	vector<string> all_strings;
	for (int i = 0; i < num; i++) {
		string cur_string;
		cin >> cur_string;
		all_strings.push_back(cur_string);
		}
	int counter = 0;
	double result=0;
	vector<string>::iterator it = all_strings.begin();
	for (; it < all_strings.end(); it++) {
		if (check_valid(*it)) {
			double num_value = stringToNum<double>(*it);
			if (num_value<=1000 && num_value>=-1000)
			{
				counter++;
				result += num_value;
			}
			else
				cout << "ERROR: " << (*it) << " is not a legal number" << endl;
		}
		else {
			cout << "ERROR: " << (*it) << " is not a legal number" << endl;
		}
	}

	if (counter == 0) {
		printf("The average of 0 numbers is Undefined");
	}
	else if (counter == 1) {
		printf("The average of 1 number is %.2lf", result);
	}
	else {
		printf("The average of %d numbers is %.2lf", counter, result / counter);
	}
}
