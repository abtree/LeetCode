#include <iostream>
#include <vector>
using namespace std;

class Utf8Validation {
public:
    bool validUtf8(vector<int>& data) {
        int c = 0;
        for (int x : data) {
            if (c > 0) {
                if (count1s(x) != 1)
                    return false;
                --c;
            }
            else {
                c = count1s(x);
                if (c < 0)
                    return false;
                if (c == 1)
                    return false;
                if (c > 1)
                    --c;    //自己也要算一个
            }
        }
        return c == 0;
    }
private:
    int count1s(int x) {
        if (((x >> 7) & 1) == 0)
            return 0;
        if (((x >> 6) & 1) == 0)
            return 1;
        if (((x >> 5) & 1) == 0)
            return 2;
        if (((x >> 4) & 1) == 0)
            return 3;
        if (((x >> 3) & 1) == 0)
            return 4;
        return -1;
    }
};

int main(int argc, char const* argv[])
{
    Utf8Validation cls;
    cout << boolalpha << cls.validUtf8(vector<int>{197, 130, 1}) << " -> true" << endl;
    cout << boolalpha << cls.validUtf8(vector<int>{235, 140, 4}) << " -> false" << endl;
    return 0;
}
