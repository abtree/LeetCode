#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 209. 长度最小的子数组
class MinimumSizeSubarraySum
{
    /* 给定一个含有 n 个正整数的数组和一个正整数 target 。找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
    */
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i =0,j=0;
        int total = 0;
        int ret = INT_MAX;
        while(i < nums.size()){
            while(total < target && i < nums.size()){
                total += nums[i];
                ++i;
            }
            if(total < target)
                break;
            while (total >= target){
                total -= nums[j];
                ++j;
            }
            ret = min(i - j + 1, ret);
        }
        return (ret == INT_MAX)?0:ret;
    }
};

int main(int argc, char const *argv[])
{
    MinimumSizeSubarraySum cls;
    cout << cls.minSubArrayLen(7, vector<int>{2,3,1,2,4,3}) << " -> 2" << endl;
    cout << cls.minSubArrayLen(4, vector<int>{1,4,4}) << " -> 1" << endl;
    cout << cls.minSubArrayLen(11, vector<int>{1,1,1,1,1,1,1,1}) << " -> 0" << endl;
    return 0;
}
