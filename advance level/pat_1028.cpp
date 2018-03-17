
1028 List Sorting (25)



#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
//scanf，printf的效率比cin，cout要高
//scanf不能处理string，要用cin
using namespace std;
struct Student {
	int id;
	string name;
	int score;
};

bool cmp1(Student s1, Student s2) {
	return s1.id < s2.id;
}
bool cmp2(Student s1, Student s2) {
	if (s1.name == s2.name)
		return s1.id < s2.id;
	return s1.name < s2.name;
}
bool cmp3(Student s1, Student s2) {
	if (s1.score == s2.score)
		return s1.id < s2.id;
	return s1.score < s2.score;
}

int main() {
	int num, flag;
	cin >> num >> flag;
	Student* all_student= new Student[num];
	for (int i = 0; i < num; i++) {
		scanf_s("%d", &all_student[i].id);
		cin >> all_student[i].name;
		scanf_s("%d", &all_student[i].score);
	//	cin >> all_student[i].id >> all_student[i].name >> all_student[i].score;
	}

	switch (flag)
	{
	case 1:
		sort(all_student, all_student+num, cmp1);
		break;
	case 2:
		sort(all_student, all_student + num, cmp2);
		break;
	case 3:
		sort(all_student, all_student + num, cmp3);
		break;
	default:
		break;
	}

	for (int i = 0; i < num; i++) {
		printf("%06d %s %d\n", all_student[i].id, all_student[i].name.c_str(), all_student[i].score);

	}


}
