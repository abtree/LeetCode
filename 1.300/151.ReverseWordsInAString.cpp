#include <iostream>
#include <string>

using namespace std;

//151. 翻转字符串里的单词
class ReverseWordsInAString
{
    /*给定一个字符串，逐个翻转字符串中的每个单词。
    说明：无空格字符构成一个 单词 。输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
    */
public:
    string reverseWords(string s) {
        int tail = s.size() - 1;
        string str = "";
        int len = 0;
        for (;tail >= 0; --tail) {
            if (s[tail] == ' ') {
                if (len == 0)
                    continue;
                str.append(s.substr(tail + 1, len));
                str.append(" ");
                len = 0;
            }
            else {
                ++len;
            }
        }
        if (len > 0) {
            str.append(s.substr(0, len));
        }
        else {
            str.pop_back();
        }
        return str;
    }
};

int main(int argc, char const* argv[])
{
    ReverseWordsInAString cls;

    cout << cls.reverseWords("the sky is blue").c_str() << endl;
    cout << cls.reverseWords("  hello world!  ").c_str() << endl;
    cout << cls.reverseWords("a good   example").c_str() << endl;
    cout << cls.reverseWords("  Bob    Loves  Alice   ").c_str() << endl;
    cout << cls.reverseWords("Alice does not even like bob").c_str() << endl;
    return 0;
}
