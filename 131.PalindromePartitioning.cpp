#include <iostream>
#include <string>
#include <vector>

using namespace std;

//131. 分割回文串
class PalindromePartitioning
{
    /*给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。回文串 是正着读和反着读都一样的字符串。
    */
public:
    vector<vector<string>> partition(string s) {
        //递归+回溯
        mRet.clear();
        vector<string> cur;
        part(s, 0, s.size(), cur);
        return mRet;
    }
private:
    void part(string& s, int i, int j, vector<string>& cur){
        if(i == j){
            mRet.emplace_back(cur.begin(), cur.end());
            return;
        }
        for(int p = i; p<j;++p){
            if(!isPalindrome(s, i, p))
                continue;
            cur.push_back(s.substr(i, p-i+1));
            part(s, p+1, j, cur);
            cur.pop_back();
        }
    }
    bool isPalindrome(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
private:
    vector<vector<string>> mRet;
};

int main(int argc, char const* argv[])
{
    PalindromePartitioning cls;

    auto& ret = cls.partition("aab");
    cout << "[";
    for(auto &it : ret){
        cout << "[";
        for(auto &i : it){
            cout << i.c_str() << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    auto& ret1 = cls.partition("a");
    cout << "[";
    for(auto &it : ret1){
        cout << "[";
        for(auto &i : it){
            cout << i.c_str() << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    auto& ret2 = cls.partition("efe");
    cout << "[";
    for(auto &it : ret2){
        cout << "[";
        for(auto &i : it){
            cout << i.c_str() << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    return 0;
}
