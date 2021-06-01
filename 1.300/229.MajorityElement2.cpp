#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 229. 求众数 II
class MajorityElement2 {
    /*  给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
    进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。
    */
public:
    vector<int> majorityElement(vector<int>& nums) {
        //统计法
        int n = nums.size() / 3;
        unordered_map<int, int> counts;
        vector<int> ret;
        for(int i : nums){
            ++counts[i];
        }
        for (auto &it : counts){
            if (it.second > n)
                ret.push_back(it.first);
        }
        return ret;
    }
public:
    vector<int> majorityElement2(vector<int>& nums) {
        vector<int> ret;
        int size = nums.size();
        if(size == 0)
            return ret;
        if(size == 1){
            ret.push_back(nums[0]);
            return ret;
        }
        //排序法
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int n = size / 3;
        for(int i = 0; i< size; ++i){
            if(i+1 < size && nums[i] == nums[i+1]){
                ++cnt;
            }else{
                if(cnt > n)
                    ret.push_back(nums[i]);
                cnt = 1;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    MajorityElement2 cls;
    auto &ret = cls.majorityElement2(vector<int>{3,2,3});
    cout << "[";
    for(auto i : ret){
        cout << i << ",";
    }
    cout << "]" << endl;

    auto &ret1 = cls.majorityElement2(vector<int>{1});
    cout << "[";
    for(auto i : ret1){
        cout << i << ",";
    }
    cout << "]" << endl;

    auto &ret2 = cls.majorityElement2(vector<int>{1,1,1,3,3,2,2,2});
    cout << "[";
    for(auto i : ret2){
        cout << i << ",";
    }
    cout << "]" << endl;
    return 0;
}
