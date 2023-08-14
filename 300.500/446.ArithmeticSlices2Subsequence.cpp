#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class ArithmeticSlices2Subsequence
{
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        dp.clear();
        ret = 0;
        dfs(nums, 0);
        return ret;
    }
private:
    void dfs(vector<int>& nums, int i) {
        while (i < nums.size()) {
            dp.push_back(nums[i]);
            int size = dp.size();
            if (size < 3) {
                dfs(nums, i + 1);
            }
            else if (dp[size - 1] - dp[size - 2] == dp[size - 2] - dp[size - 3]) {
                ++ret;
                dfs(nums, i + 1);
            }
            dp.pop_back();
            ++i;
        }
    }
private:
    int ret{};
    vector<long long> dp;
public:
    int numberOfArithmeticSlices1(vector<int>& nums) {
        int ret = 0;
        vector<unordered_map<long long, int>> dp(nums.size());
        for (int i = 0;i < nums.size();++i) {
            for (int j = 0;j < i;++j) {
                long long d = 1ll * nums[i] - nums[j];
                auto it = dp[j].find(d);
                int cnt = it == dp[j].end() ? 0 : it->second;
                ret += cnt;
                dp[i][d] += cnt + 1;
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[])
{
    ArithmeticSlices2Subsequence cls;
    cout << cls.numberOfArithmeticSlices1(vector<int>{2, 4, 6, 8, 10}) << " -> 7" << endl;
    cout << cls.numberOfArithmeticSlices1(vector<int>{7, 7, 7, 7, 7}) << " -> 16" << endl;
    return 0;
}
