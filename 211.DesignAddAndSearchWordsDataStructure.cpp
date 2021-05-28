#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() = default;

    ~WordDictionary() {
        Clear();
    }

    void Clear() {
        for (auto& info : Children) {
            if (info.second) {
                info.second->Clear();
                delete info.second;
                info.second = nullptr;
            }
        }
    }

    void addWord(string word) {
        WordDictionary* node = this;
        for (char c : word) {
            auto* n = node->Children[c];
            if (!n) {
                n = new WordDictionary();
                node->Children[c] = n;
            }
            node = n;
        }
        node->IsEnd = true;
    }

    bool search(string word) {
        WordDictionary* node = this;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == '.') {
                return node->searchDot(word, i + 1);
            }
            else {
                auto it = node->Children.find(word[i]);
                if (it == node->Children.end())
                    return false;
                node = it->second;
                if (!node)
                    return false;
            }
        }
        return node->IsEnd;
    }
private:
    bool searchDot(string& word, int pos) {
        for (auto& it : Children) {
            WordDictionary* node = it.second;
            if (!node)
                continue;
            bool end = true;
            for (int i = pos; i < word.size(); ++i) {
                if (word[i] == '.') {
                    if (node->searchDot(word, i + 1))
                        return true;
                    end = false;
                    break;
                }
                else {
                    auto it = node->Children.find(word[i]);
                    if (it == node->Children.end()) {
                        end = false;
                        break;
                    }
                    node = it->second;
                    if (!node) {
                        end = false;
                        break;
                    }
                }
            }
            if (end && node->IsEnd)
                return true;
        }
        return false;
    }
private:
    unordered_map<char, WordDictionary*> Children;
    bool IsEnd{};
};

int main(int argc, char const* argv[])
{
    WordDictionary wd;
    wd.addWord("ran");
    wd.addWord("rune");
    wd.addWord("runner");
    wd.addWord("runs");
    wd.addWord("add");
    wd.addWord("adds");
    wd.addWord("adder");
    wd.addWord("addee");
    cout << boolalpha << wd.search("r.n") << " -> true" << endl;
    cout << boolalpha << wd.search("ru.n.e") << " -> false" << endl;
    cout << boolalpha << wd.search("add") << " -> true" << endl;
    cout << boolalpha << wd.search("add.") << " -> true" << endl;
    cout << boolalpha << wd.search("adde.") << " -> true" << endl;
    cout << boolalpha << wd.search(".an.") << " -> false" << endl;
    cout << boolalpha << wd.search("...s") << " -> true" << endl;
    cout << boolalpha << wd.search("....e.") << " -> true" << endl;
    cout << boolalpha << wd.search(".......") << " -> false" << endl;
    cout << boolalpha << wd.search("..n.r") << " -> false" << endl;
    return 0;
}