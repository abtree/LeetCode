#include <iostream>
#include <array>
using namespace std;

class RansomNode{
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(auto c : magazine){
            counts[c-'a'] += 1;
        }
        for(char c : ransomNote){
            if(counts[c-'a'] <= 0)
                return false;
            counts[c-'a'] -= 1;
        }
        return true;
    }
    void clear(){
        for(int i = 0; i< 26;++i){
            counts[i] = 0;
        }
    }
private:
    array<int, 26> counts{};
};

int main(int argc, char const *argv[])
{
    RansomNode cls;
    cout << boolalpha << cls.canConstruct("a","b") << " -> false " << endl;
    cls.clear();
    cout << boolalpha << cls.canConstruct("aa","ab") << " -> false " << endl;
    cls.clear();
    cout << boolalpha << cls.canConstruct("aa","aab") << " -> true " << endl;
    return 0;
}
