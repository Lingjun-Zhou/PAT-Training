// 给定区间[-231, 231]内的3个整数A、B和C，请判断A+B是否大于C。
// 输入格式：
// 输入第1行给出正整数T(<=10)，是测试用例的个数。随后给出T组测试用例，每组占一行，顺序给出A、B和C。整数间以空格分隔。
// 输出格式：
// 对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）。
// 输入样例：
// 4
// 1 2 3
// 2 3 4
// 2147483647 0 2147483646
// 0 -2147483648 -2147483647
// 输出样例：
// Case #1: false
// Case #2: true
// Case #3: true
// Case #4: false

常见数据类型变量的scanf和printf格式
						scanf					printf
int					("%d",&n)			("%d",n)
long long		("%lld",&n)		("lld",n)
float				("%f",&fl)		("%f",fl)
double(*)		("%lf",&db)		("%f",db)
char				("%c",&c)			("%c",c)
字符串				("%s",str)		("%s",str)
(char数组)
import java.util.Scanner;

public class pat_1011 {
	public static void main(String args[]) {


		Scanner scanner = new Scanner(System.in);
		int numOfTests = scanner.nextInt();
		boolean[] replies = new boolean[numOfTests];
		long a,b,c;
		for(int i=0;i<numOfTests;i++) {
			a = scanner.nextLong();
			b = scanner.nextLong();
			c = scanner.nextLong();
			if(a+b > c)
				replies[i] = true;
			else
				replies[i] = false;
		}
		scanner.close();
		for(int i=0;i<numOfTests;i++) {
			System.out.println("Case #"+Integer.toString(i+1)+": "+replies[i]);
		}

	}
}
