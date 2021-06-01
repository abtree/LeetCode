#include <iostream>
#include <algorithm>
using namespace std;

//233. 数字 1 的个数
class NumberOfDigitOne {
    /* 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
    */
public:
    int countDigitOne(int n) {
        int cnt = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long div = i * 10;
            cnt += (n / div) * i + min(max(n % div - i + 1, 0LL), i);
        }
        return cnt;
    }
};

int main(int argc, char const* argv[])
{
    NumberOfDigitOne cls;
    cout << cls.countDigitOne(13) << "->6" << endl;
    cout << cls.countDigitOne(0) << "->0" << endl;
    cout << cls.countDigitOne(1234) << "->689" << endl;
    return 0;
}
