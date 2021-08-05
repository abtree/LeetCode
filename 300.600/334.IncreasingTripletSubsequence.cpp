#include <iostream>
#include <vector>
using namespace std;

// 334. 递增的三元子序列
class IncreasingTripletSubsequence {
    /* 给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。
    */
public:
    bool increasingTriplet(vector<int>& nums) {
        /*  此题只要求 small 比 mid 小
            而不要求 small的pos一定在mid前面，因为mid前面一定有比mid小的项，不一定是small
        */
        int small = INT_MAX;
        int mid = INT_MAX;
        for (int c : nums) {
            if (c < small) {
                small = c;
            }
            else if (c > small && c < mid) {
                mid = c;
            }
            else if (c > mid) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const* argv[]) {
    IncreasingTripletSubsequence cls;
    cout << boolalpha << cls.increasingTriplet(vector<int>{ 1, 1, -2, 6}) << " -> false" << endl;
    cout << boolalpha << cls.increasingTriplet(vector<int>{ 20, 100, 10, 12, 5, 13}) << " -> true" << endl;
    cout << boolalpha << cls.increasingTriplet(vector<int>{1, 2, 3, 4, 5}) << " -> true" << endl;
    cout << boolalpha << cls.increasingTriplet(vector<int>{5, 4, 3, 2, 1}) << " -> false" << endl;
    cout << boolalpha << cls.increasingTriplet(vector<int>{2, 1, 5, 0, 4, 6}) << " -> true" << endl;
    return 0;
}
