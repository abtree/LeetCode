#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class BrickWall
{
public:
    int leastBricks(const vector<vector<int>> &wall)
    {
        int n = wall.size();
        int t = 0;
        for (int x : wall[0])
        {
            t += x;
        }
        unordered_map<int, int> dp;
        for (auto p : wall)
        {
            int s = 0;
            for (auto x : p)
            {
                s += x;
                if (s != t)
                {
                    dp[s]++;
                }
            }
        }
        int m = 0;
        for (auto it : dp)
        {
            m = max(m, it.second);
        }
        return n - m;
    }
};

int main(int argc, char const *argv[])
{
    BrickWall cls;
    cout << cls.leastBricks(vector<vector<int>>{{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}}) << " -> 2" << endl;
    cout << cls.leastBricks(vector<vector<int>>{{1}, {1}, {1}}) << " -> 3" << endl;
    return 0;
}
