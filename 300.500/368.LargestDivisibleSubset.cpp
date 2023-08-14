#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class LargestDivisibleSubset {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size();++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        //倒推结果
        auto it = max_element(dp.begin(), dp.end());
        int pos = distance(dp.begin(), it);
        if (pos == 0) {
            return vector<int>{nums[0]};
        }
        int max = *it;
        vector<int> ret(max, 0);
        ret[--max] = nums[pos];
        for (int i = pos - 1; i >= 0 && max > 0; i--) {
            if (dp[i] == max && ret[max] % nums[i] == 0) {
                ret[--max] = nums[i];
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    LargestDivisibleSubset cls;

    auto& ret3 = cls.largestDivisibleSubset(vector<int>{5, 9, 18, 54, 108, 540, 90, 180, 360, 720});
    cout << "[";
    for (auto c : ret3) {
        cout << c << ",";
    }
    cout << "]" << endl;

    auto& ret = cls.largestDivisibleSubset(vector<int>{1, 2, 3});
    cout << "[";
    for (auto c : ret) {
        cout << c << ",";
    }
    cout << "]" << endl;

    auto& ret1 = cls.largestDivisibleSubset(vector<int>{1, 2, 4, 8});
    cout << "[";
    for (auto c : ret1) {
        cout << c << ",";
    }
    cout << "]" << endl;

    auto& ret2 = cls.largestDivisibleSubset(vector<int>{2, 3, 4, 8});
    cout << "[";
    for (auto c : ret2) {
        cout << c << ",";
    }
    cout << "]" << endl;

    return 0;
}
