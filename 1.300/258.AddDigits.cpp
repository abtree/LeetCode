#include <iostream>
using namespace std;

// 258. 各位相加
class AddDigits {
    /* 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
    */
public:
    int addDigits(int num) {
        int ret = 0;
        while (num > 9) {
            ret = 0;
            while (num > 0) {
                ret += num % 10;
                num /= 10;
            }
            num = ret;
        }
        return num;
    }
public:
    int addDigits2(int num) {
        /* 公式推导 num = xyzk = 1000x + 100y + 10z + k = 999x + 99y + 9z + (x + y + z + k)
           例：38 = 3*10+8 = 3*9+3+8 = 3*9+11 (第一次迭代)
                  = 3*9+1*10+1=3*9+1*9+1+1=3*9+1*9+2 (第二次迭代)
            由此可见：最终的结果为 num = 9x+y (y < 10)
        */
        if (num < 10)
            return num;
        return (num - 1) % 9 + 1;
    }
};

int main(int argc, char const* argv[]) {
    AddDigits cls;
    cout << cls.addDigits(38) << " -> 2" << endl;
    cout << cls.addDigits2(38) << " -> 2" << endl;
    return 0;
}
