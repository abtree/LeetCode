#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = kv.find(key);
        if (it == kv.end())
            return -1;
        flags[key] = _id++;
        return it->second;
    }

    void put(int key, int value) {
        flags[key] = _id++;
        auto it = kv.find(key);
        if (it != kv.end()) {
            it->second = value;
        }
        else {
            kv[key] = value;
            if (kv.size() > cap) {
                drop();
            }
        }
    }
private:
    void drop() {
        int k = 0;
        int f = INT_MAX;
        for (auto& it : flags) {
            if (it.second < f) {
                k = it.first;
                f = it.second;
            }
        }
        flags.erase(k);
        kv.erase(k);
    }
private:
    int _id{};  //id值(有越界风险)
    unordered_map<int, int> flags;  //标记(标记key的先后顺序)
    unordered_map<int, int> kv; //key and value
    int cap{};  //容积
};

class LRUCache2 {
public:
    LRUCache2(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = kv.find(key);
        if (it == kv.end())
            return -1;
        keys.remove(key);
        keys.push_back(key);
        return it->second;
    }

    void put(int key, int value) {
        keys.remove(key);
        keys.push_back(key);
        auto it = kv.find(key);
        if (it != kv.end()) {
            it->second = value;
        }
        else {
            kv[key] = value;
            if (kv.size() > cap) {
                int d = keys.front();
                keys.pop_front();
                kv.erase(d);
            }
        }
    }
private:
    list<int> keys;  //标记(标记key的先后顺序) 这种做法性能更低 但是没有越界风险
    unordered_map<int, int> kv; //key and value
    int cap{};  //容积
};

int main(int argc, char const* argv[])
{
    LRUCache2 cls(2);
    cls.put(1, 1);
    cls.put(2, 2);
    cout << "1 = " << cls.get(1) << ";";
    cls.put(3, 3);
    cout << "2 = " << cls.get(2) << ";";
    cls.put(4, 4);
    cout << "1 = " << cls.get(1) << ";";
    cout << "3 = " << cls.get(3) << ";";
    cout << "4 = " << cls.get(4) << ";";
    cout << endl;
    return 0;
}