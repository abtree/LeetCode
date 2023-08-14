#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class UniqueSubstringsInWraparoundString{
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26);
        /*k表示已字母s[i]结尾的子字符串有k个
          如 s[i] == 'd' k==3
          表示以字母d结尾的子串有三个，即"bcd","cd","d"
        */
        int k = 0;  
        for (int i =0;i<s.length();++i){
            // 'a' - 'z' == -25
            if(i > 0 && (s[i] - s[i-1] == 1 || s[i] - s[i-1] == -25)){
                ++k;
            }else{
                k = 1;
            }
            dp[s[i]-'a'] = max(dp[s[i]-'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main(){
    UniqueSubstringsInWraparoundString cls;
    cout << cls.findSubstringInWraproundString("a") << " -> 1" << endl;
    cout << cls.findSubstringInWraproundString("cac") << " -> 2" << endl;
    cout << cls.findSubstringInWraproundString("zab") << " -> 6" << endl;
    return 0;
}
