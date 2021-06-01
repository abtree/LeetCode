#include <iostream>
#include <vector>
using namespace std;

//59. 螺旋矩阵 II
class SpiralMatrix2 {
    /*
    给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

    示例:
    输入: 3
    输出:
    [
    [ 1, 2, 3 ],
    [ 8, 9, 4 ],
    [ 7, 6, 5 ]
    ]
    */
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));

        int pos = 1;
        int end = (n - 1) / 2;
        int ce = 0;
        for (int margin = 0; margin <= end; ++margin) {
            //先处理上面一行
            for (int pc = margin; pc < n - margin; ++pc) {
                ret[margin][pc] = pos;
                ++pos;
            }
            ce = n - margin - 1;
            if (ce == margin)
                break;
            for (int pr = margin + 1;pr < ce;++pr) {
                ret[pr][ce] = pos;
                ++pos;
            }

            for (int pc = ce; pc >= margin;--pc) {
                ret[ce][pc] = pos;
                ++pos;
            }

            for (int pr = ce - 1; pr >= margin + 1;--pr) {
                ret[pr][margin] = pos;
                ++pos;
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[])
{
    SpiralMatrix2 cls;
    auto ret = cls.generateMatrix(3);
    cout << '[' << endl;
    for (auto& it : ret) {
        cout << '[';
        for (auto& it1 : it) {
            cout << it1 << ",";
        }
        cout << ']' << endl;
    }
    cout << ']' << endl;
    return 0;
}
