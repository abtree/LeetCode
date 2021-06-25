#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//309. 最佳买卖股票时机含冷冻期
class BestTimeToBuyAndSellStockWithCooldown
{
    /* 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
    你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
    卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
    */
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
            return 0;
        vector<int> buy(prices.size(), 0);
        vector<int> sell(prices.size(), 0);
        buy[0] = -prices[0];
        sell[0] = 0;
        buy[1] = max(buy[0], -prices[1]);
        sell[1]= max(buy[0]+prices[1], 0);
        for (int i = 2; i<n;++i){
            sell[i] = max(buy[i-1]+prices[i], sell[i-1]);
            buy[i] = max(sell[i-2]-prices[i], buy[i-1]);
        }
        return max(buy[n-1], sell[n-1]);
    }
};

int main(int argc, char const *argv[]){
    BestTimeToBuyAndSellStockWithCooldown cls;
    cout << cls.maxProfit(vector<int>{1,2,3,0,2}) << " -> 3" << endl;
    return 0;
}