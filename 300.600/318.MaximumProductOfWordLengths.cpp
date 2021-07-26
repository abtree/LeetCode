#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// 318. 最大单词长度乘积
class MaximumProductOfWordLengths {
    /* 给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
    */
public:
    int maxProduct(vector<string>& words) {
        //暴力解法
        //预处理
        vector<int> tmp(words.size(), 0);
        int i = 0;
        for(auto& str:words){
            int power = 0;
            for(char c : str){
                power |= (1 << (c - 'a'));
            }
            tmp[i] = power;
            ++i;
        }
        //通过一一比对计算结果
        int n = words.size() - 1;
        int ret = 0;
        for(int i = 0; i< n; ++i){
            for(int j = i+1; j < words.size(); ++j){
                if((tmp[i] & tmp[j]) == 0){
                    ret = max(ret, int(words[i].size()*words[j].size()));
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[]){
    MaximumProductOfWordLengths cls;
    cout << cls.maxProduct(vector<string>{"abcw","baz","foo","bar","xtfn","abcdef"}) << " -> 16" << endl;
    cout << cls.maxProduct(vector<string>{"a","ab","abc","d","cd","bcd","abcd"}) << " -> 4" << endl;
    cout << cls.maxProduct(vector<string>{"a","aa","aaa","aaaa"}) << " -> 0" << endl;

    return 0;
}
