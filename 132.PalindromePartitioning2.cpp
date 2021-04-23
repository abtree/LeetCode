#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//132. 分割回文串 II
class PalindromePartitioning2
{
    /*给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。返回符合要求的 最少分割次数 。
    */
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> g(n, vector<int>(n, true));
        //确定i...j是否是回文串
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];
            }
        }

        vector<int> f(n, INT_MAX);
        for (int i = 0; i < n; ++i) {   //逐步构建s
            if (g[0][i]) {  //0...i本身是回文串
                f[i] = 0;   //无需额外分割
            }
            else {  //需要额外分割
                for (int j = 0; j < i; ++j) {
                    if (g[j + 1][i]) {  //剩余部分为回文串
                        f[i] = min(f[i], f[j] + 1); //取切法最小的方案
                    }
                }
            }
        }

        return f[n - 1];
    }
public:
    int minCut2(string s) {
        //这个算法性能更好(原理与上面一样，只是将两步合并为一步)
        int n = s.size();
        vector<int> dp(n + 1, -1);
        iota(dp.begin(), dp.end(), 0); //初始化为最大值
        dp[0] = -1;
        for (int i = 0; i < n; i++) {
            func(i, i, s, dp);      //基数的情况(i为中心)
            func(i, i + 1, s, dp);  //偶数的情况
        }
        return dp[n];
    }
    void func(int l, int r, string& s, vector<int>& dp) {
        while (l >= 0 && r < s.size()) {
            if (s[l] == s[r]) {
                dp[r + 1] = min(dp[r + 1], dp[l] + 1); //这里是l+1...r为回文串
                r++;
                l--;
            }
            else
                return;
        }
    }
};

int main(int argc, char const* argv[])
{
    PalindromePartitioning2 cls;
    cout << cls.minCut2("aab") << " -> 1" << endl;
    cout << cls.minCut2("a") << " -> 0" << endl;
    cout << cls.minCut2("ab") << " -> 1" << endl;
    return 0;
}
