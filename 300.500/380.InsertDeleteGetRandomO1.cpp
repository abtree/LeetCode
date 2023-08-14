#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdlib.h>
#include <time.h>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(data.find(val) != data.end())
            return false;
        data.insert(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = data.find(val);
        if(it == data.end())
            return false;
        data.erase(it);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int pos = rand()%data.size();
        auto it = data.begin();
        advance(it, pos);
        return *it;
    }
private:
    unordered_set<int> data;
};

int main(int argc, char const *argv[]){
    RandomizedSet cls;
    cout << boolalpha << cls.insert(1) << " -> true" << endl;
    cout << boolalpha << cls.remove(2) << " -> false" << endl;
    cout << boolalpha << cls.insert(2) << " -> true" << endl;
    cout << cls.getRandom() << endl;
    cout << boolalpha << cls.remove(1) << " -> true" << endl;
    cout << boolalpha << cls.insert(2) << " -> false" << endl;
    cout << cls.getRandom() << endl;
    return 0;
}
