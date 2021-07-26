#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 324. 摆动排序 II
class WiggleSort2 {
    /* 给你一个整数数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。你可以假设所有输入数组都可以得到满足题目要求的结果。
    */
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = n >> 1;
        if (n % 2 == 0) {
            --i;
        }
        int j = n - 1;
        vector<int> ret(n);
        for (int k = 0; k < n; ++k) {
            ret[k] = nums[i];
            --i;++k;
            if (k == n)
                break;
            ret[k] = nums[j];
            --j;
        }
        swap(nums, ret);
    }
};

int main(int argc, char const* argv[]) {
    WiggleSort2 cls;

    vector<int> ret2{ 1,1,2,1,2,2,1 };
    cls.wiggleSort(ret2);
    cout << "[";
    for (auto c : ret2) {
        cout << c << ",";
    }
    cout << "]" << endl;

    vector<int> ret{ 1, 5, 1, 1, 6, 4 };
    cls.wiggleSort(ret);
    cout << "[";
    for (auto c : ret) {
        cout << c << ",";
    }
    cout << "]" << endl;

    vector<int> ret1{ 1, 3, 2, 2, 3, 1 };
    cls.wiggleSort(ret1);
    cout << "[";
    for (auto c : ret1) {
        cout << c << ",";
    }
    cout << "]" << endl;

    return 0;
}
