#include <iostream>
#include <vector>
using namespace std;

//240. 搜索二维矩阵 II
class SearchA2dMatrix2 {
    /* 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：每行的元素从左到右升序排列。每列的元素从上到下升序排列。
    */
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //暴力法 （由于只需要遍历一次矩阵 性能消耗上是可以接受的）
        int col = matrix.size();
        if (col <= 0)
            return false;
        int row = matrix[0].size();
        for (int i = 0;i < col; ++i) {
            for (int j = 0; j < row;++j) {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
public:
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        //列暴力 行2分 法(这个可以优化为: min(col, row)用暴力法 max(col, row)用2分 性能更好)
        int col = matrix.size();
        if (col <= 0)
            return false;
        int row = matrix[0].size();
        for (int i = 0; i < col; ++i) {
            if (matrix[i][row - 1] < target)
                continue;
            if (matrix[i][0] > target)
                return false;
            if (searchVertical(matrix, target, i))
                return true;
        }
        return false;
    }
private:
    bool searchVertical(vector<vector<int>>& matrix, int target, int i) {
        int start = 0;
        int end = matrix[0].size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (matrix[i][mid] == target)
                return true;
            if (matrix[i][mid] > target)
                end = mid;
            else
                start = mid + 1;
        }
        return false;
    }
public:
    bool searchMatrix3(vector<vector<int>>& matrix, int target) {
        //双指针法 row 先指向 row max, col指向0
        int row = matrix.size() - 1;
        int col = 0;
        int colmax = matrix[0].size();
        while (row >= 0 && col < colmax) {
            if (matrix[row][col] > target) {
                --row;
            }
            else if (matrix[row][col] < target) {
                ++col;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const* argv[]) {
    SearchA2dMatrix2 cls;
    vector<vector<int>> matrix{
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    cout << boolalpha << cls.searchMatrix3(matrix, 5) << " -> true" << endl;
    cout << boolalpha << cls.searchMatrix3(matrix, 20) << " -> false" << endl;
    return 0;
}