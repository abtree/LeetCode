#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class LongestUncommonSubsequence
{
public:
    int findLUSlength(string a, string b)
    {
        int m = a.size();
        int n = b.size();
        if (m != n || a != b)
        {
            return max(m, n);
        }
        return -1;
    }
};

int main()
{
    LongestUncommonSubsequence cls;
    cout << cls.findLUSlength("aba", "cdc") << " -> 3" << endl;
    cout << cls.findLUSlength("aaa", "bbb") << " -> 3" << endl;
    cout << cls.findLUSlength("aaa", "aaa") << " -> -1" << endl;
    return 0;
}
