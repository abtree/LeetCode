#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//221. 最大正方形
class MaximalSquare{
    /* 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
    */
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int col = matrix.size();
        if(col <= 0)
            return 0;
        int row = matrix[0].size();
        int ret = 0;
        for (int i = 0; i < col; ++i){
            for (int j = 0; j<row;++j){
                if(matrix[i][j] == '1'){
                    ret = max(ret, bfs(matrix, i, j));
                }
            }
        }
        return ret;
    }
private:
    int bfs(vector<vector<char>>& matrix, int i, int j){
        int ret = 1;
        while(i + ret < matrix.size() && j + ret < matrix[0].size()){
            int end = i+ret;
            for(int k = i; k <= end; ++k){
                if(matrix[k][j+ret] == '0')
                    return ret * ret;
            }
            end = j + ret;
            for(int k = j; k < end; ++k){
                if(matrix[i+ret][k] == '0')
                    return ret * ret;
            }
            ++ret;
        }
        return ret*ret;
    }
public:
    int maximalSquare2(vector<vector<char>>& matrix) {
        /* 动态规划
           dp[i,j]表示已i,j为右下角的全为'1'的矩阵(dp[i,j]最大值的平方即为解)
           状态转移方程 dp[i,j] = min(dp[i,j-1],dp[i-1,j-1],dp[i-1,j]) + 1
        */
        int col = matrix.size();
        if(col <= 0)
            return 0;
        int row = matrix[0].size();
        int ret = 0;
        vector<vector<int>> dp(col, vector<int>(row, 0));
        for(int i = 0;i < col; ++i){
            if(matrix[i][0] == '1'){
                dp[i][0] = 1;
                ret = 1;
            }
        }
        for(int i = 1;i < row; ++i){
            if(matrix[0][i] == '1'){
                dp[0][i] = 1;
                ret = 1;
            }
        }
        for (int i = 1;i < col; ++i){
            for (int j =1 ;j < row;++j){
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
                ret = max(ret, dp[i][j]);
            }
        }
        return ret*ret;
    }
};

int main(int argc, char const *argv[])
{
    MaximalSquare cls;
    cout << cls.maximalSquare2(vector<vector<char>>{
        {'0','1'}
    }) << " -> 1" << endl;

    cout << cls.maximalSquare2(vector<vector<char>>{
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    }) << " -> 4" << endl;

    cout << cls.maximalSquare2(vector<vector<char>>{
        {'0','1'},
        {'1','0'}
    }) << " -> 1" << endl;

    cout << cls.maximalSquare2(vector<vector<char>>{{'0'}}) << " -> 0" << endl;
    return 0;
}
