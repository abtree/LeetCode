#include <iostream>
#include <vector>

using namespace std;

//64. 最小路径和
class MinimumPathSum {
    /*
    给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
    说明：每次只能向下或者向右移动一步。

    示例 1：
    输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
    输出：7
    解释：因为路径 1→3→1→1→1 的总和最小。

    示例 2：
    输入：grid = [[1,2,3],[4,5,6]]
    输出：12
     
    提示：
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 200
    0 <= grid[i][j] <= 100
    */
public:
    int minPathSum(vector<vector<int>>& grid) {
        //通过动态规划计算出到每个格子的最短路径 最后一个格子就是需要的
        int c = grid.size();
        if (c == 0)
            return 0;
        int r = grid[0].size();
        for (int i = 0;i < c;++i) {
            for (int j = 0;j < r;++j) {
                if (i == 0 && j == 0)
                    continue;
                int min = INT_MAX;
                if (i > 0) {
                    min = grid[i - 1][j];
                }
                if (j > 0) {
                    if (min > grid[i][j - 1])
                        min = grid[i][j - 1];
                }
                grid[i][j] += min;
            }
        }
        return grid[c - 1][r - 1];
    }
};

int main(int argc, char const* argv[])
{
    MinimumPathSum cls;
    vector<vector<int>> maze{
        {1,3,1},{1,5,1},{4,2,1}
    };
    cout << cls.minPathSum(maze) << " -> 7" << endl;
    vector<vector<int>> maze1{
        {1,2,3},{4,5,6}
    };
    cout << cls.minPathSum(maze1) << " -> 12" << endl;
    return 0;
}
