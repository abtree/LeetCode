#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//140. 单词拆分 II
class WordBreak2
{
    /*给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
    说明：分隔时可以重复使用字典中的单词。你可以假设字典中没有重复的单词。
    */
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dic.clear();
        ret.clear();
        minLen = INT_MAX;
        maxLen = 0;
        //生成单词表
        for (auto& str : wordDict) {
            if (str.size() > maxLen)
                maxLen = str.size();
            if (str.size() < minLen)
                minLen = str.size();
            dic.insert(str);
        }
        //构建结果
        vector<string> tmp;
        build(s, tmp, 0);
        return ret;
    }
private:
    void build(string& s, vector<string> tmp, int start) {
        int end = start + maxLen + 1;
        for (int i = start + minLen; i < end; ++i) {
            string cur = s.substr(start, i - start);
            if (dic.find(cur) != dic.end()) {
                tmp.push_back(cur);
                if (i >= s.size()) {
                    string str = "";
                    for (auto& s : tmp) {
                        str.append(s + " ");
                    }
                    str.pop_back();
                    ret.push_back(str);
                    tmp.pop_back();
                    break;
                }
                build(s, tmp, i);
                tmp.pop_back();
            }
        }
    }
private:
    unordered_set<string> dic;  //单词表
    int minLen{};   //单词最小长度
    int maxLen{};   //单词最大长度
    vector<string> ret{};   //结果
};

int main(int argc, char const* argv[])
{
    WordBreak2 cls;

    auto &ret4 = cls.wordBreak("ab", vector<string>{"a", "b"});
    cout << "[";
    for(auto &it : ret4){
        cout << it.c_str() << " , ";
    }
    cout << "]" << endl;

    auto &ret1 = cls.wordBreak("catsanddog", vector<string>{"cat", "cats", "and", "sand", "dog"});
    cout << "[";
    for(auto &it : ret1){
        cout << it.c_str() << " , ";
    }
    cout << "]" << endl;

    auto &ret2 = cls.wordBreak("pineapplepenapple", vector<string>{"apple", "pen", "applepen", "pine", "pineapple"});
    cout << "[";
    for(auto &it : ret2){
        cout << it.c_str() << " , ";
    }
    cout << "]" << endl;

    auto &ret3 = cls.wordBreak("catsandog", vector<string>{"cats", "dog", "sand", "and", "cat"});
    cout << "[";
    for(auto &it : ret3){
        cout << it.c_str() << " , ";
    }
    cout << "]" << endl;

    return 0;
}
