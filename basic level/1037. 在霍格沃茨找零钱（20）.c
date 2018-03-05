如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。
输入格式：
输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 107]区间内的整数，Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。
输出格式：
在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。
输入样例1：
10.16.27 14.1.28
输出样例1：
3.2.1
输入样例2：
14.1.28 10.16.27
输出样例2：
-3.2.1

#include<iostream>
using namespace std;
int main() {
	int A_Kunt, A_Sickle, A_Galleon;
	int P_Kunt, P_Sickle, P_Galleon;

	scanf_s("%d.%d.%d %d.%d.%d", &P_Galleon, &P_Sickle, &P_Kunt,
		&A_Galleon, &A_Sickle, &A_Kunt);

	int actual_cost = P_Galleon * 17 * 29+P_Sickle*29+P_Kunt;
	int actual_pay  = A_Galleon * 17 * 29 + A_Sickle * 29 + A_Kunt;
	int diff = abs(actual_pay - actual_cost);
	int R_Galleon = diff / (29 * 17);
	diff -= R_Galleon * 29 * 17;
	int R_Sickle = diff / 29;
	diff -= R_Sickle * 29;
	int R_Kunt = diff;

	if (actual_cost > actual_pay)
		printf("-%d.%d.%d", R_Galleon, R_Sickle, R_Kunt);
	else
		printf("%d.%d.%d", R_Galleon, R_Sickle, R_Kunt);


}
