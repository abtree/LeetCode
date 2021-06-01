#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//137. 只出现一次的数字 II
class SingleNumber
{
    /*给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
    */
public:
    int singleNumber(vector<int>& nums) {
        //排序查找法
        if(nums.size() < 4)
            return nums.back();
        sort(nums.begin(), nums.end());
        for(int i =0; i<nums.size()-1; i+=3){
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
        /*
        第一次出现时，once和twice均为0，once^num相当于把num添加到once，表示num出现了一次，~once表示不把num添加到twice；
            once = ~0 & (0 ^ a) = a
            twice = ~a & (0 ^ a) = 0
        第二次出现时，num已经添加到once了，num^num=0，once=0，相当于将num从once中删除，twice^num相当于把num添加到twice中；
            once = ~0 & (a ^ a) = 0
            twice = ~0 & (0 ^ a) = a
        第三次出现时，第二次的twice为1，~twice为0，所以once依然为0，第三次的twice=num^num=0，相当于把num从twice中删除；
            once = ~a & (0 ^ a) = 0
            twice = ~0 & (a ^ a) = 0
        */
        int seenOnce = 0, seenTwice = 0;
        for (auto e: nums){
            seenOnce = ~seenTwice & (seenOnce ^ e);
            seenTwice = ~seenOnce & (seenTwice ^ e);
        }
        return seenOnce;
    } 
};

int main(int argc, char const* argv[])
{
    SingleNumber cls;
    cout << cls.singleNumber3(vector<int>{1,1,1}) << " -> 1" << endl;
    cout << cls.singleNumber3(vector<int>{2,2,3,2}) << " -> 3" << endl;
    cout << cls.singleNumber3(vector<int>{0,1,0,1,0,1,99}) << " -> 99" << endl;
    cout << cls.singleNumber3(vector<int>{1}) << " -> 1" << endl;
    return 0;
}
