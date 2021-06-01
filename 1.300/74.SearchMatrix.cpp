#include <iostream>
#include <vector>
using namespace std;

//74. 搜索二维矩阵
class SearchMatrix {
    /*
    编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
    每行中的整数从左到右按升序排列。
    每行的第一个整数大于前一行的最后一个整数。

    示例 1：
    输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    输出：true

    示例 2：
    输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    输出：false
    */
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size();
        if (size == 0)
            return false;
        //二分查找法
        int l = 0;
        int r = size - 1;
        int size1 = matrix[0].size() - 1;
        int mid = 0;
        while (l <= r) {
            mid = (r - l) / 2 + l;
            if (matrix[mid][0] == target)
                return true;
            if (matrix[mid][size1] < target)
                l = mid + 1;
            else if (matrix[mid][0] > target)
                r = mid - 1;
            else
                break;  //说明就在mid这一行
        }
        if (l > r)
            return false;
        //继续用二分查找法
        l = 0;
        r = size1;
        while (l <= r) {
            int mid1 = (r - l) / 2 + l;
            if (matrix[mid][mid1] == target)
                return true;
            if (matrix[mid][mid1] < target)
                l = mid1 + 1;
            else
                r = mid1 - 1;
        }
        return false;
    }
};

int main() {
    SearchMatrix cls;
    bool ret = cls.searchMatrix(vector<vector<int>>{
        {1, 3, 5, 7}, { 10,11,16,20 }, { 23,30,34,60 }
    }, 3);
    cout << boolalpha << ret << " -> true" << endl;

    ret = cls.searchMatrix(vector<vector<int>>{
        {1, 3, 5, 7}, { 10,11,16,20 }, { 23,30,34,60 }
    }, 13);
    cout << boolalpha << ret << " -> false" << endl;
    return 0;
}