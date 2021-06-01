#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    ~Trie() {
        Clear();
    }

    void Clear() {
        for (auto& it : children) {
            if (it.second) {
                it.second->Clear();
                delete it.second;
                it.second = nullptr;
            }
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            Trie* n = node->children[c];
            if (!n) {
                n = new Trie();
                node->children[c] = n;
            }
            node = n;
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = getNode(word);
        return node && node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = getNode(prefix);
        return node != nullptr;
    }
private:
    Trie* getNode(string& str) {
        Trie* node = this;
        for (char c : str) {
            node = getChild(node, c);
            if (!node)
                return nullptr;
        }
        return node;
    }
    Trie* getChild(Trie* node, char c) {
        auto it = node->children.find(c);
        if (it == node->children.end())
            return nullptr;
        return it->second;
    }
private:
    unordered_map<char, Trie*> children;
    bool isEnd{};
};

int main(int argc, char const* argv[])
{
    Trie cls;
    cls.insert("apple");
    cout << boolalpha << cls.search("apple") << " -> true" << endl;
    cout << boolalpha << cls.search("app") << " -> false" << endl;
    cout << boolalpha << cls.startsWith("app") << " -> true" << endl;
    cls.insert("app");
    cout << boolalpha << cls.search("app") << " -> true" << endl;
    return 0;
}
