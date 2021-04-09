#include <iostream>
#include <vector>

using namespace std;

//118. 杨辉三角2
class PascalsTriangle2 {
    /*
    给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
    */
public:
    vector<int> getRow(int rowIndex) {
        //利用公式: c[0] = 1; c[i] = c[i-1]*(n-i+1)/i
        vector<int> ans(rowIndex + 1, 0);
        ans[0] = 1;
        for (int i = 1; i <= rowIndex;++i) {
            ans[i] = 1LL * ans[i - 1] * (rowIndex - i + 1) / i;
        }

        return ans;
    }
};

int main(int argc, char const* argv[])
{
    PascalsTriangle2 cls;
    auto& ret = cls.getRow(3);
    cout << "[";
    for (auto i : ret) {
        cout << i << ",";
    }
    cout << "]" << endl;
    return 0;
}
