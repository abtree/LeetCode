#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// 350. 两个数组的交集 II
class InterinsectionOfTwoArrays2 {
    /*
    给定两个数组，编写一个函数来计算它们的交集。
    */
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> ret;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                ret.push_back(nums1[i]);
                ++i;
                ++j;
            }
            else if (nums1[i] < nums2[j]) {
                ++i;
            }
            else {
                ++j;
            }
        }
        return ret;
    }
public:
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dp;
        for (auto x : nums1) {
            dp[x] += 1;
        }
        vector<int> ret;
        for (auto x : nums2) {
            if (dp[x] > 0) {
                ret.push_back(x);
                --dp[x];
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    InterinsectionOfTwoArrays2 cls;
    auto& ret = cls.intersect1(vector<int>{1, 2, 2, 1}, vector<int>{2, 2});
    cout << "[";
    for (auto x : ret) {
        cout << x << ",";
    }
    cout << "]" << endl;

    auto& ret1 = cls.intersect1(vector<int>{4, 9, 5}, vector<int>{9, 4, 9, 8, 4});
    cout << "[";
    for (auto x : ret1) {
        cout << x << ",";
    }
    cout << "]" << endl;

    return 0;
}
