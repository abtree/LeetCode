#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// 301. 删除无效的括号
class RemoveInvalidParentheses {
    /* 给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。返回所有可能的结果。答案可以按 任意顺序 返回。
    */
public:
    vector<string> removeInvalidParentheses(string s) {
        //计算需要删除的左右括号数
        int rml = 0, rmr = 0;   //需要删除的左右括号数,这两个值都可能大于0,如: ")("
        for(char c: s){
            if(c == '('){
                ++rml;  //默认都标记为需要删除,遇到右括号时取消
            }else if(c == ')'){
                if(rml > 0){
                    --rml;  //还有左括号与他抵消
                }else{
                    ++rmr;  //需要删除该右括号
                }
            }
        }
        //回溯 尝试所有可能的结果
        ret.clear();
        dfs(s, "", 0, 0, 0, rml, rmr);
        vector<string> ans(ret.begin(), ret.end());
        return ans;
    }
private:
    void dfs(string& s, string dst, int pos, int left, int right, int rml, int rmr){
        while(pos < s.size()){
            if(s[pos] == '('){
                if(rml > 0){    //尝试删除这个左括号
                    dfs(s, dst, pos + 1, left, right, rml-1,rmr);
                }
                left++; //保留这个左括号
                dst.push_back(s[pos]);
            }else if(s[pos] == ')'){
                if(rmr>0){  //尝试删除这个右括号
                    dfs(s, dst, pos+1, left, right, rml, rmr-1);
                }
                if(right < left){
                    right++; //保留这个右括号
                    dst.push_back(s[pos]);
                }else{
                    return; //如果将这个右括号插入 括号是不匹配的
                }
            }else{
                dst.push_back(s[pos]);
            }
            ++pos;
        }
        if(rml == 0 && rmr==0){ //满足需求
            ret.insert(dst);
        }
    }
private:
    unordered_set<string> ret;
};

int main(int argc, char const *argv[]){
    RemoveInvalidParentheses cls;
    auto& ret = cls.removeInvalidParentheses("()())()");
    cout << "[";
    for(auto& str : ret){
        cout <<str.c_str()<<",";
    }
    cout << "]" << endl;

    auto& ret1 = cls.removeInvalidParentheses("(a)())()");
    cout << "[";
    for(auto& str : ret1){
        cout <<str.c_str()<<",";
    }
    cout << "]" << endl;

    auto& ret2 = cls.removeInvalidParentheses(")(");
    cout << "[";
    for(auto& str : ret2){
        cout <<str.c_str()<<",";
    }
    cout << "]" << endl;
    return 0;
}
