#include <iostream>
#include <unordered_map>
#include <set>
#include <map>
#include <list>
using namespace std;

struct Node{
    int cnt{};  //使用频率
    int time{}; //最后使用时间
    int key{};
    int value{};

    Node(int c, int t, int k, int v):cnt(c),time(t),key(k),value(v){}

    // 需要定义小于操作 才能进行排序操作
    bool operator<(const Node& rhs) const{
        return cnt == rhs.cnt? time < rhs.time : cnt < rhs.cnt;
    }
};

class LFUCache
{
private:
    int mCap{};
    int mTime{};
    unordered_map<int, Node> mTable;
    set<Node> mTree;
public:
    LFUCache(int capacity) {
        mCap = capacity;
        mTime = 0;
        mTable.clear();
        mTree.clear();
    }
    
    int get(int key) {
        if(mCap < 1){
            return -1;
        }
        auto it = mTable.find(key);
        if(it == mTable.end()){
            return -1;
        }
        Node cache = it->second;
        mTree.erase(cache);
        cache.cnt++;
        cache.time=++mTime;
        mTree.insert(cache);
        it->second = cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if(mCap < 1)
            return;
        auto it = mTable.find(key);
        if(it == mTable.end()){
            if(mTable.size() == mCap){
                mTable.erase(mTree.begin()->key);
                mTree.erase(mTree.begin());
            }
            Node cache(1,++mTime,key, value);
            mTable.insert({key, cache});
            mTree.insert(cache);
        }else{
            Node cache = it->second;
            mTree.erase(cache);
            cache.cnt+=1;
            cache.time=++mTime;
            cache.value = value;
            mTree.insert(cache);
            it->second = cache;
        }
    }
};

int main(int argc, char const *argv[])
{
    LFUCache cls(2);
    cls.put(1,1);
    cls.put(2,2);
    cout << cls.get(1) << " -> 1" << endl;
    cls.put(3,3);
    cout << cls.get(2) << " -> -1" << endl;
    cout << cls.get(3) << " -> 3" << endl;
    cls.put(4,4);
    cout << cls.get(1) << " -> -1" << endl;
    cout << cls.get(3) << " -> 3" << endl;
    cout << cls.get(4) << " -> 4" << endl;
    return 0;
}
