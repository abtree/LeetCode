#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class LongestRepeatingCharacterReplacement{
public:
    int characterReplacement(string s, int k) {
        //第一种情况 最长连续字符数+k
        int ret = 0;
        int p = 0;
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[p]) {
                ret = max(ret, i - p);
                p = i;
            }
        }
        ret = max(ret, n - p);
        ret = min(n, ret + k);
        if (k == 0)
            return ret;
        //处理跨区间的情况
        ret = max(ret, check(s, k));
        return ret;
    }
private:
    int check(string& s, int k) {
        int p = 0, q = 0, x = 0;
        int ret = 0;
        int n = s.size();
        for (int i = 1; i < n;++i) {
            if (s[i] == s[p]) {
                continue;
            }
            if (q == p) {
                q = i;
            }
            if (x >= k) {
                ret = max(ret, i - p);
                p = q;
                i = q;
                x = 0;
                continue;
            }
            ++x;
        }
        ret = max(ret, n - p);
        return ret;
    }
public:
    int characterReplacement1(string s, int k) {
        //双指针，注意：统计的是双指针区间内最多字符+k
        vector<int> dp(26, 0);
        int n = s.size();
        int maxn = 0;   //用于统计主要字符个数
        int p = 0, q = 0;
        while (q < n) {
            ++dp[s[q] - 'A'];
            maxn = max(maxn, dp[s[q] - 'A']);
            //非主要字符超过k了
            if (q - p + 1 - maxn > k) {
                //注意 这里会照成区间可能不满足要求，不过不影响最终结果
                --dp[s[p] - 'A'];
                ++p;
            }
            ++q;
        }
        return q - p;
    }
};

int main(int argc, char const* argv[]) {
    LongestRepeatingCharacterReplacement cls;
    cout << cls.characterReplacement1("BAAAB", 2) << " -> 5" << endl;
    cout << cls.characterReplacement1("ABBB", 2) << " -> 4" << endl;
    cout << cls.characterReplacement1("AAAB", 0) << " -> 3" << endl;
    cout << cls.characterReplacement1("ABAB", 2) << " -> 4" << endl;
    cout << cls.characterReplacement1("AABABBA", 1) << " -> 4" << endl;
    return 0;
}
