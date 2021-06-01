#include <iostream>
#include <vector>
using namespace std;

//204. 计数质数
class CountPrimes
{
    /* 统计所有小于非负整数 n 的质数的数量。
    */
public:
    int countPrimes(int n) {
        //埃氏筛查发
        vector<int> isprimes(n, 1); //全标记为质数
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isprimes[i]) {
                ++ans;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isprimes[j] = 0;    //i的倍数都不是质数
                    }
                }
            }
        }
        return ans;
    }
public:
    int countPrimes2(int n) {
        //线性筛查发
        vector<int> primes;
        vector<int> isprimes(n, 1); //全部标记为质数
        for (int i = 2;i < n;++i) {
            if (isprimes[i]) {
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                isprimes[i * primes[j]] = 0;    //将以标记的质数的i倍都标记为合数
                if (i % primes[j] == 0)
                    break;
            }
        }
        return primes.size();
    }
};

int main(int argc, char const* argv[])
{
    CountPrimes cls;
    cout << cls.countPrimes2(10) << " -> 4" << endl;
    cout << cls.countPrimes2(0) << " -> 0" << endl;
    cout << cls.countPrimes2(1) << " -> 0" << endl;
    return 0;
}
