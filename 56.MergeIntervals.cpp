#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//56. 合并区间
class MergeIntervals {
    /*
    给出一个区间的集合，请合并所有重叠的区间。

    示例 1:
    输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
    输出: [[1,6],[8,10],[15,18]]
    解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

    示例 2:
    输入: intervals = [[1,4],[4,5]]
    输出: [[1,5]]
    解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
    */
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if (intervals.empty())
            return ret;
        //先排序
        sort(intervals.begin(), intervals.end());
        //在合并
        int size = intervals.size();
        ret.push_back(intervals[0]);
        for (int i = 1; i < size; ++i) {
            auto it = ret.rbegin();
            if ((*it)[1] >= intervals[i][0]) {
                if ((*it)[1] < intervals[i][1]) {
                    (*it)[1] = intervals[i][1];
                }
                if ((*it)[0] > intervals[i][0]) {
                    (*it)[0] = intervals[i][0];
                }
            }
            else {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[])
{
    MergeIntervals cls;
    vector<vector<int>> v1{
        {1,3},
        {2,6},
        {8,10},
        {15,18},
    };
    auto ret1 = cls.merge(v1);
    cout << "[" << endl;
    for (auto& it : ret1) {
        cout << "[" << it[0] << "," << it[1] << "]" << endl;
    }
    cout << "]" << endl;

    vector<vector<int>> v2{
        {1,4},
        {4,5}
    };
    auto ret2 = cls.merge(v2);
    cout << "[" << endl;
    for (auto& it : ret2) {
        cout << "[" << it[0] << "," << it[1] << "]" << endl;
    }
    cout << "]" << endl;

    vector<vector<int>> v3{
        {1,9},
        {2,5},
        {19,20},
        {10,11},
        {12,20},
        {0,3},
        {0,1},
        {0,2}
    };
    auto ret3 = cls.merge(v3);
    cout << "[" << endl;
    for (auto& it : ret3) {
        cout << "[" << it[0] << "," << it[1] << "]" << endl;
    }
    cout << "]" << endl;
    return 0;
}
