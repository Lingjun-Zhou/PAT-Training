// 输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。
// 输入格式：
// 输入在一行中依次给出3个整数A、B和D。
// 输出格式：
// 输出A+B的D进制数。
// 输入样例：
// 123 456 8
// 输出样例：
// 1103
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

import java.util.StringTokenizer;

public class pat_1022 {
	public static void main(String args[]) throws IOException {

		int ANum,BNum,DNum;

		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		String curLine = bufferedReader.readLine();
		bufferedReader.close();
		StringTokenizer stringTokenizer = new StringTokenizer(curLine);
		ANum = Integer.parseInt(stringTokenizer.nextToken());
		BNum = Integer.parseInt(stringTokenizer.nextToken());
		DNum = Integer.parseInt(stringTokenizer.nextToken());


		int sum = ANum +BNum;
		ArrayList<Integer> remainder = new ArrayList<>();
		while(sum!=0) {
			remainder.add(sum % DNum);
			sum = sum / DNum;
		}
		Collections.reverse(remainder);
		String output="";
		for(int i:remainder) {
			output += i;
		}
		if(output=="")
			output += 0;
		System.out.println(output);

	}

}
