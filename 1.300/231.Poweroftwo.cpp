#include <iostream>
#include <bitset>
using namespace std;

// 231. 2 的幂
class Poweroftwo {
    /* 给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
    如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。
    */
public:
    bool isPowerOfTwo(int n) {
        if(n == INT_MIN)
            return false;
        bitset<32> bc(n);
        return bc.count() == 1;
    }
public:
    bool isPowerOfTwo2(int n) {
        int cnt = 0;
        for(int i = 0; i< 32 && n > 0; ++i){
            if(n & 1){
                ++cnt;
                if(cnt > 1)
                    return false;
            }
            n >>= 1;
        }
        return cnt == 1;
    }
public:
    bool isPowerOfTwo3(int n) {
        return n > 0 && (n & (n-1)) == 0;   // n & (n-1) 是将n的最后一个1去掉， 如果他是2的幂次 剩余的就为0
    }
};

int main(int argc, char const *argv[])
{
    Poweroftwo cls;
    cout << boolalpha << cls.isPowerOfTwo3(INT_MIN) << "->false"<<endl;
    cout << boolalpha << cls.isPowerOfTwo3(1) << "->true"<<endl;
    cout << boolalpha << cls.isPowerOfTwo3(16) << "->true"<<endl;
    cout << boolalpha << cls.isPowerOfTwo3(3) << "->false"<<endl;
    cout << boolalpha << cls.isPowerOfTwo3(4) << "->true"<<endl;
    cout << boolalpha << cls.isPowerOfTwo3(5) << "->false"<<endl;
    return 0;
}
