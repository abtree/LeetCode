#include <iostream>
#include <vector>
using namespace std;

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.

    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (hasStore)
            return store;
        store = Iterator::next();
        hasStore = true;
        return store;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (hasStore) {
            hasStore = false;
            return store;
        }
        return Iterator::next();
    }

    bool hasNext() const {
        if (hasStore)
            return true;
        return Iterator::hasNext();
    }
private:
    bool hasStore{};
    int store{};
};