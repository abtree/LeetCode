#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

#define START "JFK"

// 332. 重新安排行程
class ReconstructItinerary {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> dp;
        for (auto& vec : tickets) {
            dp[vec[0]].emplace(vec[1]);
        }
        vector<string> ret;
        dfs(dp, ret, START);
        reverse(ret.begin(), ret.end());
        return ret;
    }
private:
    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& dp, vector<string>& ret, const string& curr) {
        while (dp.count(curr) && dp[curr].size() > 0) {
            string c = dp[curr].top();
            dp[curr].pop();
            dfs(dp, ret, c);
        }
        ret.push_back(curr);
    }
};

int main(int argc, char const* argv[]) {
    ReconstructItinerary cls;
    auto& ret = cls.findItinerary(vector<vector<string>>{
        {"MUC", "LHR"}, { "JFK","MUC" }, { "SFO","SJC" }, { "LHR","SFO" }
    });
    cout << "[";
    for (auto& it : ret) {
        cout << it.c_str() << " , ";
    }
    cout << "]" << endl;

    auto& ret1 = cls.findItinerary(vector<vector<string>>{
        {"JFK", "SFO"}, { "JFK","ATL" }, { "SFO","ATL" }, { "ATL","JFK" }, { "ATL","SFO" }
    });
    cout << "[";
    for (auto& it : ret1) {
        cout << it.c_str() << " , ";
    }
    cout << "]" << endl;

    return 0;
}
