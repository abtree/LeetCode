#include <iostream>
#include <cmath>
using namespace std;

//367. 有效的完全平方数
class ValidPerfectSquare {
    /* 给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
    进阶：不要 使用任何内置的库函数，如  sqrt
    */
public:
    bool isPerfectSquare(int num) {
        int x = (int)sqrt(num);
        return x * x == num;
    }
public:
    bool isPerfectSquare1(int num) {
        //牛顿二分法
        /*
            f(x) = x^2-num
            f'(x) = 2x
            => f(x)/(x-x') = 2x (斜率计算)
            => (x^2-num) = 2x(x-x')
            => x' = 1/2(x+num/x)
        */
        if (num == 1)
            return true;
        long long x = num / 2;
        while (x * x > num) {
            x = (x + num / x) / 2;
        }
        return x * x == num;
    }
};

int main(int argc, char const* argv[]) {
    ValidPerfectSquare cls;
    cout << boolalpha << cls.isPerfectSquare1(16) << " -> true" << endl;
    cout << boolalpha << cls.isPerfectSquare1(14) << " -> false" << endl;
    return 0;
}
