#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//76. 最小覆盖子串
class MinimumCoverSubstring {
    /*
    给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
    注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

    示例 1：
    输入：s = "ADOBECODEBANC", t = "ABC"
    输出："BANC"

    示例 2：
    输入：s = "a", t = "a"
    输出："a"
     
    提示：
    1 <= s.length, t.length <= 105
    s 和 t 由英文字母组成
    */
public:
    string minWindow(string s, string t) {
        //先处理t
        unordered_map<char, int> ts;
        for (char c : t) {
            ts[c] += 1;
        }
        int oi = 0; //记录上一次匹配成功起始位置
        int oj = -1; //记录上次匹配成功的结束位置
        int ot = INT_MAX;  //记录上次匹配成功的长度
        int i = 0, j = 0;   //记录当前窗口
        for (;j < s.size();++j) {
            if (ts.find(s[j]) == ts.end())
                continue;
            ts[s[j]] -= 1;
            if (checkTs(ts)) {
                //开始收缩
                while (i <= j) {
                    if (ts.find(s[i]) == ts.end()) {
                        ++i;
                        continue;
                    }
                    ts[s[i]] += 1;
                    if (ts[s[i]] == 1) {    //匹配到最短了
                        if (j - i < ot) {   //新匹配的更短
                            oi = i;
                            oj = j;
                            ot = j - i;
                        }
                        ++i;
                        break;
                    }
                    ++i;
                }
            }
        }
        if (oj < 0)    //表示一次都没有匹配成功
            return "";
        return s.substr(oi, ot + 1);    //返回最后一次匹配成功的记录
    }
private:
    bool checkTs(unordered_map<char, int>& ts) {
        for (auto& it : ts) {
            if (it.second > 0)
                return false;
        }
        return true;
    }
};

int main() {
    MinimumCoverSubstring cls;
    cout << cls.minWindow("ADOBECODEBANC", "ABC").c_str() << " -> BANC" << endl;
    cout << cls.minWindow("a", "a").c_str() << " -> a" << endl;
    cout << cls.minWindow("abbbbca", "abc").c_str() << " -> bca" << endl;
}