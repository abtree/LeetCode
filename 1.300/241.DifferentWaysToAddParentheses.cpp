#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

//241. 为运算表达式设计优先级
class DifferentWaysToAddParentheses {
    /* 给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。
    */
public:
    vector<int> diffWaysToCompute(string expression) {
        //分治法
        int n = expression.size();
        if(n <= 0)
            return vector<int>{};
        return substr(expression, 0, n);
    }
private:
    vector<int> substr(string& expression, int start, int end){
        vector<int> ret;
        for(int i = start; i< end; ++i){
            if(isdigit(expression[i]))
                continue;
            auto& a = substr(expression, start, i);
            auto& b = substr(expression, i+1, end);
            for(auto x : a){
                for(auto y : b){
                    if(expression[i] == '+'){
                        ret.push_back(x + y);
                    }else if(expression[i] == '-'){
                        ret.push_back(x - y);
                    }else{
                        ret.push_back(x * y);
                    }
                }
            }
        }
        if(!ret.empty())
            return ret;
        int num = 0;
        for(int i = start; i< end; ++i){
            num = num*10+(expression[i]-'0');
        }
        ret.push_back(num);
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    DifferentWaysToAddParentheses cls;
    auto ret = cls.diffWaysToCompute("2-1-1");
    cout << "[";
    for (auto i : ret){
        cout << i << ",";
    }
    cout << "]" << endl;

    auto ret2 = cls.diffWaysToCompute("2*3-4*5");
    cout << "[";
    for (auto i : ret2){
        cout << i << ",";
    }
    cout << "]" << endl;
    return 0;
}
