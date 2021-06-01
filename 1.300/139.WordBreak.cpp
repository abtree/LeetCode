#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class WordBreak
{
public:
    class Node {    //字典树结构
    public:
        ~Node() {
            for (auto& it : next) {
                if (it.second) {
                    delete it.second;
                    it.second = nullptr;
                }
            }
        }
    public:
        unordered_map<char, Node*> next;    //字典树子项
    };
public:
    ~WordBreak() {
        clear();
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //先构建字典树
        clear();
        for (auto& it : wordDict) {
            Build(it);
        }
        //在动态规划
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size();++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && check(s, j, i)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
private:
    void clear() {
        for (auto& it : dic) {
            if (it.second) {
                delete it.second;
                it.second = nullptr;
            }
        }
        dic.clear();
    }
    void Build(string& s) { //构建字典树
        if (dic.find(s[0]) == dic.end()) {
            dic[s[0]] = new Node();
        }
        Node* cur = dic[s[0]];
        for (int i = 1;i < s.size();++i) {
            if (cur->next.find(s[i]) == cur->next.end()) {
                cur->next[s[i]] = new Node();
            }
            cur = cur->next[s[i]];
        }
        cur->next['_'] = nullptr;
    }
    bool check(string& s, int i, int j) { //查找字典树
        if (dic.find(s[i]) == dic.end())
            return false;
        Node* cur = dic[s[i]];
        ++i;
        while (i < j) {
            if (cur->next.find(s[i]) == cur->next.end())
                return false;
            cur = cur->next[s[i]];
            ++i;
        }
        if (cur->next.find('_') == cur->next.end())
            return false;
        return true;
    }
private:
    unordered_map<char, Node*> dic; //字典树
};

class WordBreak2
{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //不用字典树的剪枝查找法
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        int maxLen = 0; int minLen = INT_MAX;
        for (auto& str : wordDict) {
            if (str.size() > maxLen)
                maxLen = str.size();
            if (str.size() < minLen)
                minLen = str.size();
        }
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = minLen; i <= s.size(); ++i) {
            for (int j = max(0, i - maxLen); j < i; ++j) {
                if (dp[j] && dic.find(s.substr(j, i - j)) != dic.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main(int argc, char const* argv[])
{
    WordBreak2 cls;
    cout << boolalpha << cls.wordBreak("leetcode", vector<string>{"leet", "code"}) << " -> true" << endl;
    cout << boolalpha << cls.wordBreak("applepenapple", vector<string>{"apple", "pen"}) << " -> true" << endl;
    cout << boolalpha << cls.wordBreak("catsandog", vector<string>{"cats", "dog", "sand", "and", "cat"}) << " -> false" << endl;
    return 0;
}
