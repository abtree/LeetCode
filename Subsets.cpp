#include <iostream>
#include <vector>

using namespace std;

//78. 子集
class Subsets {
    /*
    给你一个整数数组 nums ，返回该数组所有可能的子集（幂集）。解集不能包含重复的子集。

    示例 1：
    输入：nums = [1,2,3]
    输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

    示例 2：
    输入：nums = [0]
    输出：[[],[0]]
    */
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rets;
        rets.push_back(vector<int>{});
        vector<int> ret;
        int size = nums.size();
        comb(rets, ret, nums, 0, size);
        return rets;
    }
private:
    void comb(vector<vector<int>>& rets, vector<int>& ret, vector<int>& nums, int p, int size) {
        for (int i = p; i < size;++i) {
            ret.push_back(nums[i]);
            rets.push_back(ret);
            if (i + 1 < size) {
                comb(rets, ret, nums, i + 1, size);
            }
            ret.pop_back();
        }
    }
};

int main() {
    Subsets cls;
    auto ret = cls.subsets(vector<int>{1, 2, 3});
    cout << "[";
    for (auto& it : ret) {
        cout << "[";
        for (int i : it) {
            cout << i << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;

    auto ret1 = cls.subsets(vector<int>{1});
    cout << "[";
    for (auto& it : ret1) {
        cout << "[";
        for (int i : it) {
            cout << i << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;
    return 0;
}