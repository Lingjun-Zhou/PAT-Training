// 大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
//
// 现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
// 输入格式：
// 输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
// 输出格式：
// 输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。
// 输入样例：
// 10
// C J
// J B
// C B
// B B
// B C
// C C
// C B
// J B
// B C
// J J
// 输出样例：
// 5 3 2
// 2 3 5
// B B
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

//chao shi
public class pat_1018 {
  static ArrayList<Character> operationAWin = new ArrayList<>();
  static ArrayList<Character> operationBWin = new ArrayList<>();
  static int numOfAWin=0;
  static int numOfBWin=0;
  static int numOfTie=0;
  public static void main(String args[]) throws NumberFormatException, IOException {

    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    int numOfGame = Integer.parseInt(bufferedReader.readLine());

    char Aoperation;
    char Boperation;
    String[] curItem;
    for(int i=0;i<numOfGame;i++) {
      curItem = bufferedReader.readLine().split(" ");
      Aoperation = curItem[0].charAt(0);
      Boperation = curItem[1].charAt(0);
      playGame(Aoperation, Boperation);
    }


    char AMostOpertion = findMostOpertion(operationAWin);
    char BMostOprtation = findMostOpertion(operationBWin);

    System.out.println(numOfAWin+" "+numOfTie+" "+numOfBWin);
    System.out.println(numOfBWin+" "+numOfTie+" "+numOfAWin);
    System.out.println(AMostOpertion+" "+BMostOprtation);

  }
  private static void playGame(char a,char b) {
    if(a=='C'&&b=='J') {
      numOfAWin ++;
      operationAWin.add('C');
    }
    else if(a=='C'&&b=='B') {
      numOfBWin ++;
      operationBWin.add('B');
    }
    else if (a=='J'&&b=='C') {
      numOfBWin ++;
      operationBWin.add('C');
    }else if (a=='J'&&b=='B') {
      numOfAWin ++;
      operationAWin.add('J');
    }else if (a=='B'&&b=='C') {
      numOfAWin ++;
      operationAWin.add('B');
    }else if (a=='B'&&b=='J') {
      numOfBWin ++;
      operationBWin.add('J');
    }else {
      numOfTie++;
    }

  }

  private static char findMostOpertion(ArrayList<Character>operationWin) {
    int numOfC=0,numOfJ=0,numOfB=0;
    for(Character c:operationWin) {
      if(c.equals('C')) {
        numOfC++;
      }else if(c.equals('J')){
        numOfJ++;
      }else {
        numOfB++;
      }
    }
    int maxNum = Math.max(numOfB, Math.max(numOfC, numOfJ));
    if(numOfB>=maxNum)
      return 'B';
    if(numOfC>=maxNum)
      return 'C';
    if(numOfJ>=maxNum)
      return 'J';

    return 'B';

  }

}
