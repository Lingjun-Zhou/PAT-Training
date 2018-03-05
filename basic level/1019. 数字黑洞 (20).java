// 给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。
// 例如，我们从6767开始，将得到
// 7766 - 6677 = 1089
// 9810 - 0189 = 9621
// 9621 - 1269 = 8352
// 8532 - 2358 = 6174
// 7641 - 1467 = 6174
// ... ...
// 现给定任意4位正整数，请编写程序演示到达黑洞的过程。
// 输入格式：
// 输入给出一个(0, 10000)区间内的正整数N。
// 输出格式：
// 如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。
// 输入样例1：
// 6767
// 输出样例1：
// 7766 - 6677 = 1089
// 9810 - 0189 = 9621
// 9621 - 1269 = 8352
// 8532 - 2358 = 6174
// 输入样例2：
// 2222
// 输出样例2：
// 2222 - 2222 = 0000

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class pat_1019 {
	static ArrayList<Integer> numbers = new ArrayList<>();
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		String inputNumber = scanner.next();
		scanner.close();
		if(Integer.parseInt(inputNumber)<=0||Integer.parseInt(inputNumber)>=10000)
			return;
		for(int i=0;i<4;i++)
			numbers.add(0);

		do {
			inputNumber = processNumber(inputNumber);
		}while(!inputNumber.equals("6174")&&inputNumber!="");

	}

	private static String processNumber(String inputNumber) {
		if(inputNumber.matches("(\\d)\\1{3}")) {
			System.out.println(inputNumber + " - " + inputNumber + " = 0000");
			return "";
		}

		 if(inputNumber.length()<4){
	            int diff = 4-inputNumber.length();
				String zeros="";
				for(int n=0;n<diff;n++)
					zeros += "0";
				inputNumber = zeros + inputNumber;
	        }

		int i=0;
		String ascending_string="";
		String descending_string="";
		while(i!=4) {
			numbers.set(i, inputNumber.charAt(i)-'0');
			i++;
		}
		Collections.sort(numbers);
		for(Integer integer:numbers)
			ascending_string += integer;
		Collections.reverse(numbers);
		for(Integer integer:numbers)
			descending_string += integer;

		String nextNumber = Integer.parseInt(descending_string)-Integer.parseInt(ascending_string)+"";
		if(nextNumber.length()<4) {
			int diff = 4-nextNumber.length();
			String zeros="";
			for(int n=0;n<diff;n++)
				zeros += "0";
			nextNumber = zeros + nextNumber;
		}
		System.out.println(descending_string+" - "+ascending_string+" = "+nextNumber);
		return nextNumber;

	}

}
