#include <iostream>
#include <bitset>

using namespace std;

class NumberOf1bits
{
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bc(n);
        return bc.count();
    }
public:
    int hammingWeight2(uint32_t n) {
        int c = 0;
        for (int i = 0; i < 32 && n > 0;++i) {
            if (n & 1)
                ++c;
            n >>= 1;
        }
        return c;
    }
};

int main(int argc, char const* argv[])
{
    NumberOf1bits cls;
    cout << cls.hammingWeight2(11) << " -> 3" << endl;
    cout << cls.hammingWeight2(128) << " -> 1" << endl;
    cout << cls.hammingWeight2(4294967293) << " -> 31" << endl;
    return 0;
}
