#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class KeyboardRow
{
public:
    vector<string> findWords(const vector<string> &words)
    {
        vector<string> ret;
        for (auto &word : words)
        {
            int size = word.size();
            if (size < 2)
            {
                ret.push_back(word);
                continue;
            }
            bool b = true;
            for (int i = 1; i < size; ++i)
            {
                if (group[tolower(word[i])] != group[tolower(word[i - 1])])
                {
                    b = false;
                    break;
                }
            }
            if (b)
            {
                ret.push_back(word);
            }
        }
        return ret;
    }
    vector<string> findWords1(const vector<string> &words)
    {
        vector<string> ret;
        for (auto &word : words)
        {
            int size = word.size();
            if (size < 2)
            {
                ret.push_back(word);
                continue;
            }
            char idx = rowIdx[tolower(word[0]) - 'a'];
            for (int i = 1; i < size; ++i)
            {
                if (rowIdx[tolower(word[i]) - 'a'] != idx)
                {
                    idx = '3';
                    break;
                }
            }
            if (idx < '3')
            {
                ret.push_back(word);
            }
        }
        return ret;
    }

private:
    unordered_map<char, int> group{
        {'q', 0},
        {'w', 0},
        {'e', 0},
        {'r', 0},
        {'t', 0},
        {'y', 0},
        {'u', 0},
        {'i', 0},
        {'o', 0},
        {'p', 0},
        {'a', 1},
        {'s', 1},
        {'d', 1},
        {'f', 1},
        {'g', 1},
        {'h', 1},
        {'j', 1},
        {'k', 1},
        {'l', 1},
        {'z', 2},
        {'x', 2},
        {'c', 2},
        {'v', 2},
        {'b', 2},
        {'n', 2},
        {'m', 2},
    };
    // 字母顺序与键盘顺序映射
    string rowIdx = "12210111011122000010020202";
};

void print(const vector<string> &vec)
{
    cout << "[";
    for (auto &s : vec)
    {
        cout << s.c_str() << " ";
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    KeyboardRow cls;
    // ["Alaska","Dad"]
    print(cls.findWords1(vector<string>{"Hello", "Alaska", "Dad", "Peace"}));
    // []
    print(cls.findWords1(vector<string>{"omk"}));
    // ["adsdf","sfd"]
    print(cls.findWords1(vector<string>{"adsdf", "sfd"}));
    return 0;
}
