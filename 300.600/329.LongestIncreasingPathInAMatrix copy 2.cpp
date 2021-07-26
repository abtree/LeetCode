#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//329. 矩阵中的最长递增路径
class LongestIncreasingPathInAMatrix {
    /* 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
    */
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //存储已经遍历过的点
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ret = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                ret = max(ret, longest(matrix, dp, i, j));
            }
        }
        return ret;
    }
private:
    int longest(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y) {
        if (dp[x][y] > -1)
            return dp[x][y];    //已经查询过的点
        int m = matrix.size();
        int n = matrix[0].size();
        dp[x][y] = 1;
        if (x - 1 > -1 && matrix[x - 1][y] > matrix[x][y]) {
            dp[x][y] = max(dp[x][y], longest(matrix, dp, x - 1, y) + 1);
        }
        if (x + 1 < m && matrix[x + 1][y] > matrix[x][y]) {
            dp[x][y] = max(dp[x][y], longest(matrix, dp, x + 1, y) + 1);
        }
        if (y - 1 > -1 && matrix[x][y - 1] > matrix[x][y]) {
            dp[x][y] = max(dp[x][y], longest(matrix, dp, x, y - 1) + 1);
        }
        if (y + 1 < n && matrix[x][y + 1] > matrix[x][y]) {
            dp[x][y] = max(dp[x][y], longest(matrix, dp, x, y + 1) + 1);
        }
        return dp[x][y];
    }
};

int main(int argc, char const* argv[]) {
    LongestIncreasingPathInAMatrix cls;
    cout << cls.longestIncreasingPath(vector<vector<int>>{
        {9, 9, 4}, { 6,6,8 }, { 2,1,1 }
    }) << " -> 4" << endl;
    cout << cls.longestIncreasingPath(vector<vector<int>>{
        {3, 4, 5}, { 3,2,6 }, { 2,2,1 }
    }) << " -> 4" << endl;
    cout << cls.longestIncreasingPath(vector<vector<int>>{ {1}}) << " -> 1" << endl;
    return 0;
}
