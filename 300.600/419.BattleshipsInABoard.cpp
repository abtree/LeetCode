#include <iostream>
#include <vector>

using namespace std;

class BattleshipsInABoard{
public:
    int countBattleships(vector<vector<char>>& board) {
        //标记法
        m = board.size();
        n = board[0].size();
        int cnt = 0;
        for (int i = 0; i < m;++i) {
            for (int j = 0; j < n;++j) {
                if (board[i][j] == 'X') {
                    ++cnt;
                    goon(board, i, j);
                }
            }
        }
        return cnt;
    }
private:
    void goon(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if (board[i][j] == 'X') {
            board[i][j] = '.';
            goon(board, i - 1, j);
            goon(board, i + 1, j);
            goon(board, i, j + 1);
            goon(board, i, j - 1);
        }
    }
private:
    int m{};
    int n{};
public:
    int countBattleships2(vector<vector<char>>& board) {
        //相邻识别法
        m = board.size();
        n = board[0].size();
        int cnt = 0;
        for (int i = 0; i < m;++i) {
            for (int j = 0; j < n;++j) {
                if (board[i][j] == '.')
                    continue;
                if (i > 0 && board[i - 1][j] == 'X')
                    continue;   //已经统计过了
                if (j > 0 && board[i][j-1] == 'X')
                    continue;   //已经统计过了
                ++cnt;
            }
        }
        return cnt;
    }
};



int main(int argc, char const* argv[]) {
    BattleshipsInABoard cls;
    cout << cls.countBattleships2(vector<vector<char>>{ {'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}}) << " -> 2" << endl;
    cout << cls.countBattleships2(vector<vector<char>>{ {'.'}}) << "-> 0" << endl;
    return 0;
}
