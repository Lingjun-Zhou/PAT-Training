
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
得到“答案正确”的条件是：
1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。
输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。
输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO

//有题意可得出满足条件的字符串为：A*PA+TA*，其中P之前的A的个数*P和T之间A的个数=T之后A的个数
//了解Scanner的用法，简单低效
import java.util.Scanner;
public class pat_1003 {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int num_of_string = scanner.nextInt();
		String[] strings = new String[num_of_string];
		String[] answers = new String[num_of_string];

		for(int i=0;i<num_of_string;i++) {
			strings[i] = scanner.next();
			answers[i] = checkString(strings[i]);
		}
		for(int i=0;i<num_of_string;i++) {
			System.out.println(answers[i]);
		}
	}
	private static String checkString(String string) {

		String answer = "NO";
		if(string.matches("A*PA+TA*")) {
			int indexOfP = string.indexOf("P");
			int indexOfT = string.indexOf("T");
			if(indexOfP*(indexOfT-indexOfP-1) == (string.length()-1-indexOfT)) {
				answer =  "YES";
			}
		}
		return answer;
	}
}
