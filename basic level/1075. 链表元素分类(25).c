给定一个单链表，请编写程序将链表元素进行分类排列，使得所有负值元素都排在非负值元素的前面，而[0, K]区间内的元素都排在大于K的元素前面。但每一类内部元素的顺序是不能改变的。例如：给定链表为 18→7→-4→0→5→-6→10→11→-2，K为10，则输出应该为 -4→-6→-2→7→0→5→10→18→11。
输入格式：
每个输入包含1个测试用例。每个测试用例第1行给出：第1个结点的地址；结点总个数，即正整数N (<= 105)；以及正整数K (<=1000)。结点的地址是5位非负整数，NULL地址用-1表示。
接下来有N行，每行格式为：
Address Data Next
其中Address是结点地址；Data是该结点保存的数据，为[-105, 105]区间内的整数；Next是下一结点的地址。题目保证给出的链表不为空。
输出格式：
对每个测试用例，按链表从头到尾的顺序输出重排后的结果链表，其上每个结点占一行，格式与输入相同。
输入样例：
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
输出样例：
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1

#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

typedef struct {
	int address;
	int value;
	int next_address;
}node;

void print_node(node cur_node) {
	cout << setw(5) << setfill('0') << cur_node.address;
	cout << " " << cur_node.value << " ";
	if (cur_node.next_address == -1)
		cout << -1 << endl;
	else
		cout << setw(5) << setfill('0') << cur_node.next_address<<endl;
}

int main() {

	node* all_poss_nodes = new node[100000];

	//cout << sizeof(all_poss_nodes) << endl;


	int start_address,total_num,k;
	cin >> start_address >> total_num >> k;

	while (total_num--) {
		int cur_address,cur_value,next_address;
		cin >> cur_address >> cur_value >> next_address;
		all_poss_nodes[cur_address].address = cur_address;
		all_poss_nodes[cur_address].value = cur_value;
		all_poss_nodes[cur_address].next_address = next_address;
	}

	vector<node> link_nodes,first_class,second_class,third_class;
	node cur_node = all_poss_nodes[start_address];

	while (cur_node.next_address!=-1) {
		link_nodes.push_back(cur_node);
		cur_node = all_poss_nodes[cur_node.next_address];
	}
	link_nodes.push_back(cur_node);

	for (int i = 0; i < link_nodes.size(); i++) {
		if (link_nodes[i].value < 0)
			first_class.push_back(link_nodes[i]);
		else if (link_nodes[i].value >= 0 && link_nodes[i].value <= k)
			second_class.push_back(link_nodes[i]);
		else
			third_class.push_back(link_nodes[i]);
	}

	//cout << "===" <<first_class.size()<< endl;

	for (int i = 0; i < first_class.size(); i++) {
		if (i == first_class.size() - 1 && second_class.size()>0)
			first_class[i].next_address = second_class[0].address;
		else if (i == first_class.size() - 1 && second_class.size() == 0 && third_class.size()>0)
			first_class[i].next_address = third_class[0].address;
		else if (i == first_class.size() - 1 && second_class.size() == 0 && third_class.size() == 0)
			first_class[i].next_address = -1;
		else
			first_class[i].next_address = first_class[i + 1].address;

		print_node(first_class[i]);
	}

	for (int i = 0; i < second_class.size(); i++) {
		if (i == second_class.size() - 1 && third_class.size()>0)
			second_class[i].next_address = third_class[0].address;
		else if (i == second_class.size() - 1 && third_class.size() == 0)
			second_class[i].next_address = -1;
		else
			second_class[i].next_address = second_class[i + 1].address;
		print_node(second_class[i]);
	}

	for (int i = 0; i < third_class.size(); i++) {
		if (i == third_class.size() - 1)
			third_class[i].next_address = -1;
		else
			third_class[i].next_address = third_class[i + 1].address;

		print_node(third_class[i]);
	}



}
