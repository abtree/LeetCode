#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 349. 两个数组的交集
class IntersectionOfTwoArrays {
    /* 给定两个数组，编写一个函数来计算它们的交集。
    */
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> ret;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                ret.push_back(nums1[i]);
                ++i;
                while (i < nums1.size() && nums1[i] == nums1[i - 1]) {
                    ++i;
                }
                ++j;
                while (j < nums2.size() && nums2[j] == nums2[j - 1]) {
                    ++j;
                }
            }
            else if (nums1[i] < nums2[j]) {
                ++i;
                while (i < nums1.size() && nums1[i] == nums1[i - 1]) {
                    ++i;
                }
            }
            else {
                ++j;
                while (j < nums2.size() && nums2[j] == nums2[j - 1]) {
                    ++j;
                }
            }
        }
        return ret;
    }
public:
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> dp;
        for (auto x : nums1) {
            dp[x] = true;
        }
        vector<int> ret;
        for (auto x : nums2) {
            if (dp[x]) {
                ret.push_back(x);
                dp[x] = false;  //去重
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    IntersectionOfTwoArrays cls;
    auto& ret = cls.intersection1(vector<int>{1, 2, 2, 1}, vector<int>{2, 2});
    cout << "[";
    for (auto x : ret) {
        cout << x << ",";
    }
    cout << "]" << endl;

    auto& ret1 = cls.intersection1(vector<int>{4, 9, 5}, vector<int>{9, 4, 9, 8, 4});
    cout << "[";
    for (auto x : ret1) {
        cout << x << ",";
    }
    cout << "]" << endl;

    return 0;
}
