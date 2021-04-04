#pragma once

//48. 旋转图像
class CRotateImage {
    /*
    给定一个 n × n 的二维矩阵表示一个图像。将图像顺时针旋转 90 度。
    你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

    示例 1:
    给定 matrix =
    [
        [1,2,3],
        [4,5,6],
        [7,8,9]
    ],
    原地旋转输入矩阵，使其变为:
    [
        [7,4,1],
        [8,5,2],
        [9,6,3]
    ]

    示例 2:
    给定 matrix =
    [
        [ 5, 1, 9,11],
        [ 2, 4, 8,10],
        [13, 3, 6, 7],
        [15,14,12,16]
    ],

    原地旋转输入矩阵，使其变为:
    [
        [15,13, 2, 5],
        [14, 3, 4, 1],
        [12, 6, 8, 9],
        [16, 7,10,11]
    ]
    */
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int end = n / 2;
        --n;
        for (int i = 0; i < end;++i) {
            for (int j = i; j < n - i; ++j) {
                //交换相应4个格子的值
                swap(matrix[i][j], matrix[j][n - i]); //0,0 <-> 0,3
                swap(matrix[i][j], matrix[n - j][i]); //0,0 <-> 3,0
                swap(matrix[n - j][i], matrix[n - i][n - j]); //3,0 <-> 3,3
            }
        }
    }
public:
    static void Test() {
        vector<vector<int>> dat{
            {1,2,3},
            {4,5,6},
            {7,8,9},
        };
        CRotateImage cls;
        cls.rotate(dat);
        cout << "[" << endl;
        for (auto& it : dat) {
            cout << "[";
            for (auto it1 : it) {
                cout << it1 << ",";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;

        vector<vector<int>> dat1{
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16},
        };
        cls.rotate(dat1);
        cout << "[" << endl;
        for (auto& it : dat1) {
            cout << "[";
            for (auto it1 : it) {
                cout << it1 << ",";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;


        vector<vector<int>> dat2{
                {1,2,3,4,5},
                {6,7,8,9,10},
                {11,12,13,14,15},
                {16,17,18,19,20},
                {21,22,23,24,25},
        };
        cls.rotate(dat2);
        cout << "[" << endl;
        for (auto& it : dat2) {
            cout << "[";
            for (auto it1 : it) {
                cout << it1 << ",";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;
    }
};