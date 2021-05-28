#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 217. 存在重复元素
class ContainsDuplicate {
    /* 给定一个整数数组，判断是否存在重复元素。如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
    */
public:
    bool containsDuplicate(vector<int>& nums) {
        //排序查找
        sort(nums.begin(), nums.end());
        for (int i = 1;i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
public:
    bool containsDuplicate2(vector<int>& nums) {
        //hash法
        unordered_set<int> dup;
        for(auto i : nums){
            if(dup.find(i) != dup.end())
                return true;
            dup.insert(i);
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    ContainsDuplicate cls;
    cout << boolalpha << cls.containsDuplicate2(vector<int>{1,2,3,1}) << " -> true" << endl;
    cout << boolalpha << cls.containsDuplicate2(vector<int>{1,2,3,4}) << " -> false" << endl;
    cout << boolalpha << cls.containsDuplicate2(vector<int>{1,1,1,3,3,4,3,2,4,2}) << " -> true" << endl;
    return 0;
}
