#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(nullptr));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        data.insert(val);
        return data.count(val) == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = data.find(val);
        if(it == data.end())
            return false;
        data.erase(it);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int pos = rand()%data.size();
        auto it = data.begin();
        advance(it, pos);
        return *it;
    }
private:
    unordered_multiset<int> data;
};

class RandomizedCollection1 {
public:
    /** Initialize your data structure here. */
    RandomizedCollection1() {
        srand(time(nullptr));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(size < max){
            data[size] = val;
            kvs[val].insert(size);
        }else{
            data.push_back(val);
            kvs[val].insert(max);
            ++max;
        }
        ++size;
        return kvs[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = kvs.find(val);
        if(it == kvs.end())
            return false;
        if(it->second.empty()){
            kvs.erase(it);
            return false;
        }
        auto pos = *it->second.begin();
        //交换data的数据
        swap(pos);
        if(it->second.empty())
            kvs.erase(it);
        --size;
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int pos = rand()%size;
        return data[pos];
    }
private:
    void swap(int pos){
        int end = size-1;
        if(pos == end || data[pos] == data[end]){
            kvs[data[pos]].erase(end);
            return;
        }
        kvs[data[pos]].erase(pos);
        data[pos] = data[end];
        kvs[data[end]].erase(end);
        kvs[data[end]].insert(pos);
    }
private:
    unordered_map<int, unordered_set<int>> kvs;
    vector<int> data;
    int max{};
    int size{};
};

int main(int argc, char const *argv[]){
    RandomizedCollection1 cls;
    cout << boolalpha << cls.insert(1) << " -> true" << endl;
    cout << boolalpha << cls.insert(1) << " -> false" << endl;
    cout << boolalpha << cls.insert(2) << " -> true" << endl;
    cout << boolalpha << cls.insert(1) << " -> false" << endl;
    cout << boolalpha << cls.insert(2) << " -> false" << endl;
    cout << boolalpha << cls.insert(2) << " -> false" << endl;
    cout << boolalpha << cls.remove(1) << " -> true" << endl;
    cout << boolalpha << cls.remove(2) << " -> true" << endl;
    cout << boolalpha << cls.remove(2) << " -> true" << endl;
    cout << boolalpha << cls.remove(2) << " -> true" << endl;
    cout << cls.getRandom() << endl;
    cout << cls.getRandom() << endl;
    return 0;
}
