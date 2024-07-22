#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PermutationInString
{
public:
    bool checkInclusion1(string s1, string s2)
    {
        if (s2.size() < s1.size())
        {
            return false;
        }
        vector<int> va(26, 0);
        vector<int> vb(26, 0);
        for (char c : s1)
        {
            va[c - 'a']++;
        }
        int len = s1.size();
        for (int i = 0; i < len; ++i)
        {
            vb[s2[i] - 'a']++;
        }
        if (va == vb)
        {
            return true;
        }
        int i = len;
        while (i < s2.size())
        {
            vb[s2[i - len] - 'a']--;
            vb[s2[i] - 'a']++;
            if (va == vb)
            {
                return true;
            }
            ++i;
        }
        return false;
    }
    bool checkInclusion2(string s1, string s2)
    {
        int ss1 = s1.size();
        int ss2 = s2.size();
        if (ss2 < ss1)
        {
            return false;
        }
        vector<int> dp(26, 0);
        int diff = 0;
        for (int i = 0; i < ss1; i++)
        {
            dp[s1[i] - 'a']++;
            dp[s2[i] - 'a']--;
        }
        for (int c : dp)
        {
            if (c != 0)
                ++diff;
        }
        if (diff == 0)
        {
            return true;
        }

        int i = ss1;
        while (i < ss2)
        {
            int x = s2[i - ss1] - 'a';
            int y = s2[i] - 'a';
            if (x == y)
            {
                ++i;
                continue;
            }
            if (dp[x] == 0)
            {
                ++diff;
            }
            --dp[x];
            if (dp[x] == 0)
            {
                --diff;
            }
            if (dp[y] == 0)
            {
                ++diff;
            }
            ++dp[y];
            if (dp[y] == 0)
            {
                --diff;
            }
            if (diff == 0)
            {
                return true;
            }
            ++i;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    PermutationInString cls;
    cout << boolalpha << cls.checkInclusion2("ab", "eidbaooo") << " -> true " << endl;
    cout << boolalpha << cls.checkInclusion2("ab", "eidboaoo") << " -> false " << endl;
    return 0;
}
