#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 214. 最短回文串
class ShortestPalindrome
{
    /* 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
    */
public:
    string shortestPalindrome(string s) {
        int size = s.size() - 1;
        if (size < 1)
            return s;
        //先找出从开始能形成的最大回文串
        int e = size;
        for (;e > 0; --e) {
            if (isPalindrome(s, 0, e))
                break;
        }
        // //再找出从结尾能形成的最大回文串
        // int b = 0;
        // for (;b < size; ++b) {
        //     if (isPalindrome(s, b, size))
        //         break;
        // }
        // //判断从前往后补还是从后向前补
        // if (size - b > e) {   //补在后面
        //     string sub = s.substr(0, b);
        //     reverse(sub.begin(), sub.end());
        //     return s + sub;
        // }
        // else {  //补在前面
        string sub = s.substr(e + 1);
        reverse(sub.begin(), sub.end());
        return sub + s;
        //}
    }
private:
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
public:
    string shortestPalindrome2(string s) {
        int size = s.size();
        if (size < 2)
            return s;
        //先找出从开始能形成的最大回文串(利用KMP寻找最大前序回文串 提高效率)
        vector<int> fail(size, -1);
        for (int i = 1; i < size; ++i) {
            int j = fail[i - 1];
            while (j != -1 && s[j + 1] != s[i]) {
                j = fail[j];
            }
            if (s[j + 1] == s[i]) {
                fail[i] = j + 1;
            }
        }
        int best = -1;
        for (int i = size - 1; i >= 0; --i) {
            while (best != -1 && s[best + 1] != s[i]) {
                best = fail[best];
            }
            if (s[best + 1] == s[i]) {
                ++best;
            }
        }

        string sub = (best == size - 1 ? "" : s.substr(best + 1, size));
        reverse(sub.begin(), sub.end());
        return sub + s;
    }
public:
    string shortestPalindrome3(string s) {
        //manacher算法
        int end = -1;
        string t = s;
        s = "#";
        for (char c : t) {
            s += c;
            s += '#';
        }
        vector<int> armLen(s.size(), 0);
        int jright = -1; int j = -1;
        for (int i = 0; i < s.size();++i) {
            int curArmLen;
            if (jright >= i) {
                int iSym = j * 2 - i;
                int minArmLen = min(armLen[iSym], jright - i);
                curArmLen = armLens(s, i - minArmLen, i + minArmLen);
            }
            else {
                curArmLen = armLens(s, i, i);
            }
            armLen[i] = curArmLen;
            if (i + curArmLen > jright) {
                j = i;
                jright = i + curArmLen;
            }
            if (i - curArmLen == 0) {
                end = i + curArmLen;
            }
        }
        string pre = "";
        for (++end; end < s.size(); ++end) {
            if (s[end] != '#') {
                pre += s[end];
            }
        }
        reverse(pre.begin(), pre.end());
        return pre + t;
    }
private:
    int armLens(string& s, int start, int end) {
        while (start >= 0 && end < s.size() && s[start] == s[end]) {
            --start;
            ++end;
        }
        return (end - start - 2) / 2;
    }
};

int main(int argc, char const* argv[])
{
    ShortestPalindrome cls;
    cout << cls.shortestPalindrome3("aacecaaa").c_str() << " -> aaacecaaa" << endl;
    cout << cls.shortestPalindrome3("abcd").c_str() << " -> dcbabcd" << endl;
    cout << cls.shortestPalindrome3("abb").c_str() << " -> bbabb" << endl;
    return 0;
}
