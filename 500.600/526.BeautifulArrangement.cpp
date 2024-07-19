#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class BeautifulArrangement
{
public:
    // 回溯法
    int countArrangement(int n)
    {
        num = 0;
        used.clear();
        dp.clear();
        used.resize(n + 1);
        dp.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i % j == 0 || j % i == 0)
                {
                    dp[i].push_back(j);
                }
            }
        }
        dfs(1, n);
        return num;
    }

private:
    void dfs(int i, int n)
    {
        if (i > n)
        {
            ++num;
            return;
        }
        for (int x : dp[i])
        {
            if (used[x])
            {
                continue;
            }
            used[x] = 1;
            dfs(i + 1, n);
            used[x] = 0;
        }
    }

private:
    vector<vector<int>> dp;
    vector<int> used;
    int num;

public:
    int countArrangement1(int n)
    {
        // dp存储填不同mask，可以得到的总优美的排列数
        // mask中的1就代表选取了哪一个值
        vector<int> dp(1 << n);
        dp[0] = 1;
        for (int mask = 1; mask < (1 << n); ++mask)
        {
            // num代表的是当前在填第几个位置(1开始)
            int num = __builtin_popcount(mask);
            for (int i = 0; i < n; ++i)
            {
                // 如果当前值被选取，且满足要求
                if ((mask & (1 << i)) && (num % (i + 1) == 0 || (i + 1) % num == 0))
                {
                    // 第num位填当前值后，剩下的为有多少种填法之和
                    dp[mask] += dp[mask ^ (1 << i)];
                }
            }
        }
        // 返回每一位都填1时的总组合数
        return dp[(1 << n) - 1];
    }
};

int main()
{
    BeautifulArrangement cls;
    cout << cls.countArrangement1(2) << "->2" << endl;
    cout << cls.countArrangement1(1) << "->1" << endl;
    cout << cls.countArrangement1(15) << "->24679" << endl;
    return 0;
}
