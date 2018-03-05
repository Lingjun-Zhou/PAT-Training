// 令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。
// 输入格式：
// 输入在一行中给出M和N，其间以空格分隔。
// 输出格式：
// 输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。
// 输入样例：
// 5 27
// 输出样例：
// 11 13 17 19 23 29 31 37 41 43
// 47 53 59 61 67 71 73 79 83 89
// 97 101 103

import java.util.ArrayList;
import java.util.Scanner;
//超时一个测试点
public class pat_1013 {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int min = scanner.nextInt();
		int max = scanner.nextInt();
		int count = 0;
		scanner.close();
		ArrayList<Integer>output = new ArrayList<>();

		for(int i=2;;i++) {
			if(isPrime(i)) {
				count ++;
				if(count>=min)
					output.add(i);
				if(count>=max)
					break;
			}
		}

		String output_str="";
		for (int i=0;i<output.size();i++) {
			output_str += output.get(i);
			if((i+1)%10 == 0)
				output_str += "\n";
			else {
				output_str += " ";
			}
		}
		if(" ".equals(output_str.charAt(output_str.length()-1)+""))
			output_str = output_str.substring(0, output_str.length()-1);
		System.out.print(output_str);
	}

	private static boolean isPrime(int number) {
		if(number==2)
			return true;
		for(int i=2;i<=Math.sqrt(number);i++) {
			if(number % i == 0)
				return false;
		}
		return true;
	}
}
