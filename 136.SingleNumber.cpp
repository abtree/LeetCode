#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//136. 只出现一次的数字
class SingleNumber
{
    /*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
    说明：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
    */
public:
    int singleNumber(vector<int>& nums) {
        //排序查找法
        if(nums.size() < 2)
            return nums.back();
        sort(nums.begin(), nums.end());
        for(int i =0; i<nums.size(); i+=2){
            if(nums[i] != nums[i+1])
                return nums[i];
        }
        return nums.back();
    }
public:
    int singleNumber2(vector<int>& nums) {
        //hash表法
        unordered_map<int, int> dp;
        for(auto i : nums){
            dp[i] += 1;
        }
        for(auto &it : dp){
            if(it.second == 1)
                return it.first;
        }
        return 0;
    } 
public:
    int singleNumber3(vector<int>& nums) {
        //位运算 法
        // a ^ 0 = a && a ^ a = 0 && a ^ b ^ a = a ^ a ^ b = b
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    } 
};

int main(int argc, char const* argv[])
{
    SingleNumber cls;
    cout << cls.singleNumber3(vector<int>{2,2,1}) << " -> 1" << endl;
    cout << cls.singleNumber3(vector<int>{4,1,2,1,2}) << " -> 4" << endl;
    cout << cls.singleNumber3(vector<int>{1}) << " -> 1" << endl;
    return 0;
}
