#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 290. 单词规律
class WordPattern {
    /* 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律
    */
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, pair<int, int>> seen;
        unordered_set<string> repeated;
        int i = 0, j = 0;
        for (char c : pattern) {
            if (j >= s.size())
                return false;
            auto it = seen.find(c);
            if (it == seen.end()) {
                while (j < s.size()) {
                    if (s[j] == ' ')
                        break;
                    ++j;
                }
                string sbstr = s.substr(i, j - i);
                if (repeated.find(sbstr) != repeated.end())
                    return false;
                repeated.insert(sbstr);
                seen[c] = make_pair(i, j);
            }
            else {
                int k = it->second.first;
                while (j < s.size() && k < it->second.second) {
                    if (s[j] != s[k])
                        return false;
                    ++j;
                    ++k;
                }
                if (k < it->second.second)
                    return false;
            }
            i = j + 1;
            j = i;
        }
        return j == s.size() + 1;
    }
};

int main(int argc, char const* argv[]) {
    WordPattern cls;
    cout << boolalpha << cls.wordPattern("jquery", "jquery") << " -> false" << endl;
    cout << boolalpha << cls.wordPattern("aaa", "aa aa aa aa") << " -> false" << endl;
    cout << boolalpha << cls.wordPattern("abba", "dog cat cat dog") << " -> true" << endl;
    cout << boolalpha << cls.wordPattern("abba", "dog cat cat fish") << " -> false" << endl;
    cout << boolalpha << cls.wordPattern("aaaa", "dog cat cat dog") << " -> false" << endl;
    cout << boolalpha << cls.wordPattern("abba", "dog dog dog dog") << " -> false" << endl;

    return 0;
}
