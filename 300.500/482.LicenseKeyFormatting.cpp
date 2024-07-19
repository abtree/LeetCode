#include <iostream>
#include <string>
using namespace std;

class LicenseKeyFormatting
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        string ans;
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] != '-')
            {
                ans.push_back(toupper(s[i]));
                ++cnt;
                if (cnt == k)
                {
                    ans.push_back('-');
                    cnt = 0;
                }
            }
        }
        if (ans.size() > 0 && ans.back() == '-')
        {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    LicenseKeyFormatting cls;
    cout << cls.licenseKeyFormatting("5F3Z-2e-9-w", 4).c_str() << " -> 5F3Z-2E9W" << endl;
    cout << cls.licenseKeyFormatting("2-5g-3-J", 2).c_str() << " -> 2-5G-3J" << endl;
    return 0;
}
