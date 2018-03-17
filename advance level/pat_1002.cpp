#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

typedef struct {
	int exponent;
	float coefficient;
}Element;

void insertEle(vector<Element>&element , int num) {
	for (int i = 0; i < num; i++) {
		Element cur;
		cin >> cur.exponent >> cur.coefficient;
		element.push_back(cur);
	}
}

int cmp(Element ele1, Element ele2) {
	if (ele1.exponent > ele2.exponent)
		return 1;
	else if (ele1.exponent == ele2.exponent)
		return 0;
	else
		return -1;
}

void calcuEle(vector<Element>&element1, vector<Element>&element2, vector<Element>&result) {

	int i = 0, j = 0;
	while (i < element1.size() && j < element2.size()) {
		if (cmp(element1[i], element2[j]) == 1) {
			result.push_back(element1[i]);
			i++;
		}
		else if(cmp(element1[i], element2[j]) == 0){
			Element cur;
			cur.exponent = element1[i].exponent;
			cur.coefficient = element1[i].coefficient + element2[j].coefficient;
			if (cur.coefficient != 0)
				result.push_back(cur);
			i++; 
			j++;
		}
		else {
			result.push_back(element2[j]);
			j++;
		}
	}

	while (i < element1.size()) {
		result.push_back(element1[i]);
		i++;
	}

	while (j < element2.size()) {
		result.push_back(element2[j]);
		j++;
	}

}

int main() {
	vector<Element> element1;
	vector<Element>element2;
	vector<Element>result;
	int num1,num2;
	cin >> num1;
	insertEle(element1, num1);
	cin >> num2;
	insertEle(element2, num2);

	calcuEle(element1, element2, result);
	//cout << element1.size() <<" "<< element2.size() << endl;

	cout << result.size();
	for (int i = 0; i < result.size(); i++) {
		cout << " " << result[i].exponent;
		cout<<setiosflags(ios::fixed)<<setprecision(1)<< " " << result[i].coefficient;
	}
	


}