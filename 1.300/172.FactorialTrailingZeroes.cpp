#include <iostream>
using namespace std;

//172. 阶乘后的零
class FactorialTrailingZeroes
{
    /* 给定一个整数 n，返回 n! 结果尾数中零的数量。
    */
public:
    int trailingZeroes(int n) {
        /* 因式分解 只需要统计分解后 有多少个5 (因为5*2=10，而2一定比5多)
        */
        int ret = 0;
        for (int i = 5;i <= n;i += 5) {
            ++ret;
            int fact = 25;  //如果是25 需要算2个5 (5*5) 125算三个 以此类推
            while (i % fact == 0) {
                ++ret;
                fact *= 5;
            }
        }
        return ret;
    }
public:
    int trailingZeroes2(int n) {
        /* 因式分解高级版 fives = n/5 + n/25 + n/125 + ...
        */
        int ret = 0;
        while (n > 0) {
            n /= 5;
            ret += n;
        }
        return ret;
    }
};

int main(int argc, char const* argv[])
{
    FactorialTrailingZeroes cls;
    cout << cls.trailingZeroes2(3) << " -> 0" << endl;
    cout << cls.trailingZeroes2(5) << " -> 1" << endl;
    return 0;
}
