#include <iostream>
#include <array>
using namespace std;

// 263. 丑数
class UglyNumber {
    /* 给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
    丑数 就是只包含质因数 2、3 和/或 5 的正整数。
    */
public:
    bool isUgly(int n) {
        if (n < 1)
            return false;
        array<int, 3> facts{ 2,3,5 };
        for (int i : facts) {
            while (n % i == 0) {
                n /= i;
            }
        }
        return n == 1;
    }
};

int main(int argc, char const* argv[])
{
    UglyNumber cls;
    cout << boolalpha << cls.isUgly(6) << "->true" << endl;
    cout << boolalpha << cls.isUgly(8) << "->true" << endl;
    cout << boolalpha << cls.isUgly(14) << "->false" << endl;
    cout << boolalpha << cls.isUgly(1) << "->true" << endl;
    return 0;
}