#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 282. 给表达式添加运算符
class ExpressionAddOperators {
    /* 给定一个仅包含数字 0-9 的字符串和一个目标值，在数字之间添加 二元 运算符（不是一元）+、- 或 * ，返回所有能够得到目标值的表达式。
    */
public:
    vector<string> addOperators(string num, int target) {
        //暴力解法(将所有可能结果列出来，在逐个判断是否满足需求)
        if(num.size() == 1 || num[0] != '0'){
            long long tar = atoll(num.c_str());
            if(tar == target){
                return vector<string>{num};
            }
            long long t = target;
            if(t < 0){
                t = -t;
            }
            if(tar <= t)
                return vector<string>{};
        }
        vector<string> tmp = divided(num);
        vector<string> ret;
        for (auto& it : tmp) {
            if (calculate(it) == target) {
                ret.push_back(it);
            }
        }
        return ret;
    }
    vector<string> divided(string num) {
        vector<string> ret;
        int size = num.size();
        if(size <= 1 || num[0] != '0')
            ret.push_back(num);
        for (int i = 1;i < size;++i) {
            string ret1 = num.substr(0, i);
            if(ret1.size() > 1 && ret1[0] == '0')
                break;
            vector<string> ret2 = divided(num.substr(i));
            for (auto& it2 : ret2) {
                ret.push_back(ret1 + "+" + it2);
                ret.push_back(ret1 + "-" + it2);
                ret.push_back(ret1 + "*" + it2);
            }
        }
        return ret;
    }
    long long calculate(string& s) {  //计算表达式的值(227题)
        int n = s.size();
        vector<long long> nums;
        int sign = 1;
        char op = ' ';
        for (int i = 0; i < n;++i) {
            if (s[i] == ' ')
                continue;
            if (s[i] == '+')
                continue;
            if (s[i] == '-') {
                sign = -sign;
                continue;
            }
            if (s[i] == '*' || s[i] == '/') {
                op = s[i];
                continue;
            }
            long long par = 0;
            while (i < n && isdigit(s[i])) {
                par = par * 10 + (s[i] - '0');
                ++i;
            }
            par *= sign;    //确定符号
            sign = 1;
            if (op != ' ') {
                if (op == '*') {
                    nums.back() *= par;
                }
                else {
                    nums.back() /= par;
                }
                op = ' ';
            }
            else {
                nums.push_back(par);
            }
            --i;
        }
        long long ret = 0;
        for(auto i : nums){
            ret += i;
        }
        return ret;
    }
};

class ExpressionAddOperators1 
{
public:
    vector<string> addOperators(string num, int target) 
    {
        //深度优先遍历
        result.clear();
        num_after.clear();
        if (num.empty()) 
            return result;
        for (int i = 0; i < num.size(); ++i) 
            num_after.emplace_back(stoll(num.substr(i)));
        exp.resize(num.size() * 2);
        dfs(num, target, 0, 0, 0, 1);
        return result;
    }
private:
    string exp{};
    vector<string> result;
    vector<long long> num_after;
    
    int dfs(string& num, long long target, int exp_p, int pos, long long now, long long last) 
    {
        now = now * 10 + num[pos] - '0';
        exp[exp_p++] = num[pos];
        long long cur_val = now * last; //这里last有可能只表示正负号 
        if (pos == num.size() - 1) 
        {
            if (target == cur_val)
                result.emplace_back(exp.substr(0, exp_p));
            return 0;
        }
        exp[exp_p] = '*';   //当前位插入*
        dfs(num, target, exp_p + 1, pos + 1, 0, cur_val);   //因为乘法优先级高 所以这里需要先算乘法
        //如果剩余数字小于了目标值 中间添加什么符号 都不可能等于目标值(这里是为了减少判断)
        if (num_after[pos + 1] >= abs(target - cur_val)) {
            exp[exp_p] = '+';   //当前位插入+
            dfs(num, target - cur_val, exp_p + 1, pos + 1, 0, 1);
            exp[exp_p] = '-';   //当前位插入-(实际上将后面的数变成负数)
            dfs(num, target - cur_val, exp_p + 1, pos + 1, 0, -1); //传-1相当于将减法变成加负数,可以将减法与加法统一
        }
        //不插入符号 进入下一位(num为0时 不插入符号不满足要求 比如: 05)
        if (now)
            dfs(num, target, exp_p, pos + 1, now, last);
        return 0;
    }
};

int main(int argc, char const *argv[]){
    ExpressionAddOperators1 cls;
    auto &ret = cls.addOperators("123", 6);
    cout << "[";
    for(auto &it : ret){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;

    auto &ret1 = cls.addOperators("232", 8);
    cout << "[";
    for(auto &it : ret1){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;

    auto &ret3 = cls.addOperators("105", 5);
    cout << "[";
    for(auto &it : ret3){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;

    auto &ret4 = cls.addOperators("00", 0);
    cout << "[";
    for(auto &it : ret4){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;

    auto &ret5 = cls.addOperators("3456237490", 9191);
    cout << "[";
    for(auto &it : ret5){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;

    auto &ret6 = cls.addOperators("000", 0);
    cout << "[";
    for(auto &it : ret6){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;

    auto &ret7 = cls.addOperators("2147483647", 2147483647);
    cout << "[";
    for(auto &it : ret7){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;

    auto &ret8 = cls.addOperators("2147483648", -2147483648);
    cout << "[";
    for(auto &it : ret8){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;
    return 0;
}
