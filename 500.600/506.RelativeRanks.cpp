#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class RelativeRanks
{
public:
    vector<string> findRelativeRanks(const vector<int> &score)
    {
        int n = score.size();
        vector<pair<int, int>> dp;
        for (int i = 0; i < n; ++i)
        {
            dp.push_back({score[i], i});
        }
        sort(dp.begin(), dp.end());
        vector<string> ans(n);
        for (int i = n - 1; i >= 0; --i)
        {
            int j = n - i;
            if (j == 1)
            {
                ans[dp[i].second] = "Gold Medal";
            }
            else if (j == 2)
            {
                ans[dp[i].second] = "Silver Medal";
            }
            else if (j == 3)
            {
                ans[dp[i].second] = "Bronze Medal";
            }
            else
            {
                ans[dp[i].second] = to_string(j);
            }
        }
        return ans;
    }
};

void print(const vector<string> &ret)
{
    cout << "[";
    for (auto &x : ret)
    {
        cout << x.c_str() << " , ";
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    RelativeRanks cls;
    // [ "Gold Medal", "Silver Medal", "Bronze Medal", "4", "5" ]
    print(cls.findRelativeRanks(vector<int>{5, 4, 3, 2, 1}));
    // ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
    print(cls.findRelativeRanks(vector<int>{10, 3, 8, 9, 4}));
    return 0;
}
