#include <iostream>
#include <vector>

using namespace std;

//130. 被围绕的区域
class SurroundedRegions
{
    /*给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
    */
public:
    void solve(vector<vector<char>>& board) {
        int col = board.size();
        if (col < 3)
            return;
        int row = board[0].size();
        if (row < 3)
            return;
        vector<vector<int>> dp(col, vector<int>(row, 0));
        //先标记不能转变的'O'点
        prepare(dp, board);
        //将能转变的'O'点转变为'X'点
        for (int i = 1; i < col - 1;++i) {
            for (int j = 1; j < row - 1; ++j) {
                if (board[i][j] == 'X')
                    continue;
                if (dp[i][j] == 1)
                    continue;
                board[i][j] = 'X';
            }
        }
    }
private:
    enum class Direct {
        UP,
        DOWN,
        Left,
        Right
    };
private:
    void prepare(vector<vector<int>>& dp, vector<vector<char>>& board) {
        int col = board.size();
        int row = board[0].size();
        for (int i = 0;i < row;++i) {
            if (board[0][i] == 'O') {
                dp[0][i] == 1;
                goFromPoint(dp, board, 1, i, Direct::DOWN);
            }
        }
        for (int i = 0;i < row;++i) {
            if (board[col - 1][i] == 'O') {
                dp[col - 1][i] == 1;
                goFromPoint(dp, board, col - 2, i, Direct::UP);
            }
        }
        for (int i = 1; i < col - 1;++i) {
            if (board[i][0] == 'O') {
                dp[i][0] = 1;
                goFromPoint(dp, board, i, 1, Direct::Right);
            }
        }
        for (int i = 1; i < col - 1;++i) {
            if (board[i][row - 1] == 'O') {
                dp[i][row - 1] = 1;
                goFromPoint(dp, board, i, row - 2, Direct::Left);
            }
        }
    }
    void goFromPoint(vector<vector<int>>& dp, vector<vector<char>>& board, int i, int j, Direct dir) {
        if (board[i][j] == 'X')
            return; //此路不通
        if (dp[i][j] == 1)
            return; //已经判断过此路
        dp[i][j] = 1;
        if (i > 1 && dir != Direct::DOWN) {
            goFromPoint(dp, board, i - 1, j, Direct::UP);
        }
        if (i < board.size() - 2 && dir != Direct::UP) {
            goFromPoint(dp, board, i + 1, j, Direct::DOWN);
        }
        if (j > 1 && dir != Direct::Right) {
            goFromPoint(dp, board, i, j - 1, Direct::Left);
        }
        if (j < board[0].size() - 2 && dir != Direct::Left) {
            goFromPoint(dp, board, i, j + 1, Direct::Right);
        }
    }
};

int main(int argc, char const* argv[])
{
    SurroundedRegions cls;

    vector<vector<char>> martix{
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    cls.solve(martix);
    cout << "[";
    for (auto& it : martix) {
        cout << "[";
        for (auto i : it) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    vector<vector<char>> martix1{
        {'X','O','X','O','X','O'},
        {'O','X','O','X','O','X'},
        {'X','O','X','O','X','O'},
        {'O','X','O','X','O','X'}
    };
    cls.solve(martix1);
    cout << "[";
    for (auto& it : martix1) {
        cout << "[";
        for (auto i : it) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    vector<vector<char>> martix2{
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','X','X','X','X','O','O','O','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','O','O','O','X','O','X','O','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','O','X','O','X','O','X','O','O','O','X','X','X','X','X','X'},
        {'X','X','X','X','X','O','X','O','O','O','X','X','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','X','O','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
    };
    cls.solve(martix2);
    cout << "[";
    for (auto& it : martix2) {
        cout << "[";
        for (auto i : it) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    return 0;
}
