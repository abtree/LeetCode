#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Trie {
public:
    Trie() = default;
    ~Trie() {
        Clear();
    }
    void Clear() {
        for (auto& it : Children) {
            if (it.second) {
                //it.second->Clear();
                delete it.second;
                it.second = nullptr;
            }
        }
    }
    void Insert(string& str, int pos) {
        Trie* node = this;
        for (char c : str) {
            Trie* n = getChild(node, c);
            if (!n) {
                n = new Trie();
                node->Children[c] = n;
            }
            node = n;
        }
        node->Pos = pos;
    }
    int Search(string& str, int start, int end) {
        Trie* node = this;
        while (end >= start) {
            node = getChild(node, str[end]);
            if (!node)
                return -1;
            --end;
        }
        return node->Pos;
    }
private:
    Trie* getChild(Trie* node, char c) {
        auto it = node->Children.find(c);
        if (it != node->Children.end())
            return it->second;
        return nullptr;
    }
private:
    unordered_map<char, Trie*> Children;
    int Pos{ -1 };
};

// 336. 回文对
class PalindromePairs {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie;
        for (int i = 0; i < words.size(); ++i) {
            trie.Insert(words[i], i);
        }
        vector<vector<int>> ret{};
        for (int i = 0; i < words.size(); ++i) {
            int size = words[i].size();
            for (int j = 0; j <= size; ++j) {
                //判断 j..size-1是不是回文串
                if (isPalindrome(words[i], j, size - 1)) {
                    int x = trie.Search(words[i], 0, j - 1);
                    if (x > -1 && x != i) {
                        ret.emplace_back(vector<int>{i, x});
                    }
                }
                //判断 0..j是不是回文串
                if (j && isPalindrome(words[i], 0, j - 1)) {
                    int x = trie.Search(words[i], j, size - 1);
                    if (x > -1 && x != i) {
                        ret.emplace_back(vector<int>{x, i});
                    }
                }
            }
        }
        return ret;
    }
private:
    bool isPalindrome(string& str, int start, int end) {
        while (start < end) {
            if (str[start] != str[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
};

int main(int argc, char const* argv[]) {
    PalindromePairs cls;

    auto& ret2 = cls.palindromePairs(vector<string>{"a", ""});
    cout << "[";
    for (auto& it : ret2) {
        cout << "[";
        cout << it[0] << "," << it[1];
        cout << "], ";
    }
    cout << "]" << endl;

    auto& ret = cls.palindromePairs(vector<string>{"abcd", "dcba", "lls", "s", "sssll"});
    cout << "[";
    for (auto& it : ret) {
        cout << "[";
        cout << it[0] << "," << it[1];
        cout << "], ";
    }
    cout << "]" << endl;

    auto& ret1 = cls.palindromePairs(vector<string>{"bat", "tab", "cat"});
    cout << "[";
    for (auto& it : ret1) {
        cout << "[";
        cout << it[0] << "," << it[1];
        cout << "], ";
    }
    cout << "]" << endl;

    return 0;
}
