#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class FindRightInterval
{
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        //记录原始下标
        kv.clear();
        for (int i = 0; i < intervals.size(); ++i) {
            kv[intervals[i][0]] = i;
        }
        //排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r)->bool {
            return l[0] < r[0];
            });
        //筛选
        vector<int> ret(intervals.size());
        for (int i = 0;i < intervals.size();++i) {
            int k = kv[intervals[i][0]];
            ret[k] = rightInterval(intervals, i);
        }
        return ret;
    }
private:
    int rightInterval(vector<vector<int>>& intervals, int start) {
        for (int j = start;j < intervals.size();++j) {
            if (intervals[j][0] >= intervals[start][1]) {
                return kv[intervals[j][0]];
            }
        }
        return -1;
    }
private:
    unordered_map<int, int> kv;
public:
    vector<int> findRightInterval1(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = make_pair(intervals[i][0], i);
        }
        sort(dp.begin(), dp.end());
        vector<int> ret(n, -1);
        for (int i = 0; i < n;++i) {
            auto it = lower_bound(dp.begin(), dp.end(), make_pair(intervals[i][1], 0));
            if (it != dp.end()) {
                ret[i] = it->second;
            }
        }
        return ret;
    }
};

void Print(vector<int>& ret) {
    cout << "[";
    for (auto x : ret) {
        cout << x << " ,";
    }
    cout << "]" << endl;
}

int main(int argc, char const* argv[]) {
    FindRightInterval cls;
    auto& ret1 = cls.findRightInterval1(vector<vector<int>>{ {1, 2}});
    Print(ret1);
    auto& ret2 = cls.findRightInterval1(vector<vector<int>>{ {3, 4}, { 2,3 }, { 1, 2 }});
    Print(ret2);
    auto& ret3 = cls.findRightInterval1(vector<vector<int>>{ {1, 4}, { 2,3 }, { 3,4 }});
    Print(ret3);
    return 0;
}
