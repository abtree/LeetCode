#include <iostream>
#include <string>
using namespace std;

class ReverseString2
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.size();
        int p = 0, q = k;
        while (p < n)
        {
            if (q > n)
            {
                q = n;
            }
            int m = q - 1;
            while (p < m)
            {
                char c = s[m];
                s[m] = s[p];
                s[p] = c;
                ++p;
                --m;
            }

            p = q + k;
            q += 2 * k;
        }
        return s;
    }
};

int main()
{
    ReverseString2 cls;
    cout << cls.reverseStr("abcdefg", 2).c_str() << " -> bacdfeg" << endl;
    cout << cls.reverseStr("abcd", 2).c_str() << " -> bacd" << endl;
    return 0;
}
