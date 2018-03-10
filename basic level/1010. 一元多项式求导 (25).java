设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为n*xn-1。）
输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。
输入样例：
3 4 -5 2 6 1 -2 0
输出样例：
12 3 -10 1 6 0




 链接：https://www.nowcoder.com/questionTerminal/2dae0a77c03e40c595881bc5d6074dfc
来源：牛客网

这道题就是个坑
第一个坑：数字之间可能有多个空格 如果你是用Java切割字符串的话
第二个坑：当系数项是0的时候输出 0 0  *如：3  4  -5  2  6  1  0  1  对应输出是12  3  -10  1  6  0  0 但是题目给出的输出是 12  3  -10  1  6  0

第三个坑：当系数项不是0，指数是0的时候   什么也不输出    *如：3  4  -5  2  6  1  -2  0  对应输出是12  3  -10  1  6  0  （-2  0没对应的数字输出）

第四个坑：当输出多项式是空串的时候要输出0 0  *如：输入只有 -2  0  的时候   输出空串  但是此时必须输出0  0



//读取一行，按空白字符分割scanner.nextLine().split("\\s+");
//string字符串处理的相关函数
import java.util.ArrayList;
import java.util.Scanner;

public class pat_1010 {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		ArrayList<Integer>input_number = new ArrayList<>();
		String[]str_numbers = scanner.nextLine().split("\\s+");
		for(int i=0;i<str_numbers.length;i++) {
			input_number.add(Integer.valueOf(str_numbers[i]));
		}
		scanner.close();
		String output = "";
		int first_num;
		int second_num;
		String new_first="";
		String new_second="";
		for(int i=0;i<input_number.size()-1;i=i+2) {
			first_num = input_number.get(i);
			second_num = input_number.get(i+1);

			if(first_num==0) {
				output += "0 0 ";
				continue;
			}

			if(first_num!=0&&second_num==0) {
				continue;
			}
			new_first = first_num*second_num+" ";
			new_second = second_num-1+" ";
			output = output + new_first + new_second;

		}

		if(output.length()>0&&" ".equals(output.charAt(output.length()-1)+"")) {
			output = output.substring(0, output.length()-1);
		}
		if(output=="") {
			System.out.println("0 0");
		}else {
			System.out.println(output);
		}



	}
}
