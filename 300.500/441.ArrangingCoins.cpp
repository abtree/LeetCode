#include <iostream>
using namespace std;

class ArrangingCoins
{
public:
    int arrangeCoins(int n) {
        int start = 1;
        int end = n;
        while (end - start > 1) {
            long long mid = (end - start) / 2 + start;
            long long x = mid * (mid + 1) / 2;
            if (x == n)
                return mid;
            if (x < n) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        return start;
    }
};

int main(int argc, char const* argv[])
{
    ArrangingCoins cls;
    cout << cls.arrangeCoins(987654321) << " -> 44443" << endl;
    cout << cls.arrangeCoins(5) << " -> 2" << endl;
    cout << cls.arrangeCoins(8) << " -> 3" << endl;
    return 0;
}
