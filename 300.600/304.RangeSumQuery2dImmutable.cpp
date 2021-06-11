#include <iostream>
#include <vector>
using namespace std;

//304. 二维区域和检索 - 矩阵不可变
class NumMatrix {
    /* 给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2) 。
    */
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int col = matrix.size();
        int row = matrix[0].size();
        data.resize(col, vector<int>(row, 0));
        data[0][0] = matrix[0][0];
        for (int j = 1; j < row;++j) {
            data[0][j] = data[0][j - 1] + matrix[0][j];
        }
        for (int i = 1;i < col;++i) {
            data[i][0] = data[i - 1][0] + matrix[i][0];
        }
        for (int i = 1; i < col;++i) {
            for (int j = 1;j < row;++j) {
                data[i][j] = data[i - 1][j] + data[i][j - 1] - data[i - 1][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) {
            return data[row2][col2];
        }
        if(row1 == 0){
            return data[row2][col2]-data[row2][col1-1];
        }
        if(col1 == 0){
            return data[row2][col2]-data[row1-1][col2];
        }
        return data[row2][col2] - data[row2][col1-1] - data[row1-1][col2] + data[row1-1][col1-1];
    }
private:
    vector<vector<int>> data;
};

int main(int argc, char const *argv[]){
    NumMatrix cls(vector<vector<int>>{
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    });
    cout << cls.sumRegion(2,1,4,3) << "->8"<<endl;
    cout << cls.sumRegion(1,1,2,2) << "->11"<<endl;
    cout << cls.sumRegion(1,2,2,4) << "->12"<<endl;
    return 0;
}

