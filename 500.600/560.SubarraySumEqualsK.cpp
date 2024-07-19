#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class SubarraySumEqualsK
{
public:
    int subarraySum(const vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = nums[i];
            if (dp[i][i] == k)
            {
                ++ret;
            }
        }
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j + i < n; ++j)
            {
                dp[j][j + i] = nums[j] + dp[j + 1][j + i];
                if (dp[j][j + i] == k)
                {
                    ++ret;
                }
            }
        }
        return ret;
    }

public:
    int subarraySum1(vector<int> nums, int k)
    {
        int sum = 0;
        int n = nums.size();
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            nums[i] = sum;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j + i < n; ++j)
            {
                int dec = nums[j + i];
                if (j > 0)
                {
                    dec -= nums[j - 1];
                }
                if (dec == k)
                {
                    ++ret;
                }
            }
        }
        return ret;
    }

public:
    int subarraySum2(const vector<int> &nums, int k)
    {
        int n = nums.size();
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j >= 0; --j)
            {
                sum += nums[j];
                if (sum == k)
                {
                    ++ret;
                }
            }
        }
        return ret;
    }

public:
    int subarraySum3(const vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ret = 0, pre = 0;
        for (auto x : nums)
        {
            pre += x;
            if (mp.find(pre - k) != mp.end())
            {
                ret += mp[pre - k];
            }
            mp[pre]++;
        }
        return ret;
    }
};

int main()
{
    SubarraySumEqualsK cls;
    cout << cls.subarraySum3(vector<int>{1, 1, 1}, 2) << " -> 2" << endl;
    cout << cls.subarraySum3(vector<int>{1, 2, 3}, 3) << " -> 2" << endl;
    return 0;
}
