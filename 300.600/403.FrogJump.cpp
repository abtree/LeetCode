#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class FrogJump{
public:
    bool canCross(vector<int>& stones) {
        //递归尝试
        if (stones.empty())
            return true;
        mEnd = stones.back();
        mDP.clear();
        for (int x : stones) {
            mDP[x];
        }
        return dfCross(0, 1, 1);
    }
private:
    bool dfCross(int pos, int stepmin, int stepmax) {
        if (pos == mEnd)
            return true;
        while (stepmin <= stepmax) {
            if (mDP.find(pos) == mDP.end()) {
                return false;
            }
            //该路径已经查询过了
            if (mDP[pos].find(stepmax) != mDP[pos].end()) {
                if (mDP[pos][stepmax])
                    return true;
                --stepmax;
                continue;
            }
            //该路径还没查询过
            mDP[pos][stepmax] = dfCross(pos + stepmax, max(1, stepmax - 1), stepmax + 1);
            if (mDP[pos][stepmax])
                return true;
            --stepmax;
        }
        return false;
    }
private:
    int mEnd{};
    unordered_map<int, unordered_map<int, bool>> mDP;   //通过记录已经查询过了路径来减少重复查找次数
};

class FrogJump2{
public:
    bool canCross(vector<int>& stones) {
        //动态规划
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = 1;
        for (int i = 1; i < n;++i) {
            //由于是单调递增序列 这两点之间一定是不可达的
            if (stones[i] - stones[i - 1] > i)
                return false;
        }
        for (int i = 1; i < n;++i) {
            for (int j = i - 1;j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k > j + 1)
                    break;  //距离太远 不可达
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if (i == n - 1 && dp[i][k]) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const* argv[]) {
    FrogJump2 cls;
    cout << boolalpha << cls.canCross(vector<int>{0,1,3,6,7}) << " -> false" << endl;
    cout << boolalpha << cls.canCross(vector<int>{0, 2147483647}) << " -> false" << endl;
    cout << boolalpha << cls.canCross(vector<int>{0, 1, 3, 5, 6, 8, 12, 17}) << " -> true" << endl;
    cout << boolalpha << cls.canCross(vector<int>{0,1,2,3,4,8,9,11}) << " -> false" << endl;
    return 0;
}
