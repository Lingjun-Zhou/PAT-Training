// 大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。
// 输入格式：
// 输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。
// 输出格式：
// 在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。
// 输入样例：
// 3485djDkxh4hhGE
// 2984akDfkkkkggEdsb
// s&hgsfdk
// d&Hyscvnm
// 输出样例：
// THU 14:04
import java.util.Scanner;

public class pat_1014 {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		String string1 = scanner.nextLine();
		String string2 = scanner.nextLine();
		String string3 = scanner.nextLine();
		String string4 = scanner.nextLine();
		scanner.close();
		String output = "";

		output += findDayAndHour(string1, string2);
		output += ":";
		int minute =  findMinute(string3, string4);
		if(minute<10)
			output =output + "0"+minute;
		else
			output += minute;
		System.out.println(output);


	}
	private static String findDayAndHour(String string1,String string2) {
		String day = "";
		int hour = 0;
		int count =0;
		int length = Math.min(string1.length(), string2.length());
		for(int i=0;i<length;i++) {
			if(string1.charAt(i)==string2.charAt(i)&&count==0&&
					string1.charAt(i)>='A'&&string1.charAt(i)<='G') {
				count = 1;
				int dayNum = string1.charAt(i);
				switch (dayNum) {
				case 'A':
					day = "MON";
					break;
				case 'B':
					day = "TUE";
					break;
				case 'C':
					day = "WED";
					break;
				case 'D':
					day = "THU";
					break;
				case 'E':
					day = "FRI";
					break;
				case 'F':
					day = "SAT";
					break;
				case 'G':
					day = "SUN";
					break;
				default:
					break;
				}
				i++;
			}

			if(count == 1 ) {
				if(string1.charAt(i)==string2.charAt(i)) {
					if(string1.charAt(i)>='0'&&string1.charAt(i)<='9') {
						hour = string1.charAt(i)-'0';
						day += " 0"+hour;
						break;
					}else if(string1.charAt(i)>='A'&&string1.charAt(i)<='N'){
						hour = string1.charAt(i)-'A'+10;
						day += " "+hour;
						break;
					}else {
						count = 1;
					}

				}
			}
		}
		return day;
	}

	private static int findMinute(String string1,String string2) {
		int minute = 0;
		int length = Math.min(string1.length(), string2.length());
		for(int i=0;i<length;i++) {
			if(string1.charAt(i)==string2.charAt(i)
					&&(
						(string1.charAt(i)>='a'&&string1.charAt(i)<='z')
						||
						(string1.charAt(i)>='A'&&string1.charAt(i)<='Z')
					)) {
				return i;
			}
		}
		return minute;
		
	}
}
