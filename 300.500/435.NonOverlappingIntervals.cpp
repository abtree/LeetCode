#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NonOverlappingIntervals {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //先按左区间排序，将问题简化
        sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r) -> bool {
            return l[0] < r[0];
            });
        vector<vector<int>> dp;
        dp.push_back({ intervals[0][0], intervals[0][1] });
        for (int i = 1;i < intervals.size();++i) {
            if (intervals[i][0] >= dp.back()[1]) {
                //没有重叠部分
                dp.push_back({ intervals[i][0], intervals[i][1] });
                continue;
            }
            //贪心算法 保证右区间尽量小
            if (intervals[i][1] < dp.back()[1]) {
                //替换掉原来的区间
                dp.pop_back();
                dp.push_back({ intervals[i][0], intervals[i][1] });
            }
        }
        return intervals.size() - dp.size();
    }
public:
    int eraseOverlapIntervals1(vector<vector<int>>& intervals) {
        //先按左区间排序，将问题简化
        sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r) -> bool {
            return l[0] < r[0];
            });
        //动态规划（会超时）
        int n = intervals.size();
        vector<int> dp(n, 1);
        for (int i = 1;i < n;++i) {
            //这里只需要判断包含第i个元素（作为结尾）的情况
            for (int j = 0; j < i;++j) {
                if (intervals[i][0] >= intervals[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return n - *max_element(dp.begin(), dp.end());
    }
};

int main(int argc, char const* argv[]) {
    NonOverlappingIntervals cls;
    cout << cls.eraseOverlapIntervals1(vector<vector<int>>{ {1, 2}, { 2,3 }, { 3,4 }, { 1,3 }}) << " -> 1" << endl;
    cout << cls.eraseOverlapIntervals1(vector<vector<int>>{ {1, 2}, { 1,2 }, { 1,2 }}) << " -> 2" << endl;
    cout << cls.eraseOverlapIntervals1(vector<vector<int>>{ {1, 2}, { 2,3 }}) << " -> 0" << endl;
    return 0;
}
