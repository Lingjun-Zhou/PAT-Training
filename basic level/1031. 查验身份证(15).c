一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：
首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；然后将计算的和对11取模得到值Z；最后按照以下关系对应Z值与校验码M的值：
Z：0 1 2 3 4 5 6 7 8 9 10
M：1 0 X 9 8 7 6 5 4 3 2
现在给定一些身份证号码，请你验证校验码的有效性，并输出有问题的号码。
输入格式：
输入第一行给出正整数N（<= 100）是输入的身份证号码的个数。随后N行，每行给出1个18位身份证号码。
输出格式：
按照输入的顺序每行输出1个有问题的身份证号码。这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。如果所有号码都正常，则输出“All passed”。
输入样例1：
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
输出样例1：
12010X198901011234
110108196711301866
37070419881216001X
输入样例2：
2
320124198808240056
110108196711301862
输出样例2：
All passed

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int main() {
	int num;
	cin >> num;
	vector<char*>id_str;
	for (int i = 0; i < num; i++) {
		char* cur_id_str=new char[19];
		cin >> cur_id_str;
		id_str.push_back(cur_id_str);
	}
	vector<char*>wrong_id_str;
	int weights[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char check_ch[] = { '1','0' ,'X' ,'9' ,'8' ,'7' ,'6' ,'5' ,'4' ,'3','2' };
	for (auto id : id_str) {
		int weight_sum=0;
		for (int i = 0; i < strlen(id); i++) {
			if (i == strlen(id) - 1) {

				int check_value = weight_sum % 11;
				if (check_value == 2 && id[i] != 'X') {
					wrong_id_str.push_back(id);
					continue;
				}
				if (id[i] != check_ch[check_value]) {
					wrong_id_str.push_back(id);
					continue;
				}
			}else {
				if (id[i] >= '0'&&id[i] <= '9') {
					weight_sum += (id[i] - '0')*weights[i];
				}else {
					wrong_id_str.push_back(id);
					break;
				}
			}
		}
	}

	//cout << endl;
	if (wrong_id_str.size() == 0) {
		cout << "All passed" << endl;
	}else {
		for (auto wrong_id : wrong_id_str)
			cout << wrong_id << endl;
	}


}
