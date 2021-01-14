#include<iostream>
#include<vector>
using namespace std;

//73. 矩阵置零
class SetMatrixZeroes {
    /*
    给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

    示例 1:
    输入:
    [
      [1,1,1],
      [1,0,1],
      [1,1,1]
    ]
    输出:
    [
      [1,0,1],
      [0,0,0],
      [1,0,1]
    ]

    示例 2:
    输入:
    [
      [0,1,2,0],
      [3,4,5,2],
      [1,3,1,5]
    ]
    输出:
    [
      [0,0,0,0],
      [0,4,5,0],
      [0,3,1,0]
    ]
    */
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int c = matrix.size();
        if (c == 0)
            return;
        int r = matrix[0].size();
        vector<int> zi; //记录列标记(被标记的列整列都要置为0)
        vector<int> zj; //记录行标记(被标记的行整行都要置为0)
        for (int i = 0; i < c;++i) {
            for (int j = 0; j < r;++j) {
                if (matrix[i][j] == 0) {
                    zi.push_back(i);    //标记该列需要置0
                    zj.push_back(j);    //标记该行需要置0
                }
            }
        }
        for (int i : zi) {
            for (int j = 0; j < r;++j) {
                matrix[i][j] = 0;       //将被标记的列置0
            }
        }
        for (int j : zj) {
            for (int i = 0; i < c;++i) {
                matrix[i][j] = 0;       //将被标记的行置0
            }
        }
    }
};

int main() {
    SetMatrixZeroes cls;
    vector<vector<int>> m3{
        {1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}
    };
    cls.setZeroes(m3);
    cout << "[" << endl;
    for (auto& it : m3) {
        cout << "[";
        for (int i : it) {
            cout << i << ",";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl << endl;

    vector<vector<int>> m1{
        {1,1,1},{1,0,1},{1,1,1}
    };
    cls.setZeroes(m1);
    cout << "[" << endl;
    for (auto& it : m1) {
        cout << "[";
        for (int i : it) {
            cout << i << ",";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl << endl;

    vector<vector<int>> m2{
        {0,1,2,0},{3,4,5,2},{1,3,1,5}
    };
    cls.setZeroes(m2);
    cout << "[" << endl;
    for (auto& it : m2) {
        cout << "[";
        for (int i : it) {
            cout << i << ",";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl << endl;
    return 0;
}