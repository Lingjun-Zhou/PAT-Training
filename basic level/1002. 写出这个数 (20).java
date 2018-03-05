
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。
输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。
输入样例：
1234567890987654321123456789
输出样例：
yi san wu

import java.util.Scanner;

public class pat_1002 {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		String input_num = scanner.next();
		int num_sum = 0;
		for(int i=0;i<input_num.length();i++) {
			int num = Integer.valueOf(input_num.charAt(i)-'0');
			num_sum += num;
		}
		String num_sum_str = String.valueOf(num_sum);
		//System.out.println(num_sum_str);
		transferStr(num_sum_str);

	}
	private static String num2str(int num) {
		String append_str="";
		switch (num) {
		case 0:
			append_str = "ling";
			break;
		case 1:
			append_str = "yi";
			break;
		case 2:
			append_str = "er";
			break;
		case 3:
			append_str = "san";
			break;
		case 4:
			append_str = "si";
			break;
		case 5:
			append_str = "wu";
			break;
		case 6:
			append_str = "liu";
			break;
		case 7:
			append_str = "qi";
			break;
		case 8:
			append_str = "ba";
			break;
		case 9:
			append_str = "jiu";
			break;
		default:
			break;
		}
		return append_str;
	}

	private static String transferStr(String num_sum_str) {
		String sum_str = "";
		for(int i=0;i<num_sum_str.length();i++) {
			int num = Integer.valueOf(num_sum_str.charAt(i)-'0');
			String append_str = num2str(num);
			if(i != num_sum_str.length()-1) {
				sum_str =sum_str + append_str + " ";
			}else {
				sum_str += append_str;
			}
		}
		System.out.println(sum_str);
		return sum_str;

	}


}
