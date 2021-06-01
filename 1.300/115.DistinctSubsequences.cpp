#include <iostream>
#include <string>
#include <vector>

using namespace std;

//115. 不同的子序列
class DistinctSubsequences {
    /*给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）题目数据保证答案符合 32 位带符号整数范围。
    */
public:
    int numDistinct(string s, string t) {
        //回溯法(会超时)
        mAns = 0;
        distinct(s, t, 0, 0);
        return mAns;
    }
private:
    void distinct(string& s, string& t, int sp, int tp) {
        for (int i = sp; i < s.size(); ++i) {
            if (s[i] != t[tp])
                continue;
            ++tp;
            if (tp >= t.size()) {
                ++mAns;
                --tp;
                continue;
            }
            distinct(s, t, i + 1, tp);
            --tp;
        }
    }
private:
    int mAns{};
public:
    int numDistinct2(string s, string t) {
        /* 动态规划 s.size() = m; t.size() = n; i表示i->m之间的子串; j表示j->n之间的子串
        边界条件:
            1) 当j=n时,j为空串, {dp[i][n] = 1 | 0<=i<=m}
            2) 当i=m时,i为空串, {dp[m][j] = 0 | 0<=j<n}
        推导方程
            s[i]=t[j]时, dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
            s[i]!=t[j]时, dp[i][j] = dp[i+1][j]
        */
        int m = s.size();
        int n = t.size();
        if (m < n) return 0;
        if (m == n) { //这里需要特殊处理 是为了防止越界
            if (s == t)
                return 1;
            return 0;
        }
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0)); //中间过程可能会越界
        for (int i = 0; i <= m; ++i) {
            dp[i][n] = 1;
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = dp[i + 1][j];
                if (s[i] == t[j])
                    dp[i][j] += dp[i + 1][j + 1];
            }
        }
        return (int)dp[0][0];
    }
};

int main(int argc, char const* argv[])
{
    DistinctSubsequences cls;
    cout << cls.numDistinct2("rabbbit", "rabbit") << " -> 3" << endl;
    cout << cls.numDistinct2("babgbag", "bag") << " -> 5" << endl;
    cout << cls.numDistinct2("adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc", "bcddceeeebecbc") << " -> 700531452" << endl;
    cout << cls.numDistinct2("xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo", "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys") << " -> 543744000" << endl;
    return 0;
}
