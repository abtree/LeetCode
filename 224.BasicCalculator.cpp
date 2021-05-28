#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

// 224. 基本计算器
class BasicCalculator {
    /* 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
    */
public:
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int sign = 1;
        int ret = 0;
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                ++i;
            }
            else if (s[i] == '+') {
                //sign = ops.top();
                ++i;
            }
            else if (s[i] == '-') {
                sign = -sign; //-ops.top();
                ++i;
            }
            else if (s[i] == '(') {
                ops.push(sign);
                ++i;
            }
            else if (s[i] == ')') {
                ops.pop();
                sign = ops.top();
                ++i;
            }
            else {
                int num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                ret += sign * num;
                sign = ops.top();
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[])
{
    BasicCalculator cls;
    cout << cls.calculate("(7)-(0)+(4)") << " -> 11" << endl;
    cout << cls.calculate("1-(+1+1)") << " -> -1" << endl;
    cout << cls.calculate("1--1") << " -> 2" << endl;
    cout << cls.calculate("- (3 + (4 + 5))") << " -> -12" << endl;
    cout << cls.calculate("1") << " -> 1" << endl;
    cout << cls.calculate("48+ -48") << " -> 0" << endl;
    cout << cls.calculate("(1+(4+5+2)-3)+(6+8)") << " -> 23" << endl;
    cout << cls.calculate("1 + 1") << " -> 2" << endl;
    cout << cls.calculate("2-1 + 2") << " -> 3" << endl;
    return 0;
}