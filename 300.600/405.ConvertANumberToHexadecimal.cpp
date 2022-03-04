#include <iostream>
#include <string>
using namespace std;

class ConvertANumberToHexadecimal{
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string ret = "";
        for (int i = 7; i >= 0;--i) {
            int val = (num >> (4 * i)) & 0xf;
            if (ret != "" || val > 0) {
                ret.push_back(val < 10 ? ('0' + val) : ('a' + val - 10));
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    ConvertANumberToHexadecimal cls;
    cout << cls.toHex(26) << " -> 1a" << endl;
    cout << cls.toHex(-1) << " -> ffffffff" << endl;
    return 0;
}
