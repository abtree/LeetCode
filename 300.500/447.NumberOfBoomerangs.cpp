#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class NumberOfBoomerangs
{
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<long long, int> dp;
        int n = points.size();
        int ret = 0;
        for (int i = 0;i < n;++i) {
            dp.clear();
            for (int j = 0;j < n;++j) {
                if (j != i) {
                    long long x = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                    ++dp[x];
                }
            }
            for (auto x : dp) {
                if (x.second > 1) {
                    // A(n,m)
                    ret += multito(x.second) / multito(x.second - 2);
                }
            }
        }
        return ret;
    }
private:
    int multito(int x) {
        int ret = 1;
        while (x > 1) {
            ret *= x;
            --x;
        }
        return ret;
    }
};

int main(int argc, char const* argv[])
{
    NumberOfBoomerangs cls;
    cout << cls.numberOfBoomerangs(vector<vector<int>>{ {0, 0}, { 1,0 }, { -1,0 }, { 0,1 }, {0,-1}}) << " -> 20" << endl;
    cout << cls.numberOfBoomerangs(vector<vector<int>>{ {0, 0}, { 1,0 }, { 2,0 }}) << " -> 2" << endl;
    cout << cls.numberOfBoomerangs(vector<vector<int>>{ {1, 1}, { 2,2 }, { 3,3 }}) << " -> 2" << endl;
    cout << cls.numberOfBoomerangs(vector<vector<int>>{ {0, 0}}) << " -> 0" << endl;
    return 0;
}
