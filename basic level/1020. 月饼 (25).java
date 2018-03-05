//
// 月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。
// 注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。
// 输入格式：
// 每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。
// 输出格式：
// 对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。
// 输入样例：
// 3 20
// 18 15 10
// 75 72 45
// 输出样例：
// 94.50
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.StringTokenizer;


//牛客网通过，pat没通过
public class pat_1020 {
	public static void main(String args[]) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());

		int numOfKinds = Integer.parseInt(stringTokenizer.nextToken());
		int numOfDemand = Integer.parseInt(stringTokenizer.nextToken());

		StringTokenizer stringTokenizer2 = new StringTokenizer(bufferedReader.readLine());
		StringTokenizer stringTokenizer3 = new StringTokenizer(bufferedReader.readLine());
		bufferedReader.close();

		int[] stocks = new int[numOfKinds];
		int[] totalPrices = new int[numOfKinds];
		HashMap<Integer, Double>average_price = new HashMap<>();
		double single_price;


		for(int i=0;i<numOfKinds;i++) {
			stocks[i] = Integer.parseInt(stringTokenizer2.nextToken());
			totalPrices[i] = Integer.parseInt(stringTokenizer3.nextToken());
			single_price = (double)totalPrices[i]/(double)stocks[i];
			average_price.put(i, single_price);
		}


		List<Map.Entry<Integer, Double>>list = new ArrayList<Map.Entry<Integer,Double>>(average_price.entrySet());
		Collections.sort(list,new Comparator<Map.Entry<Integer, Double>>() {

			@Override
			public int compare(Entry<Integer, Double> o1, Entry<Integer, Double> o2) {
				// TODO Auto-generated method stub
				return -(int) (o1.getValue().compareTo(o2.getValue()));
			}
		});

		/*
		for(Map.Entry<Integer, Double>mapping:list) {
			System.out.println(mapping.getKey()+"===>"+mapping.getValue());
		}
		*/

		int numOfRest = numOfDemand;
		double numOfMoney = 0;
		int index = 0;
		int curStockNum;
		while(numOfRest>0) {
			int cur_i = list.get(index).getKey();
			curStockNum = stocks[cur_i];
			if(numOfRest<= curStockNum) {

				numOfMoney =numOfMoney + (double)numOfRest * totalPrices[cur_i] / stocks[cur_i];
				numOfRest = 0;

			}else {
				numOfMoney += totalPrices[cur_i] ;
				numOfRest -= curStockNum;
				index++;
			}
		}

		DecimalFormat dFormat = new DecimalFormat("#.00");

		System.out.println(dFormat.format(numOfMoney));

	}
}
