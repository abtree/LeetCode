#include <iostream>
#include <string>
#include <vector>

using namespace std;

//97. 交错字符串
class InterleavingString {
    /*
    给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：
    s = s1 + s2 + ... + sn;
    t = t1 + t2 + ... + tm;
    |n - m| <= 1
    交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
    提示：a + b 意味着字符串 a 和 b 连接。

    示例 1：
    输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
    输出：true

    示例 2：
    输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
    输出：false

    示例 3：
    输入：s1 = "", s2 = "", s3 = ""
    输出：true
    */
public:
    bool isInterleave(string s1, string s2, string s3) {
        /* 动态规划
        设i为s1的前i个字符；j为s2的前j个字符;p=i+j为s3的前p个字符
        f(i,j)为true表示s1的前i个字符和s2的前j个字符匹配
        f(i,j)=true有两种情况
            1) f(i-1,j) = true && s1[i-1] == s3[i+j-1]
            2) f(i,j-1) = true && s2[j-1] == s3[i+j-1]
        由于空字符串一定是匹配的,所以f(0,0)=true
        */
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size())
            return false;    //这种情况一定是匹配不上的

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m;++i) {
            for (int j = 0;j <= n;++j) {
                if (i > 0) {
                    dp[i][j] |= dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                }
                if (j > 0) {
                    dp[i][j] |= dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char const* argv[])
{
    InterleavingString cls;
    cout << boolalpha << cls.isInterleave("aabcc", "dbbca", "aadbbcbcac") << "-> true" << endl;
    cout << boolalpha << cls.isInterleave("aabcc", "dbbca", "aadbbbaccc") << "-> false" << endl;
    cout << boolalpha << cls.isInterleave("", "", "") << "-> true" << endl;
    return 0;
}
