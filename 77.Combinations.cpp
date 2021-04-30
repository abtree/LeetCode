#include <iostream>
#include <vector>

using namespace std;

//77. 组合
class Combinations {
    /*
    给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

    示例:
    输入: n = 4, k = 2
    输出:
    [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
    ]
    */
public:
    vector<vector<int>> combine(int n, int k) {
        if (k > n)
            return vector<vector<int>>{};
        if (k == n) {
            vector<int> vec(k, 1);
            for (int i = 2; i <= k;++i) {
                vec[i - 1] = i;
            }
            return vector<vector<int>>{vec};
        }
        vector<vector<int>> rets;
        vector<int> ret;
        comb(rets, ret, 0, n + 1, k);
        return rets;
    }
private:
    //对k进行递归，每递归一层，k值减1
    void comb(vector<vector<int>>& rets, vector<int>& ret, int i, int n, int k) {
        for (int j = i + 1; j <= n - k;++j) {   //每一层能取的值
            ret.push_back(j);
            if (k == 1) //递归到最后一层了
                rets.push_back(ret);
            else
                comb(rets, ret, j, n, k - 1);
            ret.pop_back();
        }
    }
};

int main() {
    Combinations cls;
    auto ret = cls.combine(4, 2);
    cout << "[" << endl;
    for (auto& it : ret) {
        cout << "[";
        for (int i : it)
            cout << i << ",";
        cout << "]" << endl;
    }
    cout << "]" << endl << endl;
    return 0;
}