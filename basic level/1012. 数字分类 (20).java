// 给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
// A1 = 能被5整除的数字中所有偶数的和；
// A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
// A3 = 被5除后余2的数字的个数；
// A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
// A5 = 被5除后余4的数字中最大数字。
// 输入格式：
// 每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。
// 输出格式：
// 对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
// 若其中某一类数字不存在，则在相应位置输出“N”。
// 输入样例1：
// 13 1 2 3 4 5 6 7 8 9 10 20 16 18
// 输出样例1：
// 30 11 2 9.7 9
// 输入样例2：
// 8 1 2 4 5 6 7 9 16
// 输出样例2：
// N 11 2 N 9

scanner分割字符串，split（“\\s+”)
格式化输出，scanner分割字符串，split（“\\s+”)
格式化输出，DecimalFormat

0：
    比实际数字的位数多，不足的地方用0补上。
    比实际数字的位数少：整数部分不改动，小数部分，四舍五入
#：
    比实际数字的位数多，不变。
    比实际数字的位数少：整数部分不改动，小数部分，四舍五入

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;
//超时一个测试点
public class pat_1012 {
  public static void main(String args[]) {
    Scanner scanner  = new Scanner(System.in);
    String A1,A2,A3,A4,A5;

    int A1_num = 0;
    ArrayList<Integer>A2_array = new ArrayList<>();
    int A3_num=0;
    double A4_num = 0.0;
    int A4Times=0;
    int A5_num=0;

    String[] numOfstr = scanner.nextLine().split("\\s+");

    scanner.close();
    int num = Integer.valueOf(numOfstr[0]);
    int curNum,option;
    for(int i=0;i<num;i++) {
      curNum = Integer.valueOf(numOfstr[i+1]);
      option = curNum % 5;
      switch (option) {
      case 0:
        if(curNum%2==0)
          A1_num += curNum;
        break;
      case 1:
        A2_array.add(curNum);
        break;
      case 2:
        A3_num++;
        break;
      case 3:
        A4_num += curNum;
        A4Times++;
        break;
      case 4:
        if(curNum>A5_num)
          A5_num = curNum;
        break;
      default:
        break;
      }
    }
    if(A1_num!=0) {
      A1 = Integer.toString(A1_num);
    }else {
      A1 = "N";
    }

    if(!A2_array.isEmpty()) {
      int sum2 = 0;
      for(int i=0;i<A2_array.size();i++) {
        if(i%2 == 0)
          sum2 += A2_array.get(i);
        else
          sum2 -= A2_array.get(i);
      }
      A2 = Integer.toString(sum2);
    }else {
      A2 = "N";
    }

    if(A3_num!=0)
      A3 = Integer.toString(A3_num);
    else
      A3 = "N";

    if(A4_num!=0) {
      A4_num /= A4Times;
      DecimalFormat df = new DecimalFormat("#.0");
      A4 = df.format(A4_num);
    }else {
      A4 = "N";
    }

    if(A5_num!=0) {
      A5 = Integer.toString(A5_num);
    }else {
      A5 = "N";
    }

    System.out.println(A1 + " " + A2 + " " + A3 + " " + A4 + " " + A5);

  }
}
