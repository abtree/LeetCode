#include <iostream>
#include <string>

using namespace std;

//125. 验证回文串
class ValidPalindrome
{
    /*给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。说明：本题中，我们将空字符串定义为有效的回文串。
    */
public:
    bool isPalindrome(string s) {
        //双指针
        int pre = 0;
        int end = s.size() - 1;
        while (pre < end) {
            if (!isdigit(s[pre]) && !isalpha(s[pre])) {
                ++pre;
                continue;
            }
            if (!isdigit(s[end]) && !isalpha(s[end])) {
                --end;
                continue;
            }
            if (isdigit(s[pre]) || isdigit(s[end])) {
                if (s[pre] != s[end])
                    return false;
            }
            else {
                if (toupper(s[pre]) != toupper(s[end]))
                    return false;
            }
            ++pre;
            --end;
        }
        return true;
    }
};

int main(int argc, char const* argv[])
{
    ValidPalindrome cls;
    cout << boolalpha << cls.isPalindrome("A man, a plan, a canal: Panama") << " -> true" << endl;
    cout << boolalpha << cls.isPalindrome("race a car") << " -> false" << endl;
    return 0;
}
