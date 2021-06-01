#include <iostream>
#include <stack>
using namespace std;

//232. 用栈实现队列
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        while (!empty())
            tmp.push(pop());
        stk.push(x);
        while (!tmp.empty()) {
            stk.push(tmp.top());
            tmp.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int i = stk.top();
        stk.pop();
        return i;
    }

    /** Get the front element. */
    int peek() {
        return stk.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
private:
    stack<int> stk;
};

int main(int argc, char const* argv[])
{
    MyQueue cls;
    cls.push(1);
    cls.push(2);
    cout << cls.peek() << " -> 1" << endl;
    cout << cls.pop() << " -> 1" << endl;
    cout << boolalpha << cls.empty() << " -> false" << endl;
    return 0;
}
