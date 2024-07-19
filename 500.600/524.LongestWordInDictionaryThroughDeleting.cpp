#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class LongestWordInDictionaryThroughDeleting
{
public:
    string findLongestWord(string s, const vector<string> &dictionary)
    {
        int cur = -1;
        int n = dictionary.size();
        for (int i = 0; i < n; ++i)
        {
            if (isSubstr(dictionary[i], s))
            {
                if (cur != -1)
                {
                    if (dictionary[cur].size() < dictionary[i].size())
                    {
                        cur = i;
                    }
                    else if (dictionary[cur].size() == dictionary[i].size() && dictionary[cur] > dictionary[i])
                    {
                        cur = i;
                    }
                }
                else
                {
                    cur = i;
                }
            }
        }
        if (cur == -1)
        {
            return "";
        }
        return dictionary[cur];
    }

private:
    bool isSubstr(const string &t, const string &s)
    {
        int pt = 0, ps = 0;
        int nt = t.size(), ns = s.size();
        if (nt > ns)
        {
            return false;
        }
        while (pt < nt && ps < ns)
        {
            if (t[pt] == s[ps])
            {
                ++pt;
            }
            ++ps;
        }
        return pt == nt;
    }

public:
    // 先排序再匹配
    string findLongestWord1(string s, vector<string> dictionary)
    {
        sort(dictionary.begin(), dictionary.end(), [](const string &a, const string &b)
             { return a.size() > b.size() || (a.size() == b.size() && a < b); });
        for (const string &t : dictionary)
        {
            if (isSubstr(t, s))
            {
                return t;
            }
        }
        return "";
    }
};

int main()
{
    LongestWordInDictionaryThroughDeleting cls;
    cout << cls.findLongestWord1("abpcplea", vector<string>{"ale", "apple", "monkey", "plea"}) << " -> apple" << endl;
    cout << cls.findLongestWord1("abpcplea", vector<string>{"a", "b", "c"}) << " -> a" << endl;
    return 0;
}
