#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 219. 存在重复元素 II
class ContainsDuplicate2 {
    /* 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。
    */
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //超时
        int p = 0;
        int n = nums.size();
        while (p < n) {
            for (int i = min(p + k, n-1); i > p; --i) {
                if (nums[p] == nums[i])
                    return true;
            }
            ++p;
        }
        return false;
    }
public:
    bool containsNearbyDuplicate2(vector<int>& nums, int k) {
        unordered_set<int> kset;
        for(int i = 0; i< nums.size(); ++i){
            if(kset.find(nums[i]) != kset.end())
                return true;
            kset.insert(nums[i]);
            if(kset.size() > k){
                kset.erase(nums[i-k]);
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    ContainsDuplicate2 cls;
    cout << boolalpha << cls.containsNearbyDuplicate2(vector<int>{99,99}, 2) << " ->true"<< endl;
    cout << boolalpha << cls.containsNearbyDuplicate2(vector<int>{1,2,3,1}, 3) << " ->true"<< endl;
    cout << boolalpha << cls.containsNearbyDuplicate2(vector<int>{1,0,1,1}, 1) << " ->true"<< endl;
    cout << boolalpha << cls.containsNearbyDuplicate2(vector<int>{1,2,3,1,2,3}, 2) << " ->false"<< endl;
    return 0;
}
