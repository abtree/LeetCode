#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//72. 编辑距离
class EditDistance {
    /*
    给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
    你可以对一个单词进行如下三种操作：
    插入一个字符
    删除一个字符
    替换一个字符
     
    示例 1：
    输入：word1 = "horse", word2 = "ros"
    输出：3
    解释：
    horse -> rorse (将 'h' 替换为 'r')
    rorse -> rose (删除 'r')
    rose -> ros (删除 'e')

    示例 2：
    输入：word1 = "intention", word2 = "execution"
    输出：5
    解释：
    intention -> inention (删除 't')
    inention -> enention (将 'i' 替换为 'e')
    enention -> exention (将 'n' 替换为 'x')
    exention -> exection (将 'n' 替换为 'c')
    exection -> execution (插入 'u')
     
    提示：
    0 <= word1.length, word2.length <= 500
    word1 和 word2 由小写英文字母组成
    */
public:
    int minDistance(string word1, string word2) {
        //动态规划，一步一步构建word1和word2
        if (word1.compare(word2) == 0)
            return 0;   //两个字符串相同 不需要变化
        int c = word1.size();
        int r = word2.size();
        if (c == 0)
            return r;
        if (r == 0)
            return c;
        //注意这里需要从空字符串开始 而不是第一个字符 所以长度+1
        vector<vector<int>> dp(c + 1, vector<int>(r + 1, 0));
        for (int i = 0; i <= c;++i) {
            dp[i][0] = i;   //这里相当于用空字符串构建word1(实际是word2的子串变成空字符串)
        }
        for (int i = 0; i <= r;++i) {
            dp[0][i] = i;   //这里相当于用空字符串构建word2
        }
        /*
        当我们获得 D[i][j-1]，D[i-1][j] 和 D[i-1][j-1] 的值之后就可以计算出 D[i][j]。

        D[i][j-1] 为 A 的前 i 个字符和 B 的前 j - 1 个字符编辑距离的子问题。即对于 B 的第 j 个字符，我们在 A 的末尾添加了一个相同的字符，那么 D[i][j] 最小可以为 D[i][j-1] + 1；

        D[i-1][j] 为 A 的前 i - 1 个字符和 B 的前 j 个字符编辑距离的子问题。即对于 A 的第 i 个字符，我们在 B 的末尾添加了一个相同的字符，那么 D[i][j] 最小可以为 D[i-1][j] + 1；

        D[i-1][j-1] 为 A 前 i - 1 个字符和 B 的前 j - 1 个字符编辑距离的子问题。即对于 B 的第 j 个字符，我们修改 A 的第 i 个字符使它们相同，那么 D[i][j] 最小可以为 D[i-1][j-1] + 1。特别地，如果 A 的第 i 个字符和 B 的第 j 个字符原本就相同，那么我们实际上不需要进行修改操作。在这种情况下，D[i][j] 最小可以为 D[i-1][j-1]。

        若 A 和 B 的最后一个字母相同: D[i][j]=1+min(D[i][j−1],D[i−1][j],D[i−1][j−1]−1)
​	     若 A 和 B 的最后一个字母不同：D[i][j]=1+min(D[i][j−1],D[i−1][j],D[i−1][j−1])
        */
        for (int i = 1; i <= c;++i) {
            for (int j = 1; j <= r;++j) {
                int ij = (word1[i - 1] == word2[j - 1] ? (dp[i - 1][j - 1] - 1) : dp[i - 1][j - 1]);
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], ij)) + 1;
            }
        }
        return dp[c][r];
    }
};

int main()
{
    EditDistance cls;
    cout << cls.minDistance("horse", "ros") << " -> 3" << endl;
    cout << cls.minDistance("intention", "execution") << " -> 5" << endl;
    return 0;
}
