#include<iostream>
#include<string>
#include<utility>
using namespace std;

class ReverseVowelsOfAString {
public:
    string reverseVowels(string s) {
        int b = 0, e = s.size() - 1;
        while (b < e) {
            if (!isVowel(s[b])) {
                ++b;
                continue;
            }
            if (!isVowel(s[e])) {
                --e;
                continue;
            }
            swap(s[b], s[e]);
            ++b;
            --e;
        }
        return s;
    }
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

int main(int argc, char const* argv[]) {
    ReverseVowelsOfAString cls;
    cout << cls.reverseVowels("hello").c_str() << " -> holle" << endl;
    cout << cls.reverseVowels("leetcode").c_str() << " -> leotcede" << endl;
    return 0;
}
