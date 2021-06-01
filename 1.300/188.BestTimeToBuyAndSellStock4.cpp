#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//188. 买卖股票的最佳时机 IV
class BestTimeToBuyAndSellStock4
{
    /* 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
    注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
    */
public:
    int maxProfit(int k, vector<int>& prices) {
        //动态规划
        if (k == 0 || prices.empty())
            return 0;
        vector<int> buys(k, -prices[0]);
        vector<int> sells(k, 0);
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = k - 1; j > 0; --j) {
                sells[j] = max(sells[j], buys[j] + prices[i]);
                buys[j] = max(buys[j], sells[j - 1] - prices[i]);
            }
            sells[0] = max(sells[0], buys[0] + prices[i]);
            buys[0] = max(buys[0], -prices[i]);
        }
        return *max_element(sells.begin(), sells.end());
    }
};

int main(int argc, char const* argv[])
{
    BestTimeToBuyAndSellStock4 cls;
    cout << cls.maxProfit(2, vector<int>{2,4,1}) << " -> 2" << endl;
    cout << cls.maxProfit(2, vector<int>{3,2,6,5,0,3}) << " -> 7" << endl;
    return 0;
}
