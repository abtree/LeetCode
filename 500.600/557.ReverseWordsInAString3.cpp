#include <iostream>
#include <string>
using namespace std;

class ReverseWordsInAString3
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        int p = 0;
        for (int x = 0; x <= n; ++x)
        {
            if (x == n || isspace(s[x]))
            {
                int q = x - 1;
                while (p < q)
                {
                    swap(s[p], s[q]);
                    ++p;
                    --q;
                }
                p = x + 1;
            }
        }
        return s;
    }
};

int main()
{
    ReverseWordsInAString3 cls;
    cout << cls.reverseWords("Let's take LeetCode contest").c_str() << " s'teL ekat edoCteeL tsetnoc" << endl;
    cout << cls.reverseWords("Mr Ding").c_str() << " rM gniD" << endl;
    return 0;
}
