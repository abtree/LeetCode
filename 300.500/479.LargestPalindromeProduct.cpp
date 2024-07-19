#include <iostream>
#include <cmath>
using namespace std;

class LargestPalindromeProduct
{
public:
    int largestPalindrome(int n)
    {
        if (n == 1)
        {
            return 9;
        }
        int upper = pow(10, n) - 1;
        // 枚举回文数的左半部分
        for (int left = upper;; --left)
        {
            long p = left;
            // 补齐回文数的右半部分
            for (int x = left; x > 0; x /= 10)
            {
                p = p * 10 + x % 10;
            }
            // 找到符合条件的两个整数
            for (long x = upper; x * x >= p; --x)
            {
                // 能分解为两个正整数的积
                if (p % x == 0)
                {
                    return p % 1337;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    LargestPalindromeProduct cls;
    cout << cls.largestPalindrome(2) << " -> 987" << endl;
    cout << cls.largestPalindrome(1) << " -> 9" << endl;
    return 0;
}
