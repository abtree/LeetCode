#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        data.clear();
    }

    void addNum(int val) {
        auto it = lower_bound(data.begin(), data.end(), val);
        if (*it == val)
            return; //去重
        data.insert(it, val);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        if (data.empty())
            return ret;
        int size = data.size();
        int b = 0;
        for (int i = 1; i < size;++i) {
            if (data[i] != data[i - 1] + 1) {
                ret.push_back(vector<int>{data[b], data[i - 1]});
                b = i;
            }
        }
        ret.push_back(vector<int>{data[b], data.back()});
        return ret;
    }
private:
    deque<int> data;    //有序数组
};

class SummaryRanges1 {
public:
    /** Initialize your data structure here. */
    SummaryRanges1() {
        ret.clear();
    }

    void addNum(int val) {
        for (int i = 0; i < ret.size();++i) {
            if (ret[i][1] < val - 1)
                continue;   //需要查找下一个区间
            if (ret[i][0] == val || ret[i][1] == val)
                return;
            if (ret[i][0] > val + 1) {
                ret.insert(ret.begin() + i, vector<int>{val, val});
                return;
            }
            if (ret[i][0] == val + 1) {
                ret[i][0] = val;
                return;
            }
            if (ret[i][1] == val - 1) {
                ret[i][1] = val;
                if (i + 1 >= ret.size())
                    return;
                if (ret[i + 1][0] == val + 1) {
                    //合并区间
                    ret[i][1] = ret[i + 1][1];
                    ret.erase(ret.begin() + i + 1);
                }
                return;
            }
            return;
        }
        //遍历完整个区间集都没找到合适的位置就插在最后
        ret.push_back(vector<int>{val, val});
    }

    vector<vector<int>> getIntervals() {
        return ret;
    }
private:
    vector<vector<int>> ret;
};

int main(int argc, char const* argv[]) {
    SummaryRanges1 cls;
    cls.addNum(1);
    auto& r1 = cls.getIntervals();
    cout << "[";
    for (auto& v : r1) {
        cout << "[";
        cout << v[0] << "," << v[1];
        cout << "],";
    }
    cout << "]" << endl;
    cls.addNum(3);
    auto& r2 = cls.getIntervals();
    cout << "[";
    for (auto& v : r2) {
        cout << "[";
        cout << v[0] << "," << v[1];
        cout << "],";
    }
    cout << "]" << endl;
    cls.addNum(7);
    auto& r3 = cls.getIntervals();
    cout << "[";
    for (auto& v : r3) {
        cout << "[";
        cout << v[0] << "," << v[1];
        cout << "],";
    }
    cout << "]" << endl;
    cls.addNum(2);
    auto& r4 = cls.getIntervals();
    cout << "[";
    for (auto& v : r4) {
        cout << "[";
        cout << v[0] << "," << v[1];
        cout << "],";
    }
    cout << "]" << endl;
    cls.addNum(6);
    auto& r5 = cls.getIntervals();
    cout << "[";
    for (auto& v : r5) {
        cout << "[";
        cout << v[0] << "," << v[1];
        cout << "],";
    }
    cout << "]" << endl;
    return 0;
}
