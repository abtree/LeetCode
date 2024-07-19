#include <iostream>
#include <string>
using namespace std;

class DetectCapital
{
public:
    bool detectCapitalUse(string word)
    {
        int cap = 0;
        for (char c : word)
        {
            if (isupper(c))
            {
                ++cap;
            }
        }
        if (cap == 0 || cap == word.size())
        {
            return true;
        }
        if (cap == 1 && isupper(word[0]))
        {
            return true;
        }
        return false;
    }
    bool detectCapitalUse1(string word)
    {
        int n = word.size();
        // 如果超过2个字符
        if (n >= 2)
        {
            // 第一个字符小写 第二个字符必须小写
            if (islower(word[0]) && isupper(word[1]))
            {
                return false;
            }
            // 之后的字符必须与第二个字符一致
            int b = islower(word[1]);
            for (int i = 2; i < n; ++i)
            {
                if (b ^ islower(word[i]))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    DetectCapital cls;
    cout << boolalpha << (true ^ true) << endl;
    cout << boolalpha << cls.detectCapitalUse1("ggg") << " -> true" << endl;
    cout << boolalpha << cls.detectCapitalUse1("USA") << " -> true" << endl;
    cout << boolalpha << cls.detectCapitalUse1("FlaG") << " -> false" << endl;
    return 0;
}
