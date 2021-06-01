#include <iostream>
#include <vector>

using namespace std;

//200. 岛屿数量
class NumberOfIslands
{
    /* 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。此外，你可以假设该网格的四条边均被水包围。
    */
public:
    int numIslands(vector<vector<char>>& grid) {
        int col = grid.size();
        if (col <= 0)
            return 0;
        int row = grid[0].size();
        int ret = 0;
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < row; ++j) {
                if (grid[i][j] == '1') {
                    round(grid, i, j);
                    ++ret;
                }
            }
        }
        return ret;
    }
private:
    void round(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size())
            return;
        if (j < 0 || j >= grid[0].size())
            return;
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        round(grid, i - 1, j);
        round(grid, i + 1, j);
        round(grid, i, j - 1);
        round(grid, i, j + 1);
    }
};

int main(int argc, char const* argv[])
{
    NumberOfIslands cls;

    vector<vector<char>> grid2{
        {'1','1','1'},
        {'0','1','0'},
        {'1','1','1'}
    };
    cout << cls.numIslands(grid2) << " -> 1" << endl;

    vector<vector<char>> grid{
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << cls.numIslands(grid) << " -> 1" << endl;

    vector<vector<char>> grid1{
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << cls.numIslands(grid1) << " -> 3" << endl;
    return 0;
}
