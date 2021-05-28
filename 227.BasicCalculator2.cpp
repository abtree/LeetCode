#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <numeric>

using namespace std;

// 227. 基本计算器 II
class BasicCalculator2 {
    /*  给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。整数除法仅保留整数部分。
    */
public:
    int calculate(string s) {
        int n = s.size();
        vector<int> nums;
        int sign=1;
        char op = ' ';
        for(int i = 0; i< n ;++i){
            if(s[i] == ' ')
                continue;
            if(s[i] == '+')
                continue;
            if(s[i] == '-'){
                sign = -sign;
                continue;
            }
            if(s[i] == '*' || s[i] == '/'){
                op = s[i];
                continue;
            }
            int par = 0;
            while(i<n && isdigit(s[i])){
                par = par * 10 + (s[i] - '0');
                ++i;
            }
            par *= sign;    //确定符号
            sign = 1;
            if(op != ' '){
                if(op == '*'){
                    nums.back() *= par;
                }else{
                    nums.back() /= par;
                }
                op = ' ';
            }else{
                nums.push_back(par);
            }
            --i;
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

int main(int argc, char const *argv[])
{
    BasicCalculator2 cls;
    cout << cls.calculate("1-2*-1")<<" -> 3" << endl;
    cout << cls.calculate("3+2*2")<<" -> 7" << endl;
    cout << cls.calculate("3/2") << " -> 1"<<endl;
    cout << cls.calculate("3+5/ 2 ") << " -> 5"<<endl;
    return 0;
}
