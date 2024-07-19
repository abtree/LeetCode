#include <iostream>
#include <cmath>
using namespace std;

class PerfectNumber
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
        {
            return false;
        }
        int x = int(sqrt(num));
        int sum = 1;
        while (x > 1)
        {
            if (num % x == 0)
            {
                sum += x;
                sum += num / x;
            }
            --x;
        }
        return sum == num;
    }
};

int main(int argc, char const *argv[])
{
    PerfectNumber cls;
    cout << boolalpha << cls.checkPerfectNumber(1) << " -> true" << endl;
    cout << boolalpha << cls.checkPerfectNumber(28) << " -> true" << endl;
    cout << boolalpha << cls.checkPerfectNumber(7) << " -> false" << endl;
    return 0;
}
