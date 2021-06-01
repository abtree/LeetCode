#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

//150. 逆波兰表达式求值
class EvaluateReversePolishNotation
{
    /*根据 逆波兰表示法，求表达式的值。有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
    说明：整数除法只保留整数部分。给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
    */
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto &it : tokens){
            if(it == "+"){
                int a = stk.top();
                stk.pop();
                a += stk.top();
                stk.pop();
                stk.push(a);
            }else if(it == "-"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b - a);
            }else if(it == "*"){
                int a = stk.top();
                stk.pop();
                a *= stk.top();
                stk.pop();
                stk.push(a);
            }else if(it == "/"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b / a);
            }else{
                stk.push(atoi(it.c_str()));
            }
        }
        return stk.top();
    }
};

int main(int argc, char const* argv[])
{
    EvaluateReversePolishNotation cls;

    cout << cls.evalRPN(vector<string>{
        "2","1","+","3","*"
    }) << " -> 9" << endl;
    cout << cls.evalRPN(vector<string>{
        "4","13","5","/","+"
    }) << " -> 6" << endl;
    cout << cls.evalRPN(vector<string>{
        "10","6","9","3","+","-11","*","/","*","17","+","5","+"
    }) << " -> 22" << endl;
    
    return 0;
}