
卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。
当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。
现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。
输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。
输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。
输入样例：
6
3 5 6 7 8 11
输出样例：
7 6

//Collections.sort,.reverse
//静态全局变量，static HashMap,ArrayList
import java.util.ArrayList;

import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class pat_1005 {

	static HashMap<Integer, Integer>visitedNumber = new HashMap<>();
	static ArrayList<Integer>keyNumbers = new ArrayList<>();

	public static void main(String args[]) {

		Scanner scanner = new Scanner(System.in);
		int numOfArray = scanner.nextInt();

		for(int i=0;i<numOfArray;i++) {
			int curNum = scanner.nextInt();
			keyNumbers.add(curNum);
			Callatz(curNum);
		}
		scanner.close();
		String output="";
		Collections.sort(keyNumbers);
		Collections.reverse(keyNumbers);

		for(int i=0;i<keyNumbers.size();i++) {
			output += keyNumbers.get(i).toString();
			if(i != keyNumbers.size()-1) {
				output += " ";
			}
		}

		System.out.println(output);

	}

	public static int Callatz(int input_number) {


		int operNum ;
		if(visitedNumber.containsKey(input_number)) {
			if(keyNumbers.contains(input_number)) {
				keyNumbers.remove(keyNumbers.indexOf(input_number));
			}
			return visitedNumber.get(input_number);
		}

		if(input_number==1) {
			operNum = 0;
			visitedNumber.put(input_number, operNum);
			//System.out.println(input_number+"==>"+operNum);
			return operNum;
		}
		int temp;
		if(input_number % 2 == 0) {
			temp = input_number / 2;
		}else {
			temp = input_number * 3 + 1;
			temp /= 2;
		}
		operNum = 1 + Callatz(temp);
		visitedNumber.put(input_number, operNum);
		//System.out.println(input_number+"==>"+operNum);
		return operNum;

	}
}
