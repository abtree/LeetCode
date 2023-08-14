#include <iostream>
#include <unordered_map>
using namespace std;

class CanIWin{
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (((maxChoosableInteger + 1) * maxChoosableInteger)/2 < desiredTotal){
            return false;
        }
        mem.clear();
        return dfs(maxChoosableInteger, 0, desiredTotal, 0);
    }
private:
    bool dfs(int maxChoosableInteger, int used, int desiredTotal, int cur){
        if(mem.count(used)){
            return mem[used];
        }
        bool ret = false;
        for(int i =0; i< maxChoosableInteger;++i){
            if(((used >> i) & 1) == 0){
                if(i+1+cur >= desiredTotal){
                    ret = true;
                    break;
                }
                //注意 这里返回true表示对方赢了 所以要取反
                if(!dfs(maxChoosableInteger, used | (1 << i), desiredTotal, cur+i+1)){
                    ret = true;
                    break;
                }
            }
        }
        mem[used] = ret;
        return ret;
    }
private:
    unordered_map<int, bool> mem;
};

int main(int argc, char const *argv[])
{
    CanIWin cls;
    cout << boolalpha << cls.canIWin(10, 11) << " -> false" << endl;
    cout << boolalpha << cls.canIWin(10, 0) << " -> true" << endl;
    cout << boolalpha << cls.canIWin(10, 1) << " -> true" << endl;
    return 0;
}
