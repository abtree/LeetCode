#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//128. 最长连续序列
class LongestConsecutiveSequence
{
    /*给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
    进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？
    */
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        //通过排序 得到结果
        sort(nums.begin(), nums.end());
        int ret = 0;
        int cur = 1;
        for(int i =1;i< nums.size();++i){
            if(nums[i-1] == nums[i])
                continue;
            if(nums[i-1] == nums[i] - 1){
                ++cur;
            }else{
                if(cur > ret)
                    ret = cur;
                cur = 1;
            }
        }
        return max(ret,cur);
    }
public:
    int longestConsecutive2(vector<int>& nums) {
        //通过枚举以数组中每个元素为起点能达到的最大长度
        unordered_set<int> numSet;
        for(auto& num : nums){
            numSet.insert(num);
        }
        int longest = 0;
        for(auto& num : numSet){
            if(!numSet.count(num-1)){   //这里判断 如果num-1存在 就不需要判断该值 因为从num-1出发 一定大于 从该值出发
                int cur = num;
                int clang = 1;
                while(numSet.count(cur +1)){    //通过枚举判断能到达的最大长度
                    ++cur;
                    ++clang;
                }
                longest = max(longest, clang);
            }
        }
        return longest;
    }
};

int main(int argc, char const* argv[])
{
    LongestConsecutiveSequence cls;
    cout << cls.longestConsecutive2(vector<int>{100,4,200,1,3,2}) << " -> 4" << endl;
    cout << cls.longestConsecutive2(vector<int>{0,3,7,2,5,8,4,6,0,1}) << " -> 9" << endl;
    cout << cls.longestConsecutive2(vector<int>{1,2,0,1}) << " -> 3" << endl;
    return 0;
}
