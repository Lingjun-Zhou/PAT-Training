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