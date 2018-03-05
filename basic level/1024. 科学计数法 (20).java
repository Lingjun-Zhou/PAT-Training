// 科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。
// 现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。
// 输入格式：
// 每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。
// 输出格式：
// 对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。
// 输入样例1：
// +1.23400E-03
// 输出样例1：
// 0.00123400
// 输入样例2：
// -1.2E+10
// 输出样例2：
// -12000000000
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
//时间，内存超限
public class pat_1024 {
	public static void main(String args[]) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		String input = bufferedReader.readLine();
		bufferedReader.close();
		String symbol;
		if(input.charAt(0)=='-')
			symbol = "-";
		else
			symbol = "";
		int E_position = input.indexOf('E');
		String integer_part = input.substring(1, E_position);
		int integer_part_length = integer_part.length();
		int decimal_length = integer_part_length - 2;

		String expo_part = input.substring(E_position+1);
		int expo_num = Integer.parseInt(expo_part);

		String final_num_str;

		if(expo_num==0) {
			final_num_str = integer_part;
		}else if (expo_num>0) {
			if(expo_num>=decimal_length) {
				integer_part=integer_part.replace(".", "");
				while(expo_num-decimal_length>0) {
					integer_part += "0";
					expo_num--;
				}
				final_num_str = integer_part;
			}else {
				integer_part = integer_part.replace(".", "");
				StringBuilder stringBuilder = new StringBuilder(integer_part);
				stringBuilder.insert(1+expo_num, ".");
				final_num_str = stringBuilder.toString();

			}
		}else {
			int temp = -expo_num;
			integer_part = integer_part.replace(".", "");
			for(int i=0;i<temp-1;i++) {
				integer_part = "0" + integer_part;
			}
			final_num_str = "0."+integer_part;

		}



		System.out.println(symbol+final_num_str);

	}
}
