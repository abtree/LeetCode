#include <iostream>
#include <vector>
using namespace std;

class Minesweeper
{
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, const vector<int> &click)
    {
        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        bfs(board, click[0], click[1]);
        return board;
    }

private:
    void bfs(vector<vector<char>> &board, int x, int y)
    {
        int cnt = 0;
        for (int i = 0; i < 8; ++i)
        {
            int tx = x + dirX[i];
            int ty = y + dirY[i];
            if (tx >= 0 && tx < board.size() && ty >= 0 && ty < board[0].size() && board[tx][ty] == 'M')
            {
                ++cnt;
            }
        }
        if (cnt > 0)
        {
            board[x][y] = cnt + '0';
            return;
        }
        board[x][y] = 'B';
        for (int i = 0; i < 8; ++i)
        {
            int tx = x + dirX[i];
            int ty = y + dirY[i];
            if (tx >= 0 && tx < board.size() && ty >= 0 && ty < board[0].size() && board[tx][ty] == 'E')
            {
                bfs(board, tx, ty);
            }
        }
    }

private:
    vector<int> dirX{0, 0, 1, -1, 1, 1, -1, -1};
    vector<int> dirY{1, -1, 0, 0, 1, -1, 1, -1};
};
void print(const vector<vector<char>> &board)
{
    cout << "[" << endl;
    for (auto &v : board)
    {
        cout << "[";
        for (auto x : v)
        {
            cout << x << ",";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    Minesweeper cls;
    vector<vector<char>> board{
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}};
    board = cls.updateBoard(board, vector<int>{3, 0});
    print(board);
    board = cls.updateBoard(board, vector<int>{1, 2});
    print(board);
    return 0;
}
