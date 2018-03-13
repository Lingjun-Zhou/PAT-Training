// 正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
// 现给定A、DA、B、DB，请编写程序计算PA + PB。
// 输入格式：
// 输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
// 输出格式：
// 在一行中输出PA + PB的值。
// 输入样例1：
// 3862767 6 13530293 3
// 输出样例1：
// 399
// 输入样例2：
// 3862767 1 13530293 8
// 输出样例2：
// 0

BufferedReader进行数据读取, stringTokenizer进行分词

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class pat_1016 {
	public static void main(String args[]) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		String inputLine = bufferedReader.readLine();
		bufferedReader.close();
		StringTokenizer stringTokenizer = new StringTokenizer(inputLine);
		String A_num = stringTokenizer.nextToken();
		String DA_num = stringTokenizer.nextToken();
		String B_num = stringTokenizer.nextToken();
		String DB_num = stringTokenizer.nextToken();
		int PA_num = findPNum(A_num, DA_num);
		int PB_num = findPNum(B_num, DB_num);
		System.out.println(PA_num+PB_num);

	}
	private static int findPNum(String num,String D_num) {
		int p_num = 0;
		String p_String="";
		while(num.indexOf(D_num)!=-1) {
			p_String += D_num;
			num = num.replaceFirst(D_num, "");
		}
		if(p_String!="")
			p_num = Integer.parseInt(p_String);

		return p_num;
	}


}
