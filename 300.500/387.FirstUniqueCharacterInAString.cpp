#include <iostream>
#include <string>
#include <array>
#include <queue>
using namespace std;

class FirstUniqueCharacterInAString{
public:
    int firstUniqChar(string s) {
        array<int,26> used{};
        for(char c : s){
            used[c-'a']+=1;
        }
        for(int i = 0; i<s.size();++i){
            if(used[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};

int main(int argc, char const *argv[]){
    FirstUniqueCharacterInAString cls;
    cout << cls.firstUniqChar("leetcode") << " -> 0" << endl;
    cout << cls.firstUniqChar("loveleetcode") << " -> 2" << endl;
    return 0;
}
