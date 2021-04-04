#pragma once

//57. 插入区间
class InsertInterval {
    /*
    给出一个无重叠的 ，按照区间起始端点排序的区间列表。
    在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

    示例 1：
    输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
    输出：[[1,5],[6,9]]

    示例 2：
    输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    输出：[[1,2],[3,10],[12,16]]
    解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
    */
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        if (intervals.empty()) {
            ret.push_back(newInterval);
            return ret;
        }

        for (auto it = intervals.begin(); it != intervals.end(); ++it) {
            if ((*it)[1] < newInterval[0]) {
                ret.push_back((*it));
                continue;   //还没到需要插入的位置
            }
            if ((*it)[0] > newInterval[1]) {
                //插入该位置 并且没有交集
                ret.push_back(newInterval);
                ret.insert(ret.end(), it, intervals.end());
                return ret;
            }

            //插入该位置 并且有交集
            if ((*it)[0] > newInterval[0])
                (*it)[0] = newInterval[0];
            if ((*it)[1] < newInterval[1])
                (*it)[1] = newInterval[1];
            ret.push_back((*it));
            ++it;
            while (it != intervals.end()) {
                auto itr = ret.rbegin();
                if ((*it)[0] > (*itr)[1]) {
                    //之后就没有交集了
                    ret.insert(ret.end(), it, intervals.end());
                    return ret;
                }
                //还有交集 接着处理
                if ((*itr)[0] > (*it)[0])
                    (*itr)[0] = (*it)[0];
                if ((*itr)[1] < (*it)[1])
                    (*itr)[1] = (*it)[1];
                ++it;
            }
            return ret;
        }
        ret.push_back(newInterval); //插在最后
        return ret;
    }
public:
    static void Test() {
        InsertInterval cls;
        vector<vector<int>> v1{
            {1,3},
            {6,9}
        };
        auto ret1 = cls.insert(v1, vector<int>{2, 5});
        cout << "[" << endl;
        for (auto& it : ret1) {
            cout << "[" << it[0] << "," << it[1] << "]" << endl;
        }
        cout << "]" << endl;

        vector<vector<int>> v2{
            {1,2},
            {3,5},
            {6,7},
            {8,10},
            {12,16}
        };
        auto ret2 = cls.insert(v2, vector<int>{4, 8});
        cout << "[" << endl;
        for (auto& it : ret2) {
            cout << "[" << it[0] << "," << it[1] << "]" << endl;
        }
        cout << "]" << endl;
    }
};