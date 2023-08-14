#include <iostream>
#include <string>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

class AllOne {
public:
    AllOne() {

    }
    
    void inc(string key) {
        if (nodes.count(key) > 0) {
            //已经存在的key
            auto cur = nodes[key];
            auto nxt = next(cur);
            if (nxt == lst.end() || nxt->second > cur->second + 1) {
                //需要添加新的节点
                unordered_set<string> s{ key };
                nodes[key] = lst.emplace(nxt, s, cur->second + 1);
            }
            else {
                //在老节点添加元素
                nxt->first.emplace(key);
                nodes[key] = nxt;
            }
            //删除原节点
            cur->first.erase(key);
            if (cur->first.empty()) {
                lst.erase(cur);
            }
        }
        else {
            if (lst.empty() || lst.begin()->second > 1) {
                unordered_set<string> s{ key };
                lst.emplace_front(s, 1);
            }
            else {
                lst.begin()->first.emplace(key);
            }
            nodes[key] = lst.begin();
        }
    }
    
    void dec(string key) {
        auto cur = nodes[key];
        if (cur->second == 1) {
            nodes.erase(key);
        }
        else {
            auto pre = prev(cur);
            if (cur == lst.begin() || pre->second < cur->second - 1) {
                unordered_set<string> s{ key };
                nodes[key] = lst.emplace(cur, s, cur->second - 1);
            }
            else {
                pre->first.emplace(key);
                nodes[key] = pre;
            }
        }
        cur->first.erase(key);
        if (cur->first.empty()) {
            lst.erase(cur);
        }
    }
    
    string getMaxKey() {
        return lst.empty() ? "" : *lst.rbegin()->first.begin();
    }
    
    string getMinKey() {
        return lst.empty() ? "" : *lst.begin()->first.begin();
    }
private:
    list<pair<unordered_set<string>, int>> lst;
    unordered_map<string, list<pair<unordered_set<string>, int>>::iterator> nodes;
};

class AllOne1 {
public:
    AllOne1() {

    }
    
    void inc(string key) {
        int cnt = nodes[key];
        nodes[key] = cnt+1;
        if (cnt > 0) {
            dp[cnt].erase(key);
            if (dp[cnt].empty()) {
                dp.erase(cnt);
            }
        }
        dp[cnt+1].emplace(key);
    }
    
    void dec(string key) {
        int cnt = nodes[key];
        if (cnt == 1) {
            nodes.erase(key);
        }
        else {
            nodes[key] = cnt - 1;
            dp[cnt - 1].emplace(key);
        }
        dp[cnt].erase(key);
        if (dp[cnt].empty()) {
            dp.erase(cnt);
        }
    }
    
    string getMaxKey() {
        return dp.empty() ? "" : *dp.rbegin()->second.begin();
    }
    
    string getMinKey() {
        return dp.empty() ? "" : *dp.begin()->second.begin();
    }
private:
    unordered_map<string, int> nodes;
    map<int, unordered_set<string>> dp;
};

int main(int argc, char const* argv[]) {
    AllOne1 cls;
    cls.inc("a");
    cls.inc("b");
    cls.inc("b");
    cls.inc("c");
    cls.inc("c");
    cls.inc("c");
    cls.dec("b");
    cls.dec("b");
    cout << "Min:" << cls.getMinKey().c_str() << endl;
    cls.dec("a");
    cout << "Max:" << cls.getMaxKey().c_str() << endl;
    cout << "Min:" << cls.getMinKey().c_str() << endl;
    // cls.inc("a");
    // cls.inc("b");
    // cls.inc("b");
    // cls.inc("b");
    // cls.inc("b");
    // cls.dec("b");
    // cls.dec("b");
    // cout << "Max:" << cls.getMaxKey().c_str() << endl;
    // cout << "Min:" << cls.getMinKey().c_str() << endl;
    // cls.inc("hello");
    // cls.inc("hello");
    // cout << "Max:" << cls.getMaxKey().c_str() << endl;
    // cout << "Min:" << cls.getMinKey().c_str() << endl;
    // cls.inc("leet");
    // cout << "Max:" << cls.getMaxKey().c_str() << endl;
    // cout << "Min:" << cls.getMinKey().c_str() << endl;
    return 0;
}
