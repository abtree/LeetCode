#include <iostream>
#include <string>
#include <array>
#include <unordered_map>
#include <algorithm>
using namespace std;

class LongestSubstringWithAtLeastKRepeatingCharacters{
public:
    int longestSubstring(string s, int k) {
        unordered_map<int, int> dp;
        for (char c : s) {
            dp[c - 'a'] += 1;
        }
        return longest(dp, s, 0, s.size(), k);
    }
private:
    int longest(unordered_map<int, int>& dp, string& s, int b, int e, int k) {
        int x = check(dp, k);
        if (x > 0)
            return x;
        unordered_map<int, int> tmp;
        int len = 0;
        int p = b;
        for (int i = b; i < e;++i) {
            if (dp[s[i] - 'a'] >= k) {
                tmp[s[i] - 'a'] += 1;
                continue;
            }
            if (i - p >= k)
                len = max(len, longest(tmp, s, p, i, k));
            for (auto& x : tmp) {
                dp[x.first] -= x.second;
            }
            tmp.clear();
            p = i + 1;
        }
        if (e - p >= k)
                len = max(len, longest(tmp, s, p, e, k));
        return len;
    }
    int check(unordered_map<int, int>& tmp, int k) {
        int ret = 0;
        for (auto& it : tmp) {
            if (it.second < k)
                return 0;
            ret += it.second;
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    LongestSubstringWithAtLeastKRepeatingCharacters cls;
    cout << cls.longestSubstring("aabcabb", 3) << " -> 0" << endl;
    cout << cls.longestSubstring("bbaaacbd", 3) << " -> 3" << endl;
    cout << cls.longestSubstring("aaabb", 3) << " -> 3" << endl;
    cout << cls.longestSubstring("ababbc", 2) << " -> 5" << endl;
    return 0;
}
