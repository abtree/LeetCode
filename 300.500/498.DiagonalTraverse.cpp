#include <iostream>
#include <vector>
using namespace std;

class DiagonalTraverse
{
public:
    vector<int> findDiagonalOrder(const vector<vector<int>> &mat)
    {
        vector<int> ret;
        int x = 0;
        int y = 0;
        int dx = -1;
        int dy = 1;
        int sx = mat.size() - 1;
        int sy = mat[0].size() - 1;
        while (true)
        {
            ret.push_back(mat[x][y]);
            if (x == sx && y == sy)
            {
                break;
            }
            if (dx < 0 && x == 0)
            {
                if (y == sy)
                {
                    x += 1;
                }
                else
                {
                    y += 1;
                }
                dx *= -1;
                dy *= -1;
                continue;
            }
            if (dy < 0 && y == 0)
            {
                if (x == sx)
                {
                    y += 1;
                }
                else
                {
                    x += 1;
                }
                dx *= -1;
                dy *= -1;
                continue;
            }
            if (dx > 0 && x == sx)
            {
                y += 1;
                dx *= -1;
                dy *= -1;
                continue;
            }
            if (dy > 0 && y == sy)
            {
                x += 1;
                dx *= -1;
                dy *= -1;
                continue;
            }
            x += dx;
            y += dy;
        }
        return ret;
    }
    // 对角线遍历
    vector<int> findDiagonalOrder1(const vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        // 对角线总条数
        int size = m + n - 1;
        vector<int> ret;
        for (int i = 0; i < size; ++i)
        {
            if (i & 1)
            { // 基数
                // 确定初始值
                int x = i < n ? 0 : i - n + 1;
                int y = i < n ? i : n - 1;
                // 遍历斜线
                while (x < m && y >= 0)
                {
                    ret.push_back(mat[x][y]);
                    ++x;
                    --y;
                }
            }
            else
            { // 偶数
                // 确定初始值
                int x = i < m ? i : m - 1;
                int y = i < m ? 0 : i - m + 1;
                // 遍历斜线
                while (x >= 0 && y < n)
                {
                    ret.push_back(mat[x][y]);
                    --x;
                    ++y;
                }
            }
        }
        return ret;
    }
};

void print(const vector<int> &ret)
{
    cout << "[";
    for (int x : ret)
    {
        cout << x << ",";
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    DiagonalTraverse cls;
    // [1,2,3,4]
    print(cls.findDiagonalOrder1(vector<vector<int>>{{1, 2}, {3, 4}}));
    // [1,2,4,7,5,3,6,8,9]
    print(cls.findDiagonalOrder1(vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}));

    print(cls.findDiagonalOrder1(vector<vector<int>>{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}));
    return 0;
}
