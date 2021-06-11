#include <iostream>
#include <vector>
using namespace std;

// 289. 生命游戏
class GameOfLife {
    /* 生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
    如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
    如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
    如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
    如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
    下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 m x n 网格面板 board 的当前状态，返回下一个状态。
    */
public:
    void gameOfLife(vector<vector<int>>& board) {
        int col = board.size();
        int row = board[0].size();
        //2表示需要改为0； -1表示需要改为1
        for(int i =0; i< col; ++i){
            for(int j=0;j<row;++j){
                int cnt = 0;
                //统计活细胞数
                if (i - 1 >=0){
                    if(j-1>=0 && board[i-1][j-1] > 0)
                        ++cnt;
                    if(board[i-1][j] > 0)
                        ++cnt;
                    if(j+1<row && board[i-1][j+1] > 0)
                        ++cnt;
                }
                if(i+1<col){
                    if(j-1>=0 && board[i+1][j-1] > 0)
                        ++cnt;
                    if(board[i+1][j] > 0)
                        ++cnt;
                    if(j+1<row && board[i+1][j+1] > 0)
                        ++cnt;
                }
                if(j-1>=0 && board[i][j-1] > 0)
                    ++cnt;
                if(j+1<row && board[i][j+1] > 0)
                    ++cnt;

                if(board[i][j] == 0){
                    if(cnt == 3)
                        board[i][j] = -1;
                }else{
                    if(cnt < 2 || cnt > 3)
                        board[i][j] = 2;
                }
            }
        }
        for(int i =0; i< col; ++i){
            for(int j=0;j<row;++j){
                if(board[i][j] == 2){
                    board[i][j] = 0;
                }else if(board[i][j] == -1){
                    board[i][j] = 1;
                }
            }
        }
    }
};

int main(int argc, char const *argv[]){
    GameOfLife cls;
    vector<vector<int>> matrix{
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    cls.gameOfLife(matrix);
    cout << "[";
    for (auto &it : matrix){
        cout <<"[";
        for(auto i : it){
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    vector<vector<int>> matrix1{
        {1,1},
        {1,0},
    };
    cls.gameOfLife(matrix1);
    cout << "[";
    for(auto &it : matrix1){
        cout <<"[";
        for(auto i : it){
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    return 0;
}
