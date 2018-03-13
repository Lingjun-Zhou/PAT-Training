/*
题目：
卡拉兹(Callatz)猜想：
对任何一个自然数n，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把(3n+1)砍掉一半。这样一直反复砍下去，最后一定在某一步得到n=1。卡拉兹在1950年的世界数学家大会上公布了这个猜想，传说当时耶鲁大学师生齐动员，拼命想证明这个貌似很傻很天真的命题，结果闹得学生们无心学业，一心只证(3n+1)，以至于有人说这是一个阴谋，卡拉兹是在蓄意延缓美国数学界教学与科研的进展……
我们今天的题目不是证明卡拉兹猜想，而是对给定的任一不超过1000的正整数n，简单地数一下，需要多少步（砍几下）才能得到n=1？
输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。
输出格式：输出从n计算到1需要的步数。
输入样例：
3
输出样例：
5
*/

判断奇偶数的简便方法：if(1&n)-->奇数，否则偶数

//编程语言：Java
import java.util.Scanner;
public class pat_1001 {
	static int oper_num =0;
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int input_number;
		if(scanner.hasNextInt()) {
			input_number = scanner.nextInt();
			if(input_number<1||input_number>1000) {
				System.out.println("Please input the right number between 1-1000");
			}

			Callatz(input_number);
			System.out.println(oper_num);
		}else {
			System.out.println("Please input the right number between 1-1000");
		}
		scanner.close();
	}
	private static int Callatz(int input_number) {

		if(input_number==1) {
			return oper_num;
		}

		if(input_number % 2 == 0) {
			input_number /= 2;
			oper_num += 1;
			Callatz(input_number);
		}else {
			input_number = input_number * 3 + 1;
			input_number /= 2;
			oper_num += 1;
			Callatz(input_number);
		}
		return oper_num;
	}
}
