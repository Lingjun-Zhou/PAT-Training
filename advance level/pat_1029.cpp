#include<iostream>

using namespace std;
long int seq1[1000001], seq2[1000001];
int main() {

	int seq1_num, seq2_num;
	cin >> seq1_num;
	for (int i = 0; i < seq1_num; i++)
		cin >> seq1[i];
	cin >> seq2_num;
	for (int i = 0; i < seq2_num; i++)
		cin >> seq2[i];

	int med_count = (seq1_num + seq2_num + 1) / 2;
	long int* result = new long int[med_count+1];
	int cnt = 0;
	int a=0, b=0;
	while (cnt < med_count&&a != seq1_num&&b != seq2_num) {
		if(seq1[a] > seq2[b]){
			result[cnt++] = seq2[b++];
		}
		else {
			result[cnt++] = seq1[a++];
		}
	}

	while (a == seq1_num&&cnt < med_count) {
		result[cnt++] = seq2[b++];
	}
	while (b == seq2_num&&cnt < med_count) {
		result[cnt++] = seq1[a++];
	}
	cout << result[cnt - 1];
}