#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
bool isPrime(int a) {
	if (a == 1)return false;
	for (int i = 2; i <= sqrt(a*1.0); i++) {
		if (a%i == 0)return false;
	}
	return true;
}

int getReverseNum(int num, int radix) {
	vector<int>all_numbers;
	while (num != 0) {
		all_numbers.push_back(num%radix);
		num /= radix;
	}
	int result = 0;
	for (int i = 0; i < all_numbers.size(); i++) {
		result = all_numbers[i] + result * radix;
	}
	return result;
}

int main() {
	int num, radix;
	cin >> num;
	while (num > 0) {
		cin >> radix;
		if (isPrime(num) && isPrime(getReverseNum(num, radix))) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		cin >> num;
	}
}