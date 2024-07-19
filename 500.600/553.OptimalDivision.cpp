#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    // 区间最小值
    double minVal{10000.0};
    // 区间最大值
    double maxVal{};
    // 最小值字符串
    string minStr{};
    // 最大值字符串
    string maxStr{};
};

class OptimalDivision
{
public:
    string optimalDivision(const vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<Node>> dp(n, vector<Node>(n));
        for (int i = 0; i < n; ++i)
        {
            dp[i][i].maxVal = double(nums[i]);
            dp[i][i].minVal = double(nums[i]);
            dp[i][i].minStr = to_string(nums[i]);
            dp[i][i].maxStr = to_string(nums[i]);
        }
        // i表示区间大小
        for (int i = 1; i < n; ++i)
        {
            // j表示区间开始值, [j, j+i]为区间
            for (int j = 0; j + i < n; ++j)
            {
                // k表示区间[j, j+i]分割位置
                for (int k = j; k < j + i; ++k)
                {
                    if (dp[j][j + i].maxVal < dp[j][k].maxVal / dp[k + 1][j + i].minVal)
                    {
                        dp[j][j + i].maxVal = dp[j][k].maxVal / dp[k + 1][j + i].minVal;
                        if (k + 1 == j + i)
                        {
                            dp[j][j + i].maxStr = dp[j][k].maxStr + "/" + dp[k + 1][j + i].minStr;
                        }
                        else
                        {
                            dp[j][j + i].maxStr = dp[j][k].maxStr + "/(" + dp[k + 1][j + i].minStr + ")";
                        }
                    }
                    if (dp[j][j + i].minVal > dp[j][k].minVal / dp[k + 1][j + i].maxVal)
                    {
                        dp[j][j + i].minVal = dp[j][k].minVal / dp[k + 1][j + i].maxVal;
                        if (k + 1 == j + i)
                        {
                            dp[j][j + i].minStr = dp[j][k].minStr + "/" + dp[k + 1][j + i].maxStr;
                        }
                        else
                        {
                            dp[j][j + i].minStr = dp[j][k].minStr + "/(" + dp[k + 1][j + i].maxStr + ")";
                        }
                    }
                }
            }
        }
        return dp[0][n - 1].maxStr;
    }

public:
    string optimalDivision1(const vector<int> &nums)
    {
        // 由于该题nums[i] >= 2 所以该题的答案固定为
        // nums[0] / (nums[1]/nums[2]/.../nums[n-1])
        int n = nums.size();
        if (n == 1)
        {
            return to_string(nums[0]);
        }
        if (n == 2)
        {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        string str = to_string(nums[0]);
        str += "/(";
        for (int i = 1; i < n; ++i)
        {
            str += to_string(nums[i]) + "/";
        }
        str.pop_back();
        str += ")";
        return str;
    }
};

int main()
{
    OptimalDivision cls;
    cout << cls.optimalDivision1(vector<int>{1000, 100, 10, 2}).c_str() << " 1000/(100/10/2)" << endl;
    cout << cls.optimalDivision1(vector<int>{2, 3, 4}).c_str() << " 2/(3/4)" << endl;
    return 0;
}
