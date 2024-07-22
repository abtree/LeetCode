#include <iostream>
#include <vector>
using namespace std;

class ReshapeTheMatrix
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> mat, int r, int c)
    {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c)
        {
            return mat;
        }
        vector<vector<int>> ret = vector<vector<int>>(r, vector<int>(c, 0));
        int i = 0, j = 0;
        for (auto x : mat)
        {
            for (auto y : x)
            {
                ret[i][j] = y;
                ++j;
                if (j >= c)
                {
                    ++i;
                    j = 0;
                }
            }
        }
        return ret;
    }
};

void print(vector<vector<int>> &mat)
{
    cout << "[";
    for (auto x : mat)
    {
        cout << "[";
        for (auto y : x)
        {
            cout << y << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    ReshapeTheMatrix cls;
    auto ret = cls.matrixReshape(vector<vector<int>>{{1, 2}, {3, 4}}, 1, 4);
    print(ret);
    auto ret1 = cls.matrixReshape(vector<vector<int>>{{1, 2}, {3, 4}}, 2, 4);
    print(ret1);
    return 0;
}
