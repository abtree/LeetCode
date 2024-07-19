#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class OnesAndZeros
{
public:
    // 将尽可能多的字符串装进m个0和n个1的格子里，每个0格子装1个0，每个1格子装1个1
    // 也就是所有装进格子的字符串的0的个数 <= m
    // 所有装进格子的字符串的1的个数 <= n
    int findMaxForm(vector<string> strs, int m, int n)
    {
        size_t len = strs.size();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        int l = 1;
        for (string &str : strs)
        {
            vector<int> &&zerosOnes = getZerosOnes(str);
            for (int i = 0; i <= m; ++i)
            {
                for (int j = 0; j <= n; ++j)
                {
                    // 默认不加入该str，即取l-1的最大值
                    dp[l][i][j] = dp[l - 1][i][j];
                    if (i >= zerosOnes[0] && j >= zerosOnes[1])
                    {
                        // 此时该字符串可以放进去,但是放进去以后 l-1中 i = i-zeros, j = j-ones
                        // 即把放进该字符串的zeros和ones留出来
                        // 此时需要取放进该字符串与不放进该字符串的最大值
                        dp[l][i][j] = max(dp[l][i][j], dp[l - 1][i - zerosOnes[0]][j - zerosOnes[1]] + 1);
                    }
                }
            }
            ++l;
        }
        return dp[len][m][n];
    }

    // 去掉一个维度的方法
    int findMaxForm1(vector<string> strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto &str : strs)
        {
            vector<int> &&zerosOnes = getZerosOnes(str);
            // 注意：这里上一轮结果与当前轮结果在同一个数组里面
            // 所以为了不提前覆盖掉这一轮需要用到的上一轮的值，需要用倒叙遍历
            // 而遍历到 i = zeros 和 j = ones也是因为当 i < zeros 或 j < ones 时，我们直接使用上一轮的值
            for (int i = m; i >= zerosOnes[0]; --i)
            {
                for (int j = n; j >= zerosOnes[1]; --j)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zerosOnes[0]][j - zerosOnes[1]] + 1);
                }
            }
        }
        return dp[m][n];
    }

private:
    // 计算该字符串0的个数和1的个数
    vector<int> getZerosOnes(string &str)
    {
        vector<int> vec(2, 0);
        for (char c : str)
        {
            vec[c - '0']++;
        }
        return vec;
    }
};

int main()
{
    OnesAndZeros cls;
    cout << cls.findMaxForm1(vector<string>{"10", "0001", "111001", "1", "0"}, 5, 3) << " -> 4" << endl;
    cout << cls.findMaxForm1(vector<string>{"10", "0", "1"}, 1, 1) << " -> 2" << endl;
    return 0;
}