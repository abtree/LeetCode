#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 300. 最长递增子序列
class LongestIncreasingSubsequence {
    /*  给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
    */
public:
    int lengthOfLIS1(vector<int>& nums) {
        /* 动态规划
        dp[i] 表示必须包含第i个元素的前i个元素的最长子串长度
        则有 dp[i] = dp[j]+1;
        */
        int size = nums.size();
        vector<int> dp(size, 1);
        for(int i =1; i<size;++i){
            for(int j = 0;j<i;++j){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 1; i < size;++i){
            if(nums[i] > dp.back()){
                dp.push_back(nums[i]);
            }else{
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                (*it) = nums[i];
            }
        }
        return dp.size();
    }
};

int main(int argc, char const* argv[]) {
    LongestIncreasingSubsequence cls;
    cout << cls.lengthOfLIS(vector<int>{10,9,2,5,3,7,101,18}) << " -> 4" << endl;
    cout << cls.lengthOfLIS(vector<int>{0,1,0,3,2,3}) << " -> 4" << endl;
    cout << cls.lengthOfLIS(vector<int>{7,7,7,7,7,7,7}) << " -> 1" << endl;
    cout << cls.lengthOfLIS(vector<int>{0,1,98,99,100,2,3,4,5,6,7,8,9}) << " -> 10" << endl;
    cout << cls.lengthOfLIS(vector<int>{200,201,98,99,100,101,102,103,5,6,105,8,9}) << " -> 7" << endl;
    return 0;
}
