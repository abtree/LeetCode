#include <iostream>
#include <vector>
using namespace std;

class TargetSum
{
public:
    int findTargetSumWays(const vector<int> &nums, int target)
    {
        tar = target;
        return dfs(nums, 0, 0);
    }

private:
    int dfs(const vector<int> &nums, int pos, int sum)
    {
        if (pos >= nums.size())
        {
            if (sum == tar)
            {
                return 1;
            }
            return 0;
        }
        int n1 = dfs(nums, pos + 1, sum + nums[pos]);
        int n2 = dfs(nums, pos + 1, sum - nums[pos]);
        return n1 + n2;
    }

private:
    int tar{};

public:
    int findTargetSumWays1(const vector<int> &nums, int target)
    {
        int sum = 0;
        for (int n : nums)
        {
            sum += n;
        }
        int neg = sum - target;
        if (neg < 0 || neg & 1)
        {
            return 0;
        }
        neg >>= 1;
        int size = nums.size();
        // 问题转换为在nums前i个元素中选取若干元素，使其和为j的方案数
        // vector<vector<int>> dp(size + 1, vector<int>(neg + 1, 0));
        // dp[0][0] = 1; // 特殊情况，选取0个元素和为0
        // for (int i = 1; i <= size; ++i)
        // {
        //     int num = nums[i - 1];
        //     for (int j = 0; j <= neg; ++j)
        //     {
        //         dp[i][j] = dp[i - 1][j];
        //         if (j >= num)
        //         {
        //             dp[i][j] += dp[i - 1][j - num];
        //         }
        //     }
        // }
        // return dp[size][neg];

        vector<int> dp = vector<int>(neg + 1, 0);
        dp[0] = 1;
        for (int num : nums)
        {
            for (int j = neg; j >= num; --j)
            {
                dp[j] += dp[j - num];
            }
        }
        return dp[neg];
    }
};

int main(int argc, char const *argv[])
{
    TargetSum cls;
    cout << cls.findTargetSumWays1(vector<int>{1, 1, 1, 1, 1}, 3) << " -> 5" << endl;
    cout << cls.findTargetSumWays1(vector<int>{1}, 1) << " -> 1" << endl;
    return 0;
}
