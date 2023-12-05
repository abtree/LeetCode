#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct Trie{
    bool isEnd{false};
    vector<Trie*> children = vector<Trie*>(26, nullptr);
};

class ConcatenatedWords{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> words) {
        vector<string> ans;
        //先按长度排序 保证处理较长字符串时 比他短的字符串都处理过了
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
        for(auto& word : words){
            if(word.size() == 0){
                continue;
            }
            //判断字符串是否是连接词
            vector<bool> visited(word.size(), false);
            if(dfs(word, 0, visited)){
                //如果是连接词 加入答案
                ans.push_back(word);
            }else{
                //如果不是 加入字典树
                insert(word);
            }
        }
        return ans;
    }
private:
    bool dfs(const string& word, int start, vector<bool>& visited){
        if(word.size() == start){
            //已经遍历完整word了
            return true;
        }
        if(visited[start] == true){
            //从这里开始已经检测过了 所以不需要再检测了
            return false;
        }
        visited[start] = true;
        Trie* node = &trie;
        for(int i = start;i<word.size();++i){
            char ch = word[i];
            int index = ch -'a';
            node = node->children[index];
            if(node == nullptr){
                return false;
            }
            if(node->isEnd){
                //从这里分词试试
                if(dfs(word, i+1, visited)){
                    return true;
                }
            }
        }
        return false;
    } 
    void insert(string& word){
        Trie* node = &trie;
        for(int i =0;i<word.size();++i){
            char ch = word[i];
            int index = ch - 'a';
            if(node->children[index] == nullptr){
                node->children[index] = new Trie{};
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
private:
    Trie trie;
};

string print(vector<string> data){
    string str = "[";
    for (auto& s : data){
        str += s + ",";
    }
    str.pop_back();
    str += "]";
    return str;
}

class ConcatenatedWords1{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> words) {
        for(auto& word : words){
            dic.insert(word);
        }
        vector<string> ret;
        for(auto &word : words){
            if(check(word)){
                ret.push_back(word);
            }
        }
        return ret;
    }
private:
    bool check(string& word){
        int size = word.size();
        vector<int> dp(size+1, -1);
        dp[0] = 0;
        for(int i =0;i<size;++i){
            if(dp[i] < 0){
                continue;
            }
            for(int j =i+1;j<=size;++j){
                if(dic.count(word.substr(i, j-i)) > 0){
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            if(dp[size] > 1){
                return true;
            }
        }
        return false;
    }
private:
    unordered_set<string> dic;
};

int main(){
    ConcatenatedWords1 cls;
    cout << print(cls.findAllConcatenatedWordsInADict(vector<string>{"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"})).c_str() << " -> [catsdogcats,dogcatsdog,ratcatdogcat]" << endl;
    ConcatenatedWords1 cls1;
    cout << print(cls1.findAllConcatenatedWordsInADict(vector<string>{"cat","dog","catdog"})).c_str() << " -> [catdog]" << endl;
    return 0;
}
