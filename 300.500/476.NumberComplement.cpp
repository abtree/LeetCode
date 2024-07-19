#include <iostream>
using namespace std;

class NumberComplement
{
public:
    int findComplement(int num)
    {
        int highbit = 0;
        for (int i = 1; i <= 30; ++i)
        {
            if (num >= (1 << i))
            {
                highbit = i;
            }
            else
            {
                break;
            }
        }
        // 特殊处理highbit == 30 是防止溢出
        int mask = (highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1);
        return num ^ mask;
    }
};

int main(int argc, char const *argv[])
{
    NumberComplement cls;
    cout << cls.findComplement(5) << " -> 2" << endl;
    cout << cls.findComplement(1) << " -> 0" << endl;
    return 0;
}
