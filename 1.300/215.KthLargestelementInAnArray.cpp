#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 215. 数组中的第K个最大元素
class KthLargestelementInAnArray {
    /* 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
    */
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};

int main(int argc, char const* argv[])
{
    KthLargestelementInAnArray cls;
    cout << cls.findKthLargest(vector<int>{3,2,1,5,6,4}, 2) << " -> 5" << endl;
    cout << cls.findKthLargest(vector<int>{3,2,3,1,2,4,5,5,6}, 4) << " -> 4" << endl;
    return 0;
}
