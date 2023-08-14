#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RepeatedSubstringPattern{
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s,1) != s.size();
    }
public:
    bool repeatedSubstringPattern1(string s) {
        //枚举
        int n = s.size();
        for(int i = 0; i < n/2;i++){
            if(n % (i+1) != 0)
                continue;
            int p = i+1;
            bool f = true;
            while(p < n){
                for(int j = 0; j<=i;++j){
                    if(s[p] != s[j]){
                        f = false;
                        break;
                    }
                    ++p;
                }
                if(!f){
                    break;
                }
            }
            if(f){
                return true;
            }
        }
        return false;
    }
public:
    bool kmp(const string& query, const string& pattern) {
        int n = query.size();
        int m = pattern.size();
        vector<int> fail(m, -1);
        for (int i = 1; i < m; ++i) {
            int j = fail[i - 1];
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = fail[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                fail[i] = j + 1;
            }
        }
        int match = -1;
        for (int i = 1; i < n - 1; ++i) {
            while (match != -1 && pattern[match + 1] != query[i]) {
                match = fail[match];
            }
            if (pattern[match + 1] == query[i]) {
                ++match;
                if (match == m - 1) {
                    return true;
                }
            }
        }
        return false;
    }

    bool repeatedSubstringPattern2(string s) {
         return kmp(s+s, s);
    }
public:
    bool kmp1(const string& pattern) {
        int n = pattern.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; ++i) {
            int j = fail[i - 1];
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = fail[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                fail[i] = j + 1;
            }
        }
        return fail[n - 1] != -1 && n % (n - fail[n - 1] - 1) == 0;
    }

    bool repeatedSubstringPattern3(string s) {
        return kmp1(s);
    }
};

int main(int argc, char const *argv[])
{
    RepeatedSubstringPattern cls;
    cout << boolalpha << cls.repeatedSubstringPattern3("abab") << " -> true" << endl;
    cout << boolalpha << cls.repeatedSubstringPattern3("aba") << " -> false" << endl;
    cout << boolalpha << cls.repeatedSubstringPattern3("abcabcabcabc") << " -> true" << endl;
    return 0;
}
