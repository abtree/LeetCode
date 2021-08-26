#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class MaxSumOfRectangleNoLargerThanK {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m;++i) {    //区间行上标
            vector<int> sum(n, 0);
            for (int j = i; j < m;++j) {    //区间行下标
                for (int c = 0; c < n;++c) {
                    sum[c] += matrix[j][c]; //区间内列合
                }
                set<int> sunSet{ 0 };   //这里默认填入一个0,方便后面计算s-lb
                int s = 0;
                for (auto v : sum) {
                    s += v;
                    auto lb = sunSet.lower_bound(s - k);    //s - lb <= k => s - k <= lb
                    if (lb != sunSet.end()) {
                        ans = max(ans, s - *lb);
                    }
                    sunSet.insert(s);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const* argv[])
{
    MaxSumOfRectangleNoLargerThanK cls;
    cout << cls.maxSumSubmatrix(vector<vector<int>>{ {1, 0, 1}, { 0,-2,3 }}, 2) << " -> 2" << endl;
    cout << cls.maxSumSubmatrix(vector<vector<int>>{ {2, 2, -1}}, 3) << " -> 3" << endl;
    return 0;
}
