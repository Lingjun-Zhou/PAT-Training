
1015 Reversible Primes (20)

A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.
Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.
Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.
Output Specification:
For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.
Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
//进制转换，素数问题，vector

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
