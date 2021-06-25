#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

// 316. 去除重复字母
class RemoveDuplicateLetters {
    /* 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
    */
public:
    string removeDuplicateLetters(string s) {
        /* 贪心 加单调栈
            当s[i]入栈时，需要满足以下条件
                1.栈顶元素如果大于等于 s[i],且后面还会出现栈顶元素(包括s[i]) 栈顶元素需要移除
                2.s[i]之前已经入栈，则s[i]不入栈
        */
        vector<int> ret;
        int repeated[26] = {};
        int used[26] = {};
        for (char c : s) {
            repeated[c - 'a'] += 1;
        }
        for (char c : s) {
            int id = c - 'a';
            if (ret.empty()) {
                ret.push_back(c);
                used[id] = 1;
                repeated[id] -= 1;
                continue;
            }
            if (used[id] > 0) {
                repeated[id] -= 1;
                continue;
            }
            while (!ret.empty()) {
                if (ret.back() < c) {
                    break;  // 栈顶元素小于当前元素
                }
                if (repeated[ret.back() - 'a'] == 0) {
                    break;  //栈顶元素不会再出现 所以不能出栈
                }
                //栈顶元素出栈
                used[ret.back() - 'a'] = 0;
                ret.pop_back();
            }
            ret.push_back(c);
            used[id] = 1;
            repeated[id] -= 1;
        }
        return string(ret.begin(), ret.end());
    }
};

int main(int argc, char const* argv[]) {
    RemoveDuplicateLetters cls;
    cout << cls.removeDuplicateLetters("abacb").c_str() << " -> abc" << endl;
    cout << cls.removeDuplicateLetters("bcabc").c_str() << " -> abc" << endl;
    cout << cls.removeDuplicateLetters("cbacdcbc").c_str() << " -> acdb" << endl;
    return 0;
}
