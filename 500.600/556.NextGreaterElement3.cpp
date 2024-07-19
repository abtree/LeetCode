#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class NextGreaterElement3
{
public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        int l = s.size();
        if (l < 2)
        {
            return -1;
        }
        if (dfs(s, l - 2))
        {
            long long r = atoll(s.c_str());
            if (r > INT_MAX)
            {
                return -1;
            }
            return int(r);
        }
        return -1;
    }

private:
    bool dfs(string &s, int p)
    {
        if (p < 0)
        {
            return false;
        }
        for (int i = s.size() - 1; i > p; --i)
        {
            if (s[i] > s[p])
            {
                swap(s[i], s[p]);
                sort(s.begin() + p + 1, s.end());
                return true;
            }
        }
        return dfs(s, p - 1);
    }
};

int main()
{
    NextGreaterElement3 cls;
    cout << cls.nextGreaterElement(2147483476) << " -> 2147483647" << endl;
    cout << cls.nextGreaterElement(230241) << " -> 230412" << endl;
    cout << cls.nextGreaterElement(13) << " -> 31" << endl;
    cout << cls.nextGreaterElement(1234) << " -> 1243" << endl;
    cout << cls.nextGreaterElement(12) << " -> 21" << endl;
    cout << cls.nextGreaterElement(21) << " -> -1" << endl;
    return 0;
}
