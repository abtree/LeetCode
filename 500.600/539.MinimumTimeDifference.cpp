#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MinimumTimeDifference
{
public:
    int findMinDifference(const vector<string> &timePoints)
    {
        int n = timePoints.size();
        if (n > 1440)
        {
            return 0;
        }
        vector<int> dp;
        for (auto &s : timePoints)
        {
            dp.push_back(convertToMin(s));
        }
        sort(dp.begin(), dp.end());
        int ans = 1440;
        for (int i = 1; i < n; ++i)
        {
            int x = dp[i] - dp[i - 1];
            ans = min(ans, x);
        }
        // 特殊情况(最后一个 和 第一个)
        int x = 1440 - dp[n - 1] + dp[0];
        ans = min(ans, x);
        return ans;
    }

private:
    int convertToMin(const string &s)
    {
        int h = atoi(s.c_str());
        int m = atoi(s.substr(s.find(":") + 1).c_str());
        return h * 60 + m;
    }
};

int main()
{
    MinimumTimeDifference cls;
    cout << cls.findMinDifference(vector<string>{"00:00", "04:00", "22:00"}) << " -> 120" << endl;
    cout << cls.findMinDifference(vector<string>{"23:59", "00:00"}) << " -> 1" << endl;
    cout << cls.findMinDifference(vector<string>{"00:00", "23:59", "00:00"}) << " -> 0" << endl;
    return 0;
}
