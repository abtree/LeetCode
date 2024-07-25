#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class OutOfBoundaryPaths
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        //计算上边界情况
        long long ret = 0;
        //计算上下边界情况
        int disUp = abs(startColumn - 0);
        int disDown = abs(n - startColumn-1);
        for(int i = 0;i<m;++i){
            //计算到起点格子的距离
            int dis = abs(i - startRow);
            if (dis+disUp < maxMove){
                ++ret;
            }
            if (dis+disDown < maxMove){
                ++ret;
            }
        }
        //计算左右边界情况
        int disLeft = abs(startRow - 0);
        int disRight = abs(n - startRow-1);
        for(int i = 0;i<n;++i){
            //计算到起点格子的距离
            int dis = abs(i - startColumn);
            if (dis+disLeft < maxMove){
                ++ret;
            }
            if (dis+disRight < maxMove){
                ++ret;
            }
        }
        return ret % (long long)(1e9+7);
    }
public:
    static constexpr int MOD = 100'000'007;
    int findPaths1(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dirs{{-1,  0},{0, -1},{1, 0},{0,1}};
        int outDirs = 0;
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m, vector<int>(n)));
        dp[0][startRow][startColumn] = 1;
        for (int i = 0; i< maxMove; ++i){
            for(int j = 0; j< m; ++j){
                for(int k = 0; k< n;++k){
                    int start = dp[i][j][k];
                    if (start > 0){
                        for (auto& dir : dirs){
                            int j1 = j+dir[0];
                            int k1 = k+dir[1];
                            if (j1 < 0 || j1 >= m || k1 < 0 || k1 >= n){
                                outDirs = (outDirs + start) % MOD;
                            }else{
                                dp[i+1][j1][k1] = (dp[i+1][j1][k1] + start) % MOD;
                            } 
                        }
                    }
                }
            }
        } 
        return outDirs;
    }
};

int main(int argc, char const *argv[])
{
    OutOfBoundaryPaths cls;
    cout << cls.findPaths1(2,2,2,0,0) << " -> 6" << endl;
    cout << cls.findPaths1(1,3,3,0,1) << " -> 12" << endl;
    return 0;
}
