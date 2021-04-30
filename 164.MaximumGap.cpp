#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//164. 最大间距
class MaximumGap
{
    /* 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。如果数组元素个数小于 2，则返回 0。
    */
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = 1; i < nums.size(); ++i) {
            ret = max(ret, nums[i] - nums[i - 1]);
        }
        return ret;
    }
};

int main(int argc, char const* argv[])
{
    MaximumGap cls;
    cout << cls.maximumGap(vector<int>{3, 6, 9, 1}) << " -> 3" << endl;
    cout << cls.maximumGap(vector<int>{10}) << " -> 0" << endl;
    return 0;
}
