#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Trie {
public:
    Trie() = default;
    ~Trie() {
        Clear();
    }
public:
    void Clear() {
        for (auto& it : Children) {
            if (it.second) {
                it.second->Clear();
                delete it.second;
                it.second = nullptr;
            }
        }
    }
    void Insert(string& word) {
        Trie* node = this;
        for (char c : word) {
            Trie* n = node->Children[c];
            if (!n) {
                n = new Trie();
                node->Children[c] = n;
            }
            node = n;
        }
        node->IsEnd = true;
    }
    Trie* Find(char c){
        if(Children.empty())
            return nullptr;
        auto it = Children.find(c);
        if(it == Children.end())
            return nullptr;
        return it->second;
    }
    void Delete(string& word){
        del(word, 0);
    }
    bool End(){
        return IsEnd;
    }
    void NotEnd(){
        IsEnd = false;
    }
private:
    void del(string& word, int i){
        if(i >= word.size())
            return;
        auto it = Children.find(word[i]);
        if(it == Children.end())
            return;
        if(!it->second)
            return;
        it->second->del(word, i+1);
        if(it->second->Children.empty()){
            delete it->second;
            Children.erase(word[i]);
        }
    }
private:
    unordered_map<char, Trie*> Children;
    bool IsEnd{};
};

// 212. 单词搜索 II
class WordSearch2
{
    /* 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
    */
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ret.clear();
        mLen = 0;
        int col = board.size();
        int row = board[0].size();
        used.resize(col, vector<bool>(row, false));
        //先构建字典树
        Trie dic;
        for(auto& str: words){
            dic.Insert(str);
        }
        //在字典树中匹配
        for(int i = 0; i< col; ++i){
            for(int j = 0; j < row;++j){
                auto* n = dic.Find(board[i][j]);
                if(!n)
                    continue;
                search(board, n, i, j, "");
                while(mLen < ret.size()){   //删除不需要再匹配的单词 提高效率
                    dic.Delete(ret[mLen]);
                    ++mLen;
                }
            }
        }
        return ret;
    }
private:
    void search(vector<vector<char>>& board, Trie* node, int i, int j, string dp){
        dp.push_back(board[i][j]);
        used[i][j] = true;
        if(node->End()){
            ret.push_back(dp);
            node->NotEnd(); //标记该节点已经使用过了
        }
        if(i > 0 && used[i-1][j] == false){
            auto n = node->Find(board[i-1][j]);
            if(n)
                search(board, n, i-1, j, dp);
        }
        if(i + 1 < board.size() && used[i+1][j] == false){
            auto n = node->Find(board[i+1][j]);
            if(n)
                search(board, n, i+1, j, dp);
        }
        if(j > 0 && used[i][j-1] == false){
            auto n = node->Find(board[i][j - 1]);
            if(n)
                search(board, n, i, j-1, dp);
        }
        if(j+1 < board[0].size() && used[i][j+1] == false){  
            auto n = node->Find(board[i][j+1]);
            if(n)
                search(board, n, i, j+1, dp);
        }
        used[i][j] = false;
    }
private:
    vector<string> ret;
    int mLen{};
    vector<vector<bool>> used;
};

int main(int argc, char const *argv[])
{
    WordSearch2 cls;
    auto ret2 = cls.findWords(vector<vector<char>>{
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'}
    }, vector<string>{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});
    cout << "[";
    for(auto &it : ret2){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;

    auto ret = cls.findWords(vector<vector<char>>{
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    }, vector<string>{"oath","pea","eat","rain"});
    cout << "[";
    for(auto &it : ret){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;

    auto ret1 = cls.findWords(vector<vector<char>>{
        {'a','b'},
        {'c','d'}
    }, vector<string>{"abcd"});
    cout << "[";
    for(auto &it : ret1){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;

    return 0;
}
