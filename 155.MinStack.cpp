#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        data.push(val);
        if (minStack.empty() || val < minStack.top()) {
            minStack.push(val);
        }
        else {
            minStack.push(minStack.top());
        }
    }

    void pop() {
        data.pop();
        minStack.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minStack.top();
    }
private:
    stack<int> data;    //栈数据
    stack<int> minStack;    //辅助栈
};

int main(int argc, char const* argv[])
{
    MinStack cls;
    cls.push(-2);
    cls.push(0);
    cls.push(-3);
    cout << cls.getMin() << endl;
    cls.pop();
    cout << cls.top() << endl;
    cout << cls.getMin() << endl;
    return 0;
}
