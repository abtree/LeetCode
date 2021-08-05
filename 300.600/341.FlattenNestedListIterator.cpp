#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return List.empty();
    }
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        return Value;
    }
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const {
        return List;
    }
public:
    int Value{};
    vector<NestedInteger> List;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        vals.clear();
        dfs(nestedList);
        cur = vals.begin();
    }

    int next() {
        int ret = *cur;
        ++cur;
        return ret;
    }

    bool hasNext() {
        return cur != vals.end();
    }
private:
    void dfs(const vector<NestedInteger>& nestedList) {
        for (auto& it : nestedList) {
            if (it.isInteger()) {
                vals.push_back(it.getInteger());
            }
            else {
                dfs(it.getList());
            }
        }
    }
private:
    vector<int> vals;   //将原列表 直接 转成没有嵌套的列表
    vector<int>::iterator cur;
};

class NestedIterator1 {
public:
    NestedIterator1(vector<NestedInteger>& nestedList) {
        stk.emplace(nestedList.begin(), nestedList.end());
    }

    int next() {
        return stk.top().first++->getInteger();
    }

    bool hasNext() {
        while (!stk.empty()) {
            auto& p = stk.top();
            if (p.first == p.second) {
                stk.pop();
                continue;
            }
            if (p.first->isInteger()) {
                return true;
            }
            auto& n = p.first++->getList();
            stk.emplace(n.begin(), n.end());
        }
        return false;
    }
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk; //存储每一层的当前位置和结束位置
};

int main(int argc, char const* argv[]) {
    vector<NestedInteger> vec(3);
    vec[0].List.resize(2);
    vec[0].List[0].Value = 1;
    vec[0].List[1].Value = 1;
    vec[1].Value = 2;
    vec[2].List.resize(2);
    vec[2].List[0].Value = 1;
    vec[2].List[1].Value = 1;
    NestedIterator1 iter(vec);
    cout << "[";
    while (iter.hasNext()) {
        cout << iter.next() << ",";
    }
    cout << "]" << endl;

    vector<NestedInteger> vec1(2);
    vec1[0].Value = 1;
    vec1[1].List.resize(2);
    vec1[1].List[0].Value = 4;
    vec1[1].List[1].List.resize(1);
    vec1[1].List[1].List[0].Value = 6;
    NestedIterator1 iter1(vec1);
    cout << "[";
    while (iter1.hasNext()) {
        cout << iter1.next() << ",";
    }
    cout << "]" << endl;

    return 0;
}
