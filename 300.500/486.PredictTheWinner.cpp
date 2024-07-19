#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PredictTheWinner
{
public:
    bool predictTheWinner(vector<int> nums)
    {
        return def(nums, 0, nums.size() - 1, 1) >= 0;
    }

private:
    int def(vector<int> &nums, int pStart, int pEnd, int turn)
    {
        if (pStart == pEnd)
        {
            return nums[pStart] * turn;
        }
        // 算出两种不同选择的结果
        int v1 = nums[pStart] * turn + def(nums, pStart + 1, pEnd, -turn);
        int v2 = nums[pEnd] * turn + def(nums, pStart, pEnd - 1, -turn);
        // 取对自己最有利的结果
        if (turn < 0)
        {
            return min(v1, v2);
        }
        else
        {
            return max(v1, v2);
        }
        // return max(v1 * turn, v2 * turn) * turn;
    }

public:
    // 动态规划
    // 注意：每一个i..j都是算的先手胜利的值,
    // 所以如果增加一位，先手就会变化
    bool predictTheWinner1(vector<int> nums)
    {
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        // 当只有一个元素时，先手方肯定是胜利的，差值就为nums[i]
        for (int i = 0; i < len; ++i)
        {
            dp[i][i] = nums[i];
        }
        for (int i = len - 2; i >= 0; --i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                // 这里因为先后手调换了，所以要用减
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][len - 1] >= 0;
    }
};

int main(int argc, char const *argv[])
{
    PredictTheWinner cls;
    cout << boolalpha << cls.predictTheWinner1(vector<int>{1, 5, 2}) << " -> false" << endl;
    cout << boolalpha << cls.predictTheWinner1(vector<int>{1, 5, 233, 7}) << " -> true" << endl;
    return 0;
}
