#include <iostream>
using namespace std;

// 342. 4的幂
class PowerOfFour {
    /* 给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x
    */
public:
    bool isPowerOfFour(int n) {
        //4^15 = 1073741824
        //return n > 0 && (1073741824 % n == 0);
        if (n > 1073741824) //4^15
            return false;
        int i = 1;
        while (i < n) {
            i *= 4;
        }
        return i == n;
    }
public:
    bool isPowerOfFour1(int n) {
        return n > 0 &&
            (n & (n - 1)) == 0    //表示只有一个1
            && (n & 0xaaaaaaaa) == 0;    //表示1只出现在基数位上 即1后面有偶数个0（含0个）
    }
};

int main(int argc, char const* argv[]) {
    PowerOfFour cls;
    cout << boolalpha << cls.isPowerOfFour1(8) << " -> false" << endl;
    cout << boolalpha << cls.isPowerOfFour1(2) << " -> false" << endl;
    cout << boolalpha << cls.isPowerOfFour1(16) << " -> true" << endl;
    cout << boolalpha << cls.isPowerOfFour1(5) << " -> false" << endl;
    cout << boolalpha << cls.isPowerOfFour1(1) << " -> true" << endl;
    return 0;
}
