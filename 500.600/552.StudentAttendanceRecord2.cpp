#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
using namespace std;

class StudentAttendanceRecord2
{
public:
    // 暴力求解
    int checkRecord(int n)
    {
        if (n == 1)
        {
            return 3;
        }
        queue<pair<int, int>> qu;
        qu.push({1, 0});
        qu.push({0, 1});
        qu.push({0, 0});
        for (int x = 1; x < n; ++x)
        {
            int size = qu.size();
            for (int i = 0; i < size; ++i)
            {
                pair<int, int> cur = qu.front();
                qu.pop();
                if (cur.first + 1 < 2)
                {
                    qu.push({cur.first + 1, 0});
                }
                if (cur.second + 1 < 3)
                {
                    qu.push({cur.first, cur.second + 1});
                }
                qu.push({cur.first, 0});
            }
        }
        return qu.size();
    }

    // 动态规划 原理与暴力破解相似
    int checkRecord1(int n)
    {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            // 以P结尾 A数量不变 L数量清0
            for (int j = 0; j < 2; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
                }
            }
            // 以A结尾 0个A变1个 1个A的越界
            for (int k = 0; k < 3; ++k)
            {
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
            }
            // 以L结尾
            for (int j = 0; j < 2; ++j)
            {
                for (int k = 1; k < 3; ++k)
                {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                }
            }
        }
        int sum = 0;
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                sum = (sum + dp[n][j][k]) % MOD;
            }
        }
        return sum;
    }

    // 数学 快速幂 方法
    int checkRecord2(int n)
    {
        vector<vector<long>> mat = {{1, 1, 0, 1, 0, 0}, {1, 0, 1, 1, 0, 0}, {1, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 0}, {0, 0, 0, 1, 0, 1}, {0, 0, 0, 1, 0, 0}};
        vector<vector<long>> res = pow(mat, n);
        long sum = accumulate(res[0].begin(), res[0].end(), 0ll);
        return (int)(sum % MOD);
    }

private:
    vector<vector<long>> pow(vector<vector<long>> mat, int n)
    {
        vector<vector<long>> ret = {{1, 0, 0, 0, 0, 0}};
        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                ret = multiply(ret, mat);
            }
            n >>= 1;
            mat = multiply(mat, mat);
        }
        return ret;
    }

    vector<vector<long>> multiply(vector<vector<long>> a, vector<vector<long>> b)
    {
        int rows = a.size(), columns = b[0].size(), temp = b.size();
        vector<vector<long>> c(rows, vector<long>(columns));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                for (int k = 0; k < temp; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                    c[i][j] %= MOD;
                }
            }
        }
        return c;
    }

private:
    static constexpr int MOD{1000000007};
};

int main()
{
    StudentAttendanceRecord2 cls;
    cout << cls.checkRecord2(2) << " -> 8" << endl;
    cout << cls.checkRecord2(1) << " -> 3" << endl;
    cout << cls.checkRecord2(10101) << " -> 183236316" << endl;
    return 0;
}
