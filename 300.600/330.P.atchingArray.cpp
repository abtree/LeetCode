#include <iostream>
#include <vector>
using namespace std;

//330. 按要求补齐数组
class PatchingArray {
    /* 给定一个已排序的正整数数组 nums，和一个正整数 n 。从 [1, n] 区间内选取任意个数字补充到 nums 中，使得 [1, n] 区间内的任何数字都可以用 nums 中某几个数字的和来表示。请输出满足上述要求的最少需要补充的数字个数。
    */
public:
    int minPatches(vector<int>& nums, int n) {
        /* 假如 1..x-1 已经在列表中了
            则只需要补充 x 就可以保证 1..2x-1全覆盖
        */
        long long x = 1;
        int i = 0;
        int ret = 0;
        while (x <= n) {
            if (i < nums.size() && x >= nums[i]) {   // nums已经排序 很重要
                x += nums[i];
                ++i;
            }
            else {
                ++ret;
                x <<= 1;    // x = 2x
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    PatchingArray cls;
    cout << cls.minPatches(vector<int>{1, 3}, 6) << " -> 1" << endl;
    cout << cls.minPatches(vector<int>{1, 5, 10}, 20) << " -> 2" << endl;
    cout << cls.minPatches(vector<int>{1, 2, 2}, 5) << " -> 0" << endl;

    return 0;
}
