#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class LongestPalindrome
{
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> dp;
        for (char c : s) {
            dp[c] += 1;
        }
        int ret = 0;
        for (auto& it : dp) {
            if (it.second & 1) {
                ret += it.second - 1;
            }
            else {
                ret += it.second;
            }
        }
        if (ret < s.size())
            ret += 1;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    LongestPalindrome cls;
    cout << cls.longestPalindrome("abccccdd") << " -> 7" << endl;
    cout << cls.longestPalindrome("a") << " -> 1" << endl;
    cout << cls.longestPalindrome("bb") << " -> 2" << endl;
    return 0;
}
