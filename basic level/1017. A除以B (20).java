// 本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。
// 输入格式：
// 输入在1行中依次给出A和B，中间以1空格分隔。
// 输出格式：
// 在1行中依次输出Q和R，中间以1空格分隔。
// 输入样例：
// 123456789050987654321 7
// 输出样例：
// 17636684150141093474 3

import java.math.BigInteger;
import java.util.Scanner;

public class pat_1017 {
	 public static void main(String args[])
	    {
	        Scanner cin=new Scanner(System.in);
	        BigInteger a,b,q,r;
	        while(cin.hasNext())
	        {
	            a=cin.nextBigInteger();
	            b=cin.nextBigInteger();
	            q=a.divide(b);
	            r=a.mod(b);
	            System.out.println(q+" "+r);
	        }
	        cin.close();
	    }
}
