#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//121. 买卖股票的最佳时机
class BestTimeToBuyAndSellStock
{
    /*给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
    */
public:
    int maxProfit(vector<int>& prices) {
        //双循环计算
        int size = prices.size();
        if(size < 2)
            return 0;
        //第一步 计算出当天买 之后能卖出的最大价
        vector<int> dp(size, 0);
        dp[size - 1] = prices[size-1];
        for(int i = size-2; i>=0;--i){
            dp[i] = max(dp[i+1], prices[i]);
        }
        //第二步 用卖价 - 买价 算 最大利润
        int ret = 0;
        for(int i = 0; i < size;++i){
            ret = max(ret, dp[i] - prices[i]);
        }
        return ret;
    }
public:
    int maxProfit2(vector<int>& prices) {
        //将双循环变成单循环
        int size = prices.size();
        if(size < 2)
            return 0;
        int ret = 0;
        for(int i = size-2; i>=0;--i){
            int sell = max(prices[i+1], prices[i]);
            ret = max(ret, sell - prices[i]);
            prices[i] = sell;
        }
        return ret;
    }
};

int main(int argc, char const* argv[])
{
    BestTimeToBuyAndSellStock cls;
    cout << cls.maxProfit2(vector<int>{7,1,5,3,6,4}) << " -> 5" << endl;
    cout << cls.maxProfit2(vector<int>{7,6,4,3,1}) << " -> 0" << endl;
    return 0;
}
