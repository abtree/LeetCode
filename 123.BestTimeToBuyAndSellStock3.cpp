#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//123. 买卖股票的最佳时机 III
class BestTimeToBuyAndSellStock3
{
    /*给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
    */
public:
    int maxProfit(vector<int>& prices) {
        /*动态规划 需要分别考虑不购买 买卖一次 买卖2次的情况，不购买利润为0可不单独记录
        //边界条件
            buy1[0] = -prices[0];   //第一天买入
            sell1[0] = 0;           //第一天买入又卖出
            buy2[0] = -prices[0];   //第一天买入 卖出 又买入
            sell2[0] = 0;           //第一天买入 卖出 买入 卖出
        //递推公式
            buy1[i] = max(buy1[i-1], -prices[i]);   //之前已经买了，或者当天买入
            sell1[i] = max(sell1[i-1], buy1[i-1] + prices[i]);
            buy2[i] = max(buy2[i-1], sell1[i-1] - prices[i]);
            sell2[i] = max(sell2[i-1], buy2[i-1] + prices[i]);
        */
       int buy1 = -prices[0];
       int sell1 = 0;
       int buy2 = -prices[0];
       int sell2 = 0;
       for(int i = 1; i< prices.size(); ++i){
           sell2 = max(sell2, buy2 + prices[i]);
           buy2 = max(buy2, sell1 - prices[i]);
           sell1 = max(sell1, buy1 + prices[i]);
           buy1 = max(buy1, -prices[i]);
       }
       return max(sell1, sell2);
    }
};

int main(int argc, char const* argv[])
{
    BestTimeToBuyAndSellStock3 cls;
    cout << cls.maxProfit(vector<int>{3,3,5,0,0,3,1,4}) << " -> 6" << endl;
    cout << cls.maxProfit(vector<int>{1,2,3,4,5}) << " -> 4" << endl;
    cout << cls.maxProfit(vector<int>{7,6,4,3,1}) << " -> 0" << endl;
    cout << cls.maxProfit(vector<int>{1}) << " -> 0" << endl;
    return 0;
}
