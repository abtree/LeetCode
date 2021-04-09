#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//122. 买卖股票的最佳时机 II
class BestTimeToBuyAndSellStock2
{
    /*给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
    */
public:
    int maxProfit(vector<int>& prices) {
        /* 动态规划 dp0[i]表示i天不持有股票的利润 dp1[i]表示i天持有股票的利润
        边界条件：dp0[0] = 0;dp1[0] = -prices[0]
        推导方程: dp0[i] = max(dp0[i-1], dp1[i-1] + prices[i])
                 dp1[i] = max(dp1[i-1], dp0[i-1] - prices[i])
        这里要注意的是，只有买和卖才能造成利润变化，如果这一天没有买与卖，利润与上一天相同
        */
       int size = prices.size();
       int dp0 = 0;
       int dp1 = -prices[0];
       for(int i = 1;i < size;++i){
           int ndp0 = max(dp0, dp1 + prices[i]);
           dp1 = max(dp1, dp0 - prices[i]);
           dp0 = ndp0;
       }
       return dp0;
    }
};

int main(int argc, char const* argv[])
{
    BestTimeToBuyAndSellStock2 cls;
    cout << cls.maxProfit(vector<int>{7,1,5,3,6,4}) << " -> 7" << endl;
    cout << cls.maxProfit(vector<int>{1,2,3,4,5}) << " -> 4" << endl;
    cout << cls.maxProfit(vector<int>{7,6,4,3,1}) << " -> 0" << endl;
    return 0;
}
