#include <iostream>
#include <vector>
#include <string>
using namespace std;

class StringCompression
{
public:
    int compress(vector<char>& chars) {
        char cur = chars[0];
        int n = chars.size();
        int p = 0;
        int cnt = 1;
        for (int i = 1; i < n;++i) {
            if (chars[i] == cur) {
                ++cnt;
            }
            else {
                chars[p] = cur;
                ++p;
                if (cnt > 1) {
                    string s = to_string(cnt);
                    for (char c : s) {
                        chars[p] = c;
                        ++p;
                    }
                    cnt = 1;
                }
                cur = chars[i];
            }
        }
        chars[p] = cur;
        ++p;
        if (cnt > 1) {
            string s = to_string(cnt);
            for (char c : s) {
                chars[p] = c;
                ++p;
            }
        }
        return p;
    }
};

void Print(vector<char>& dat, int len) {
    cout << "len:" << len << " [";
    for (int i = 0;i < len;++i) {
        cout << dat[i] << ", ";
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    StringCompression cls;
    vector<char> dat{ 'a','a','b','b','c','c','c' };
    int len = cls.compress(dat);
    Print(dat, len);

    dat = vector<char>{ 'a' };
    len = cls.compress(dat);
    Print(dat, len);
    
    dat = vector<char>{ 'a','b','b','b','b','b','b','b','b','b','b','b','b' };
    len = cls.compress(dat);
    Print(dat, len);
    return 0;
}
