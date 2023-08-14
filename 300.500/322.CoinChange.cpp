#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// 322. 零钱兑换
class CoinChange {
    /* 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
    计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
    你可以认为每种硬币的数量是无限的。
    */
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        //层序遍历(会超时)
        queue<int> q;
        q.push(0);
        int ret = 0;
        unordered_set<int> repeated;
        while (!q.empty()) {
            int size = q.size();
            ++ret;
            for (int i = 0; i < size; ++i) {
                int cur = q.front();
                q.pop();
                for (int c : coins) {
                    c += cur;
                    if (repeated.find(c) != repeated.end())
                        continue;   //重复
                    if (c < amount) {
                        repeated.insert(c);
                        q.push(c);
                    }
                    else if (c == amount) {
                        return ret;
                    }
                }
            }
        }
        return -1;
    }
public:
    int coinChange1(vector<int>& coins, int amount) {
        /*动态规划
            dp[0] = 0
            dp[i] = min(dp[i-coins[0]], dp[i-coins[1]], dp[i-coins[2]]...) + 1
        */
        int top = amount + 1;
        vector<int> dp(top, top);
        dp[0] = 0;
        for (int i = 1; i < top;++i) {
            for (int c : coins) {
                if (c <= i) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        if (dp[amount] > amount)
            return -1;
        return dp[amount];
    }
};

int main(int argc, char const* argv[]) {
    CoinChange cls;
    cout << cls.coinChange1(vector<int>{186, 419, 83, 408}, 6249) << " -> 20" << endl;
    cout << cls.coinChange1(vector<int>{1, 2, 5}, 11) << " -> 3" << endl;
    cout << cls.coinChange1(vector<int>{2}, 3) << " -> -1" << endl;
    cout << cls.coinChange1(vector<int>{1}, 0) << " -> 0" << endl;
    cout << cls.coinChange1(vector<int>{1}, 1) << " -> 1" << endl;
    cout << cls.coinChange1(vector<int>{1}, 2) << " -> 2" << endl;
    cout << cls.coinChange1(vector<int>{1, 2, 5}, 100) << " -> 20" << endl;
    return 0;
}
