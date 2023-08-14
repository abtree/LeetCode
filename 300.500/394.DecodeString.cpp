#include <iostream>
#include <string>
using namespace std;

class DecodeString{
public:
    string decodeString(string s) {
        int p = 0;
        return decode(s, p);
    }
private:
    string decode(string& s, int& p) {
        string ret = "";
        int cnt = 0;
        //这里不考虑 字符串不合法的情况
        while (p < s.size() && s[p] != ']') {
            if (isnum(s[p])) {
                cnt = s[p] - '0';
                while (s[++p] != '[') {
                    cnt = cnt * 10 + (s[p] - '0');
                }
                string& substr = decode(s, ++p);
                for (int i = 0; i < cnt;++i) {
                    ret.append(substr);
                }
                ++p;
            }
            else {
                ret.push_back(s[p++]);
            }
        }
        return ret;
    }
    bool isnum(char c) {
        return (c >= '0' && c <= '9');
    }
};

int main(int argc, char const* argv[]) {
    DecodeString cls;
    cout << cls.decodeString("3[a]2[bc]").c_str() << " -> aaabcbc" << endl;
    cout << cls.decodeString("3[a2[c]]").c_str() << " -> accaccacc" << endl;
    cout << cls.decodeString("2[abc]3[cd]ef").c_str() << " -> abcabccdcdcdef" << endl;
    cout << cls.decodeString("abc3[cd]xyz").c_str() << " -> abccdcdcdxyz" << endl;
    return 0;
}
