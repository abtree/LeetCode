#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <unordered_map>
using namespace std;

class FreedomTrail
{
public:
    int findRotateSteps(string ring, string key)
    {
        int n = ring.size(), m = key.size();
        array<vector<int>, 26> pos;
        for (int i = 0; i < n; ++i)
        {
            pos[ring[i] - 'a'].push_back(i);
        }
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (auto &i : pos[key[0] - 'a'])
        {
            dp[0][i] = min(i, n - i) + 1;
        }
        for (int i = 1; i < m; ++i)
        {
            for (auto j : pos[key[i] - 'a'])
            {
                for (auto k : pos[key[i - 1] - 'a'])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
        }
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};

class FreedomTrail1
{
public:
    // 用递归求解 （会超时）
    int findRotateSteps(string ring, string key)
    {
        pos.clear();
        mRing = ring;
        mKey = key;
        n = ring.size();
        m = key.size();
        for (int i = 0; i < n; ++i)
        {
            pos[ring[i]].push_back(i);
        }
        return doring(0, 0, m);
    }

private:
    int doring(int x, int i, int ans)
    {
        if (i >= m)
        {
            return ans;
        }
        auto &p = pos[mKey[i]];
        int size = p.size();
        int d = abs(p[0] - x);
        int ret = doring(p[0], i + 1, ans + min(d, n - d));
        for (int j = 1; j < size; ++j)
        {
            int d1 = abs(p[j] - x);
            ret = min(ret, doring(p[j], i + 1, ans + min(d1, n - d1)));
        }
        return ret;
    }

private:
    unordered_map<char, vector<int>> pos;
    string mRing{};
    string mKey{};
    int n{};
    int m{};
};

int main(int argc, char const *argv[])
{
    FreedomTrail1 cls;
    cout << cls.findRotateSteps("caotmcaataijjxi", "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx") << " -> 137" << endl;
    cout << cls.findRotateSteps("iotfo", "fioot") << " -> 11" << endl;
    cout << cls.findRotateSteps("abcde", "ade") << " -> 6" << endl;
    cout << cls.findRotateSteps("godding", "gd") << " -> 4" << endl;
    cout << cls.findRotateSteps("godding", "godding") << " -> 13" << endl;
    return 0;
}
