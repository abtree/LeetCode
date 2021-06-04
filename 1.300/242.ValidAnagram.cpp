#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

//242. 有效的字母异位词
class ValidAnagram {
    /* 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
    */
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        //哈希比对
        unordered_map<char, int> src;
        unordered_map<char, int> dst;
        for (char c : s) {
            src[c] += 1;
        }
        for (char c : t) {
            dst[c] += 1;
        }
        for (auto& it : src) {
            if (it.second != dst[it.first])
                return false;
        }
        return true;
    }
public:
    bool isAnagram2(string s, string t) {
        //排序对比
        if (s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0;i < s.size(); ++i) {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
};

int main(int argc, char const* argv[]) {
    ValidAnagram cls;
    cout << boolalpha << cls.isAnagram("anagram", "nagaram") << "->true" << endl;
    cout << boolalpha << cls.isAnagram("rat", "car") << "->false" << endl;

    cout << boolalpha << cls.isAnagram2("anagram", "nagaram") << "->true" << endl;
    cout << boolalpha << cls.isAnagram2("rat", "car") << "->false" << endl;
    return 0;
}
