#include <iostream>
#include <cmath>
using namespace std;

class FibonacciNumber
{
public:
    int fib(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        int a = 0;
        int b = 1;
        int i = 1;
        while (i != n)
        {
            int t = a + b;
            a = b;
            b = t;
            ++i;
        }
        return b;
    }
    int fib1(int n)
    {
        // 公式计算
        double sq5 = sqrt(5);
        double fibn = pow((1 + sq5) / 2, n) - pow((1 - sq5) / 2, n);
        return round(fibn / sq5);
    }
};

int main(int argc, char const *argv[])
{
    FibonacciNumber cls;
    cout << cls.fib1(2) << " -> 1" << endl;
    cout << cls.fib1(3) << " -> 2" << endl;
    cout << cls.fib1(4) << " -> 3" << endl;
    return 0;
}
