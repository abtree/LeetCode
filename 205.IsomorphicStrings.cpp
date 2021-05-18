#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class IsomorphicStrings
{
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> dp;
        unordered_set<char> ep;
        for (int i = 0;i < s.size(); ++i) {
            auto it = dp.find(s[i]);
            if (it == dp.end()) {
                if (ep.find(t[i]) != ep.end())
                    return false;
                dp[s[i]] = t[i];
                ep.insert(t[i]);
                continue;
            }
            if (it->second != t[i])
                return false;
        }
        return true;
    }
};

int main(int argc, char const* argv[])
{
    IsomorphicStrings cls;
    cout << boolalpha << cls.isIsomorphic("badc", "baba") << " -> false" << endl;
    cout << boolalpha << cls.isIsomorphic("egg", "add") << " -> true" << endl;
    cout << boolalpha << cls.isIsomorphic("foo", "bar") << " -> false" << endl;
    cout << boolalpha << cls.isIsomorphic("paper", "title") << " -> true" << endl;
    return 0;
}
