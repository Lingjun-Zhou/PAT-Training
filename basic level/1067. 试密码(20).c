当你试图登录某个系统却忘了密码时，系统一般只会允许你尝试有限多次，当超出允许次数时，账号就会被锁死。本题就请你实现这个小功能。
输入格式：
输入在第一行给出一个密码（长度不超过20的、不包含空格、Tab、回车的非空字符串）和一个正整数N（<= 10），分别是正确的密码和系统允许尝试的次数。随后每行给出一个以回车结束的非空字符串，是用户尝试输入的密码。输入保证至少有一次尝试。当读到一行只有单个#字符时，输入结束，并且这一行不是用户的输入。
输出格式：
对用户的每个输入，如果是正确的密码且尝试次数不超过N，则在一行中输出“Welcome in”，并结束程序；如果是错误的，则在一行中按格式输出“Wrong password: 用户输入的错误密码”；当错误尝试达到N次时，再输出一行“Account locked”，并结束程序。
输入样例1：
Correct%pw 3
correct%pw
Correct@PW
whatisthepassword!
Correct%pw
#
输出样例1：
Wrong password: correct%pw
Wrong password: Correct@PW
Wrong password: whatisthepassword!
Account locked
输入样例2：
cool@gplt 3
coolman@gplt
coollady@gplt
cool@gplt
try again
#
输出样例2：
Wrong password: coolman@gplt
Wrong password: coollady@gplt
Welcome in

#include<iostream>
#include<string>
using namespace std;

//string的相等和char*调用strcmp判断相等不一样？
int main() {
	string corrret_pwd;
	int num_of_attempt;
	cin >> corrret_pwd;
	cin >> num_of_attempt;
	getchar();
	string cur_line;
	int attempt_count = 0;
	while (1) {
		getline(cin,cur_line);
		if (cur_line != "#")
			attempt_count++;
		else
			break;
		if ((cur_line== corrret_pwd) && attempt_count<=num_of_attempt ) {
			cout << "Welcome in" << endl;
			break;
		}
		else {
			cout << "Wrong password: " << cur_line << endl;
			if (attempt_count == num_of_attempt) {
				cout << "Account locked" << endl;
				break;
			}
		}
	}

}
