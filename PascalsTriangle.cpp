#include <iostream>
#include <vector>

using namespace std;

//118. 杨辉三角
class PascalsTriangle {
    /*
    给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
    */
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows < 1)
            return ans;
        ans.push_back(std::move(vector<int>{1}));
        for (int i = 1; i < numRows;++i) {
            ans.push_back(vector<int>{});
            for (int j = 0;j <= i;++j) {
                int ret = 0;
                if (j > 0) {
                    ret += ans[i - 1][j - 1];
                }
                if (j < i) {
                    ret += ans[i - 1][j];
                }
                ans.back().push_back(ret);
            }
        }
        return ans;
    }
};

int main(int argc, char const* argv[])
{
    PascalsTriangle cls;
    auto& ret = cls.generate(5);
    cout << "[";
    for (auto& it : ret) {
        cout << "[";
        for (auto i : it) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
    return 0;
}
