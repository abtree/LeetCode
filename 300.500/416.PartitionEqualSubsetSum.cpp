#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PartitionEqualSubsetSum{
public:
    bool canPartition(vector<int>& nums) {
        //穷举法
        long long sum = 0;
        for (int x : nums) {
            sum += x;
        }
        if (sum & 1)
            return false;
        sum >>= 1;
        return can(nums, sum, 0);
    }
private:
    bool can(vector<int>& nums, long long sum, int p) {
        while (p < nums.size()) {
            sum -= nums[p];
            if (sum == 0)
                return true;
            if (can(nums, sum, p + 1))
                return true;
            sum += nums[p];
            ++p;
        }
        return false;
    }
public:
    bool canPartition2(vector<int>& nums) {
        //动态规划
        int sum = 0;
        int maxNum = 0;
        for (int x : nums) {
            sum += x;
            if (x > maxNum)
                maxNum = x;
        }
        if (sum & 1)
            return false;  //元素和为基数 不能平分
        sum >>= 1;
        if (sum < maxNum)
            return false;   //最大元素 大于半值
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum + 1, false));
        for (int i = 0; i < nums.size();++i) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1;i < nums.size();++i) {
            for (int j = 1; j <= sum;++j) {
                if (j < nums[i]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j] || dp[i-1][j - nums[i]];
                }
            }
        }
        return dp[nums.size() - 1][sum];
    }
public:
    bool canPartition3(vector<int>& nums) {
        int sum = 0;
        int maxNum = 0;
        for (int x : nums) {
            sum += x;
            if (x > maxNum)
                maxNum = x;
        }
        if (sum & 1)
            return false;  //元素和为基数 不能平分
        sum >>= 1;
        if (sum < maxNum)
            return false;   //最大元素 大于半值
        vector<int> dp(sum + 1, 0);
        for (int x : nums) {
            for (int j = sum; j >= x;--j) {
                dp[j] = max(dp[j], dp[j - x] + x);
            }
        }
        return dp[sum] == sum;
    }
};

int main(int argc, char const* argv[]) {
    PartitionEqualSubsetSum cls;
    cout << boolalpha << cls.canPartition3(vector<int>{100,100,99,97}) << " -> false" << endl;
    cout << boolalpha << cls.canPartition3(vector<int>{1, 5, 11, 5}) << " -> true" << endl;
    cout << boolalpha << cls.canPartition3(vector<int>{1,2,3,5}) << " -> false" << endl;
    return 0;
}