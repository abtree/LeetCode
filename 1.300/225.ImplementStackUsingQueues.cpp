#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size;++i) {
            q.push(pop());
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = q.front();
        q.pop();
        return ret;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

int main(int argc, char const* argv[]) {
    MyStack cls;
    cls.push(1);
    cls.push(2);
    cout << cls.top() << " -> 2" << endl;
    cout << cls.pop() << " -> 2" << endl;
    cout << boolalpha << cls.empty() << " -> false" << endl;
    cout << cls.top() << " -> 1" << endl;
    return 0;
}
