#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//54. 螺旋矩阵
class SpiralMatrix {
    /*
    给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

    示例 1:
    输入:
    [
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
    ]
    输出: [1,2,3,6,9,8,7,4,5]

    示例 2:
    输入:
    [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9,10,11,12]
    ]
    输出: [1,2,3,4,8,12,11,10,9,5,6,7]

    */
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //按层模拟
        int r = matrix.size();
        if (r <= 0)
            return vector<int>{};
        int c = matrix[0].size();
        if (c <= 0)
            return vector<int>{};
        vector<int> ret(r * c, 0);
        int pos = 0;
        int end = min((r - 1) / 2, (c - 1) / 2);
        int re = 0;
        int ce = 0;
        for (int margin = 0; margin <= end; ++margin) {
            //先处理上面一行
            for (int pc = margin; pc < c - margin; ++pc) {
                ret[pos] = matrix[margin][pc];
                ++pos;
            }
            ce = c - margin - 1;
            re = r - margin - 1;
            for (int pr = margin + 1;pr < re;++pr) {
                ret[pos] = matrix[pr][ce];
                ++pos;
            }
            if (re != margin) {
                for (int pc = ce; pc >= margin;--pc) {
                    ret[pos] = matrix[re][pc];
                    ++pos;
                }
            }
            if (ce != margin) {
                for (int pr = re - 1; pr >= margin + 1;--pr) {
                    ret[pos] = matrix[pr][margin];
                    ++pos;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[])
{
    SpiralMatrix cls;

    vector<vector<int>> vec32{
        {2,5,8},
        {4,0,-1},
    };
    auto ret32 = cls.spiralOrder(vec32);
    cout << "[";
    for (auto i : ret32) {
        cout << i << ",";
    }
    cout << "]" << endl;

    vector<vector<int>> vec33{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    auto ret33 = cls.spiralOrder(vec33);
    cout << "[";
    for (auto i : ret33) {
        cout << i << ",";
    }
    cout << "]" << endl;

    vector<vector<int>> vec34{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    auto ret34 = cls.spiralOrder(vec34);
    cout << "[";
    for (auto i : ret34) {
        cout << i << ",";
    }
    cout << "]" << endl;
    return 0;
}
