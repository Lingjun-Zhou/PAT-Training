1001.A+B Format(20)
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
Input
Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.
Sample Input
-1000000 9
Sample Output
-999,991
//字符串处理，int2string相互转换


#include<iostream>
#include<string>
#include<sstream>

using namespace std;
string int2str(int a) {
	ostringstream out;
	out << a;
	return out.str();
}
int main() {

	int a, b;
	cin >> a >> b;
	int sum = a + b;

	string output = int2str(sum);

	int length = output.size();

	for (int i = length-3; i >= 0; i -= 3) {
		if (i < 1)
			continue;
		if (output[0] == '-'&&i == 1)
			continue;
		output.insert(i, ",");
	}
	cout << output << endl;


}
