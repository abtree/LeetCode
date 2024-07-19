#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*  由于本题要求每一位都是1
    k进制可以表示为 k^0 + k^1 + k^1 + ... + k^m = (1-k^(m+1))/(1-k) = n
    由题目可知：n和k都相对较大，但m相对较小，所以选择遍历m (m越大，k值越小)
    m = log_k(kn-n+1) - 1 < log_k(kn) = 1+log_k(n); k >= 2, m >= 1
    => 1 <= m <= log_2(n)
    (1-k^(m+1))/(1-k) = n
    => k^(m+1) = nk - n + 1 < nk
    => k < sqrt_m(n)
*/
class SmallestGoodBase
{
public:
    // 二分法
    string smallestGoodBase(string n)
    {
        long long num = atoll(n.c_str());
        // 遍历m值
        for (int m = log2(num); m >= 1; m--)
        {
            // k的最小值
            long long l = 2;
            // k的最大值
            long long r = powl(num, 1.0 / m) + 1;
            long long k, sum;
            while (l < r)
            {
                // 二分获取k值(由于k比较大，二分法效率更高)
                k = (l + r) / 2;
                // sum为n
                sum = 1;
                for (int j = 0; j < m; ++j)
                {
                    sum = sum * k + 1;
                }
                if (sum == num)
                {
                    return to_string(k);
                }
                else if (sum < num)
                {
                    l = k + 1;
                }
                else
                {
                    r = k;
                }
            }
        }
        return "";
    }

    // 简化版， k只需要取它的最大值
    // 为什么k只需要取最大值，官方参考题解(结论2)
    string smallestGoodBase1(string n)
    {
        long long nVal = stoll(n);
        int mMax = floor(log(nVal) / log(2));
        for (int m = mMax; m > 1; m--)
        {
            int k = pow(nVal, 1.0 / m);
            long long mul = 1, sum = 1;
            for (int i = 0; i < m; i++)
            {
                mul *= k;
                sum += mul;
            }
            if (sum == nVal)
            {
                return to_string(k);
            }
        }
        return to_string(nVal - 1);
    }
};

int main(int argc, char const *argv[])
{
    SmallestGoodBase cls;
    cout << cls.smallestGoodBase("727004545306745403").c_str() << " -> 727004545306745402" << endl;
    cout << cls.smallestGoodBase1("13").c_str() << " -> 3" << endl;
    cout << cls.smallestGoodBase1("4681").c_str() << " -> 8" << endl;
    cout << cls.smallestGoodBase1("1000000000000000000").c_str() << " -> 999999999999999999" << endl;
    return 0;
}
