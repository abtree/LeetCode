#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class base7
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
        {
            return "0";
        }
        bool neg = num < 0;
        num = abs(num);
        string ret = "";
        while (num > 0)
        {
            ret.push_back(num % 7 + '0');
            num /= 7;
        }
        if (neg)
        {
            ret.push_back('-');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    base7 cls;
    cout << cls.convertToBase7(100) << " -> 202" << endl;
    cout << cls.convertToBase7(-7) << " -> -10" << endl;
    return 0;
}
