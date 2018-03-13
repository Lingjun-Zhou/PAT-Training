某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。
这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。
输入格式：
输入在第一行给出正整数N，取值在(0, 105]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。
输出格式：
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。
输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John

（0.20）字符串比较strcmp和sort排序

#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Person {
	char* name;
	char* birth_date;
};

bool cmp(const Person& a, const Person&   b) {
	return strcmp(a.birth_date, b.birth_date)>0?true:false;
}

int main() {
	int numOfPeople;
	cin >> numOfPeople;
	vector<Person> people;

	for (int i = 0; i < numOfPeople; i++) {
		char* name = (char*)malloc(20);
		char* birth_date = (char*)malloc(12);
		//scanf_s("%s", name);
		//scanf_s("%s", birth_date);
		cin >> name;
		cin >> birth_date;
		if (strcmp(birth_date, "2014/09/06") > 0 || strcmp(birth_date, "1814/09/06") < 0)
			continue;
		Person curPerson;
		curPerson.name = name;
		curPerson.birth_date = birth_date;
		people.push_back(curPerson);

	}
	int effective_num = people.size();


	sort(people.begin(), people.end(),cmp);
	if (effective_num > 0)
		cout << effective_num << " " << people[effective_num - 1].name << " " << people[0].name << endl;
	else
		cout << 0 << endl;


}
