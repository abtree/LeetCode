#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//90. 子集 II
class Subsets2 {
    /*
    给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
    解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

    示例 1：
    输入：nums = [1,2,2]
    输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

    示例 2：
    输入：nums = [0]
    输出：[[],[0]]
    */
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.emplace_back(vector<int>{});
        sort(nums.begin(), nums.end());
        vector<int> cur;
        subsetCycle(ret, nums, cur, 0);
        return ret;
    }
private:
    void subsetCycle(vector<vector<int>>& ret, vector<int>& nums, vector<int>& cur, int pos) {
        for (int i = pos;i < nums.size();++i) {
            cur.push_back(nums[i]);
            ret.push_back(cur);
            subsetCycle(ret, nums, cur, i + 1);
            cur.pop_back();
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++i;
        }
    }
};

int main(int argc, char const* argv[])
{
    Subsets2 cls;
    auto& ret = cls.subsetsWithDup(vector<int>{1, 2, 2});
    cout << "[";
    for (auto& it : ret) {
        cout << "[";
        for (auto it1 : it) {
            cout << it1 << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    auto& ret1 = cls.subsetsWithDup(vector<int>{0});
    cout << "[";
    for (auto& it : ret1) {
        cout << "[";
        for (auto it1 : it) {
            cout << it1 << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
    return 0;
}
