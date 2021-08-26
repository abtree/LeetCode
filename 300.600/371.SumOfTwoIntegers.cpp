#include <iostream>
using namespace std;

class SumOfTwoIntegers
{
public:
    int getSum(int a, int b) {
        while (b) {
            unsigned int x = (unsigned int)(a & b) << 1;
            a ^= b;
            b = x;
        }
        return a;
    }
};

int main(int argc, char const* argv[]) {
    SumOfTwoIntegers cls;
    cout << cls.getSum(1, 2) << " -> 3" << endl;
    cout << cls.getSum(-2, 3) << " -> 1" << endl;
    cout << cls.getSum(-3, 2) << " -> -1" << endl;
    cout << cls.getSum(-80, -2) << " -> -82" << endl;
    return 0;
}
