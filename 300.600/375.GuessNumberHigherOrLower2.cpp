#include <iostream>
#include <algorithm>
using namespace std;

// 375. 猜数字大小 II
class GuessNumberHigherOrLower2 {
    /* 我们正在玩一个猜数游戏，游戏规则如下：我从 1 到 n 之间选择一个数字，你来猜我选了哪个数字。每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。给定 n ≥ 1，计算你至少需要拥有多少现金才能确保你能赢得这个游戏。
    */
public:
    int getMoneyAmount(int n) {
        if (n <= 1)
            return 0;
        int dp[n + 1][n + 1];   //这里需要G++才能编译过
        for (int i = 0; i <= n;++i) {
            dp[i][i] = 0;
        }
        for (int j = 2; j <= n;++j) {
            for (int i = j - 1; i >= 1;--i) {
                dp[i][j] = INT_MAX;
                for (int k = i + 1;k < j;++k) {
                    //这里用max是考虑最坏情况
                    //即 我们猜测的结果 总是落在结果较大的那边
                    dp[i][j] = min(k + max(dp[i][k - 1], dp[k + 1][j]), dp[i][j]);
                }
                dp[i][j] = min(dp[i][j], i + dp[i + 1][j]);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + j);
            }
        }
        return dp[1][n];
    }
};

int main(int argc, char const* argv[]) {
    GuessNumberHigherOrLower2 cls;
    cout << cls.getMoneyAmount(10) << " -> 16" << endl;
    cout << cls.getMoneyAmount(50) << " -> 172" << endl;
    return 0;
}
