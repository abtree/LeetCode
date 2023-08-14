#include <iostream>
#include <string>
using namespace std;

class IsSubsequence{
public:
    bool isSubsequence(string s, string t) {
        int ss = s.size();
        int ps = 0;
        int st = t.size();
        int pt = 0;
        while (ps < ss && pt < st) {
            if (s[ps] == t[pt]) {
                ++ps;
            }
            ++pt;
        }
        return ps == ss;
    }
};

int main(int argc, char const *argv[])
{
    IsSubsequence cls;
    cout << boolalpha << cls.isSubsequence("abc", "ahbgdc") << " -> true" << endl;
    cout << boolalpha << cls.isSubsequence("axc", "ahbgdc") << " -> false" << endl;
    return 0;
}