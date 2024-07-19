#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class LongestUncommonSubsequence2
{
public:
    int findLUSlength(const vector<string> &strs)
    {
        int n = strs.size();
        int ans = -1;
        for (int i = 0; i < n; ++i)
        {
            bool b = true;
            const string &s = strs[i];
            int ns = s.size();
            for (int j = 0; j < n; ++j)
            {
                // 同一个字符串
                if (i == j)
                {
                    continue;
                }
                // 不需要判断
                if (ns > strs[j].size())
                {
                    continue;
                }
                // 长度相等 只需要判断字符串是否相等
                // if (ns == strs[j].size())
                // {
                //     if (s == strs[j])
                //     {
                //         b = false;
                //         break; // 判断失败
                //     }
                //     else
                //     {
                //         continue;
                //     }
                // }
                if (isSubstring(s, strs[j]))
                {
                    b = false;
                    break;
                }
            }
            if (b)
            {
                ans = max(ans, ns);
            }
        }
        return ans;
    }

private:
    bool isSubstring(const string &s, const string &t)
    {
        int ps = 0, pt = 0;
        int ns = s.size(), nt = t.size();
        while (ps < ns && pt < nt)
        {
            if (s[ps] == t[pt])
            {
                ++ps;
            }
            ++pt;
        }
        return ps == ns;
    }
};

int main()
{
    LongestUncommonSubsequence2 cls;
    cout << cls.findLUSlength(vector<string>{"aba", "cdc", "eae"}) << " -> 3" << endl;
    cout << cls.findLUSlength(vector<string>{"aaa", "aaa", "aa"}) << " -> -1" << endl;
    return 0;
}
