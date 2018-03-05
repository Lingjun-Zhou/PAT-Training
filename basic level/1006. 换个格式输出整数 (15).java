// 让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。
// 输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。
// 输出格式：每个测试用例的输出占一行，用规定的格式输出n。
// 输入样例1：
// 234
// 输出样例1：
// BBSSS1234
// 输入样例2：
// 23
// 输出样例2：
// SS123
import java.util.Scanner;

public class pat_1006 {
	public static void main(String[]args) {

		Scanner scanner = new Scanner(System.in);
		int input_number = scanner.nextInt();
		scanner.close();
		String strNum = "";
		int hundred_num;
		int dozen_num;
		int number;
		if(input_number >= 100) {
			hundred_num = input_number / 100;
			int hundred_temp = hundred_num;
			while(hundred_temp>0) {
				strNum += "B";
				hundred_temp--;
			}
			dozen_num = (input_number - hundred_num*100) / 10;
			int dozen_temp = dozen_num;
			while(dozen_temp>0) {
				strNum += "S";
				dozen_temp--;
			}
			number = input_number - hundred_num*100 - dozen_num*10;
			for(int i=1;i<=number;i++)
				strNum += Integer.toString(i);

		}else if(input_number >= 10){
			dozen_num = input_number / 10;
			int dozen_temp = dozen_num;
			while(dozen_temp>0) {
				strNum += "S";
				dozen_temp--;
			}
			number = input_number - dozen_num*10;
			for(int i=1;i<=number;i++)
				strNum += Integer.toString(i);
		}else {
			for(int i=1;i<=input_number;i++)
				strNum += Integer.toString(i);
		}

		System.out.println(strNum);
	}
}
