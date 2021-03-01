#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

//79. 单词搜索
class WordSearch {
    /*
    给定一个二维网格和一个单词，找出该单词是否存在于网格中。
    单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

    示例:
    board =
    [
    ['A','B','C','E'],
    ['S','F','C','S'],
    ['A','D','E','E']
    ]
    给定 word = "ABCCED", 返回 true
    给定 word = "SEE", 返回 true
    给定 word = "ABCB", 返回 false

    提示：
    board 和 word 中只包含大写和小写英文字母。
    1 <= board.length <= 200
    1 <= board[i].length <= 200
    1 <= word.length <= 10^3
    */
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
            return true;

        int c = board.size();
        if (c == 0)
            return false;
        int r = board[0].size();

        vector<vector<int>> flag(c, vector<int>(r, 0)); //记录使用过的点
        for (int i = 0; i < c;++i) {
            for (int j = 0; j < r;++j) {
                if (board[i][j] == word[0]) {
                    flag[i][j] = 1;
                    if (goon(board, word, flag, i, j, 1))
                        return true;    //找到了
                    flag[i][j] = 0;
                }
            }
        }
        return false;
    }
private:
    bool goon(vector<vector<char>>& board, string& word, vector<vector<int>>& flag, int i, int j, int k) {
        if (k >= word.size())
            return true;

        if (i > 0 && flag[i - 1][j] == 0) {  //向上
            if (board[i - 1][j] == word[k]) {
                flag[i - 1][j] = 1;
                if (goon(board, word, flag, i - 1, j, k + 1))
                    return true;
                flag[i - 1][j] = 0;
            }
        }
        if (j > 0 && flag[i][j - 1] == 0) {  //向左 
            if (board[i][j - 1] == word[k]) {
                flag[i][j - 1] = 1;
                if (goon(board, word, flag, i, j - 1, k + 1))
                    return true;
                flag[i][j - 1] = 0;
            }
        }
        if (i + 1 < board.size() && flag[i + 1][j] == 0) {  //向下 
            if (board[i + 1][j] == word[k]) {
                flag[i + 1][j] = 1;
                if (goon(board, word, flag, i + 1, j, k + 1))
                    return true;
                flag[i + 1][j] = 0;
            }
        }
        if (j + 1 < board[0].size() && flag[i][j + 1] == 0) {  //向右 
            if (board[i][j + 1] == word[k]) {
                flag[i][j + 1] = 1;
                if (goon(board, word, flag, i, j + 1, k + 1))
                    return true;
                flag[i][j + 1] = 0;
            }
        }
        return false;
    }
};

int main() {
    WordSearch cls;

    vector<vector<char>> board2{
        {'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}
    };
    cout << boolalpha << cls.exist(board2, "ABCESEEEFS") << " -> true" << endl;

    vector<vector<char>> board1{
        {'a','a','a','a'},{'a','a','a','a'},{'a','a','a','a'}
    };
    cout << boolalpha << cls.exist(board1, "aaaaaaaaaaaaa") << " -> false" << endl;

    vector<vector<char>> board{
        {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}
    };
    cout << boolalpha << cls.exist(board, "ABCCED") << " -> true" << endl;
    cout << boolalpha << cls.exist(board, "SEE") << " -> true" << endl;
    cout << boolalpha << cls.exist(board, "ABCB") << " -> false" << endl;
    return 0;
}