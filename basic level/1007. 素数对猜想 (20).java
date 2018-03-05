// 让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
// 现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。
// 输入格式：每个测试输入包含1个测试用例，给出正整数N。
// 输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。
// 输入样例：
// 20
// 输出样例：
// 4
import java.util.ArrayList;
import java.util.Scanner;

public class pat_1007 {

	static ArrayList<Integer> primeNumbers = new ArrayList<>();

	public static void main(String[]args) {
		Scanner scanner = new Scanner(System.in);
		int max_num = scanner.nextInt();
		scanner.close();
		int prime_pair = 0;
		if(max_num>2) {
			for(int i=2;i<=max_num;i++) {
				if(isPrime(i)) {
					primeNumbers.add(i);
					//System.out.println(i);
				}
			}
		}

		for(int i=0;i<primeNumbers.size()-1;i++) {
			if(primeNumbers.get(i+1)-primeNumbers.get(i)==2)
				prime_pair++;
		}
		System.out.println(prime_pair);

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
