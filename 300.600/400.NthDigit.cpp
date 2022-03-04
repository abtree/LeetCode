#include <iostream>
#include <cmath>
using namespace std;

class NthDigit {
public:
    int findNthDigit(int n) {
        //暴力求解
        int step = 1;
        long long i = 0;
        int cnt = 0, x = 0, pw = 10;
        while (i < n) {
            ++x;
            if (x / pw > 0) {
                ++step;
                pw *= 10;
            }
            i += step;
        }
        x /= pow(10, i - n);
        x %= 10;
        return x;
    }
public:
    int findNthDigit2(int n) {
        /*  先找区间 再求值法
            如 1111
            n -> [0, 9] => [0, 9]       0到9产生9个数
              -> [10, 180] => [10, 99]  10到99产生90*2 = 180个
              -> [181, 2700] => [100, 999]  100到999产生900*3 = 1800个
                ....
            180 < 1111 < 1800 => 1111一定是个三位数
            (1111 - 99) / 2 = 307..1 推出1111是第308个三位数的第一位
            即 1111 -> 308+99 = 407 -> return 1
        */
        int min = 0, max = 9;   //落在相应位数的最小最大n 如：step=3 => [189, 2889]
        int step = 1, pw = 9;   // step是位数 pw是对应的数的个数 如 step = 3, pw = 900 <= [100,999]
        int x = 0;  // 9 99 999 9999 ...
        while (n > max) {
            min = max;
            pw *= 10;
            step += 1;
            x = x * 10 + 9;
            if (step >= 9)  //到这里就越界了   
                break;
            else
                max = pw * step+min;
        }
        n -= min;
        int cnt = n / step;
        int rem = n % step;
        cnt += x;
        if (rem == 0)
            return cnt % 10;
        cnt += 1;   //需要取下一个数
        while (step > rem) {
            cnt /= 10;
            step -= 1;
        }
        return cnt % 10;
    }
};

int main(int argc, char const* argv[]) {
    NthDigit cls;
    cout << cls.findNthDigit2(10000) << " -> 7" << endl;
    cout << cls.findNthDigit2(3) << " -> 3" << endl;
    cout << cls.findNthDigit2(11) << " -> 0" << endl;
    cout << cls.findNthDigit2(111) << " -> 0" << endl;
    cout << cls.findNthDigit2(1111) << " -> 4" << endl;
    cout << cls.findNthDigit2(2147483647) << " -> 2" << endl;
    return 0;
}
