#include<iostream>

using namespace std;
#define UP_TIME 6
#define DOWN_TIME 4
#define STOP_TIME 5
int requests[100];
int main() {
	int requests_num;
	cin >> requests_num;
	for (int i = 0; i < requests_num; i++) {
		cin >> requests[i];
	}
	int cur = 0,pre=0;
	int result=0;
	for (int i = 0; i < requests_num; i++) {
		cur = requests[i];
		if (cur > pre)
			result += ((cur - pre)*UP_TIME + STOP_TIME);
		else
			result += ((pre - cur)*DOWN_TIME + STOP_TIME);
		pre = cur;
	}
	cout << result << endl;


}