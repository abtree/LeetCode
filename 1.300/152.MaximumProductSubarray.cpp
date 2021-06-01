#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//152. 乘积最大子数组
class MaximumProductSubarray {
    /* 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。 */
public:
    int maxProduct(vector<int>& nums) {
        //动态规划（会超时）
        //dp[i][j] = i...j元素的乘积
        //dp[i][i] = nums[i];
        //dp[i][j] = dp[i][j -1] * nums[j]
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int ret = INT_MIN;
        for (int i = 0;i < len;++i) {
            dp[i][i] = nums[i];
            if (nums[i] > ret)
                ret = nums[i];
        }
        for (int i = 1; i < len;++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = dp[j][i - 1] * nums[i];
                if (dp[j][i] > ret)
                    ret = dp[j][i];
            }
        }
        return ret;
    }
public:
    int maxProduct2(vector<int>& nums) {
        //动态规划改良版
        //因为要考虑 负数（负负为正） 所有需要记录最小值 
        int mx = nums[0];   //记录以当前节点上一个节点为结尾的最大乘积
        int mn = nums[0];   //记录以当前节点上一个节点为结尾的最小乘积
        int ans = nums[0];    //记录最大乘积
        for (int i = 1; i < nums.size(); ++i) {
            int x = mx;
            int n = mn;
            mx = max(x * nums[i], max(nums[i], n * nums[i]));
            mn = min(n * nums[i], min(nums[i], x * nums[i]));
            ans = max(mx, ans);
        }
        return ans;
    }
};

int main(int argc, char const* argv[])
{
    MaximumProductSubarray cls;
    cout << cls.maxProduct2(vector<int>{5, 6, -3, 4, -3}) << " -> 1080" << endl;
    cout << cls.maxProduct2(vector<int>{2, 3, -2, 4}) << " -> 6" << endl;
    cout << cls.maxProduct2(vector<int>{-2, 0, -1}) << " -> 0" << endl;
    return 0;
}
