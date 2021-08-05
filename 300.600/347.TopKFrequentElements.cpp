#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//347. 前 K 个高频元素
class TopKFrequentElements {
    /* 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
    */
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dp;
        for (auto x : nums) {
            dp[x] += 1;
        }

        auto func = [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            return a.first > b.first;
        };
        vector<pair<int, int>> dp1;
        for (auto& kv : dp) {
            dp1.emplace_back(kv.second, kv.first);
        }
        sort(dp1.begin(), dp1.end(), func);

        vector<int> ret(k, 0);
        for (int i = 0;i < k;++i) {
            ret[i] = dp1[i].second;
        }

        return ret;
    }
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    };
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        unordered_map<int, int> dp;
        for (auto x : nums) {
            dp[x] += 1;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> que(cmp);
        for (auto& kv : dp) {
            que.push(make_pair(kv.second, kv.first));
        }

        vector<int> ret(k, 0);
        for (int i = 0;i < k;++i) {
            ret[i] = que.top().second;
            que.pop();
        }

        return ret;
    }
};

int main(int argc, char const* argv[]) {
    TopKFrequentElements cls;
    auto& ret = cls.topKFrequent1(vector<int>{1, 1, 1, 2, 2, 3}, 2);
    cout << "[";
    for (int c : ret) {
        cout << c << " , ";
    }
    cout << "]" << endl;

    auto& ret1 = cls.topKFrequent1(vector<int>{1}, 1);
    cout << "[";
    for (int c : ret1) {
        cout << c << " , ";
    }
    cout << "]" << endl;

    return 0;
}
