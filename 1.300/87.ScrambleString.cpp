#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//87. 扰乱字符串
class ScrambleString {
    /*
    给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。
    下图是字符串 s1 = "great" 的一种可能的表示形式
    在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。
    例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat"
    我们将 "rgeat” 称作 "great" 的一个扰乱字符串。
    同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。
    我们将 "rgtae” 称作 "great" 的一个扰乱字符串。
    给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。

    示例 1:
    输入: s1 = "great", s2 = "rgeat"
    输出: true

    示例 2:
    输入: s1 = "abcde", s2 = "caebd"
    输出: false
    */
public:
    bool isScramble(string s1, string s2) {
        //暴力解法(逐个子串匹配，直到得到结果)
        //这种解法会超时
        int size = s1.size();
        if (size != s2.size())
            return false;
        if (s1.compare(s2) == 0)
            return true;
        if (size == 1)
            return false;
        for (int i = 1; i < size; ++i) {
            //情况1：前半部分和前半部分匹配 后半部分和后半部分匹配
            if (isScramble(s1.substr(0, i), s2.substr(0, i))
                && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            //情况2：前半部分与后半部分匹配 后半部分与前半部分匹配
            if (isScramble(s1.substr(0, i), s2.substr(size - i))
                && isScramble(s1.substr(i), s2.substr(0, size - i)))
                return true;
        }
        return false;
    }
public:
    bool isScramble2(string s1, string s2) {
        //通过dp减少匹配次数
        int size = s1.size();
        if (size != s2.size())
            return false;
        if (s1.compare(s2) == 0)
            return true;
        /*
        dp[i][j][len]   表示s1从i开始长度为len的子串 与 s2从j开始长度为len的子串是否匹配
        dp[i][j][len] 为true的条件需要满足以下条件之一(将子串分割为0~w,w~len的两个子串)
            1) dp[i][j][w] = true && dp[i + w][j + w][len - w] = true     //子串的前半部分与前半部分匹配 后半部分与后半部分匹配
            2) dp[i][j + len - w][w] = true && dp[i + w][j][len - w] = true //子串的前半部分与后半部分匹配 后半部分与前半部分匹配
        */
        vector<vector<vector<bool>>> dp(size, vector<vector<bool>>(size, vector<bool>(size+1, 0)));
        //初始化单个字符串的情况
        for(int i =0;i<size;++i){
            for(int j =0;j<size;++j){
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        //枚举区间长度2~size
        for(int len = 2; len <= size;++len){
            //枚举s1中的起始位置
            for(int i =0;i<=size-len;++i){
                //枚举s2中的起始位置
                for(int j =0;j<=size-len;++j){
                    //枚举划分位置
                    for(int k = 1; k<=len-1;++k){
                        //情况1：前半部分和前半部分匹配 后半部分和后半部分匹配
                        if(dp[i][j][k] && dp[i+k][j+k][len-k]){
                            dp[i][j][len] = true;
                            break;
                        }
                        //情况2：前半部分与后半部分匹配 后半部分与前半部分匹配
                        if(dp[i][j+len-k][k] && dp[i+k][j][len-k]){
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][size];
    }
public:
    //(暴力匹配的优化版)
    unordered_map<string, bool> vis;    //通过记录以匹配的子串减少匹配次数(多次使用该匹配函数时，性能更优,但内存消耗更大)
    bool isScramble3(string s1, string s2) {
        int n = s1.length();
        if (string(s1.rbegin(), s1.rend()) == s2) return true; //倒叙相等
        if (s1 == s2) return true;  //正序相等
        //这一步检查两个字符串字母是否完全相同(顺序无关)
        int dic[26] = {0};
        for (int i = 0; i < n; i++) {
            dic[s1[i] - 'a']++;
            dic[s2[i] - 'a']--;
        }
        for (const auto& n : dic) if (n) return false;
        //检查是否是已经匹配过的子串
        string t = s1 + " " + s2;
        auto it = vis.find(t);
        if (it != vis.end()) return it->second;
        //如果是没匹配过的 匹配一次
        bool res = false;
        for (int i = 1; i < n; i++) {
            res = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i));
            if (res) break;
            res = isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i));
            if (res) break; 
        }
        vis[t] = res; //标记为匹配过的字符串
        return res; //返回匹配结果
    }
};

int main(int argc, char const* argv[])
{
    ScrambleString cls;
    cout << boolalpha << cls.isScramble3("great", "rgeat") << " -> true" << endl;
    cout << boolalpha << cls.isScramble3("abcde", "caebd") << " -> false" << endl;
    cout << boolalpha << cls.isScramble3("a", "a") << " -> true" << endl;
    cout << boolalpha << cls.isScramble3("abcdefghijklmnopq", "efghijklmnopqcadb") << " -> false" << endl;
    return 0;
}
