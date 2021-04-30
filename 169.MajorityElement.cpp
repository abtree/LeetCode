#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 169. 多数元素
class MajorityElement
{
    /*给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。你可以假设数组是非空的，并且给定的数组总是存在多数元素。
    */
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> dp;
        for (auto i : nums) {
            dp[i] += 1;
        }
        int min = nums.size() / 2;
        for (auto& kv : dp) {
            if (kv.second > min)
                return kv.first;
        }
        return 0;
    }
public:
    int majorityElement2(vector<int>& nums) {
        //排序法
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];   //这里中间元素一定是众数
    }
public:
    int majorityElement3(vector<int>& nums) {
        //Boyer-Moore 投票算法
        /*
               原:  7   7   5   7   5   1   5   7   5   5   7   7   7   7   7   7
        candidate:  7   7   7   7   7   7   5   5   5   5   5   5   7   7   7   7
            count:  1   2   1   2   1   0   1   0   1   2   1   0   1   2   3   4
        */
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }  
};

int main(int argc, char const* argv[])
{
    MajorityElement cls;
    cout << cls.majorityElement3(vector<int>{3,2,3}) << " -> 3" << endl;
    cout << cls.majorityElement3(vector<int>{2,2,1,1,1,2,2}) << " -> 2" << endl;
    return 0;
}
