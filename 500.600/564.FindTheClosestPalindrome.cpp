#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

class FindTheClosestPalindrome
{
public:
    string nearestPalindromic(string n)
    {
        /*5种情况*/
        long long num = atoll(n.c_str());

        unordered_map<long long, string> dp;
        // 1.用前半部分替换后半部分
        string n1 = repeated(n);
        addToMap(dp, n1, num);
        // 2. 考虑将中间位加1
        string n2 = add(n1);
        addToMap(dp, n2, num);
        // 3. 考虑将中间位减1
        string n3 = dec(n1);
        addToMap(dp, n3, num);
        // 4. 9..9
        string n4 = nines(n.size() - 1);
        addToMap(dp, n4, num);
        // 5. 10..01
        string n5 = tens(n.size() + 1);
        addToMap(dp, n5, num);
        // 找到最接近的值
        long long m = dp.begin()->first;
        for (auto &kv : dp)
        {
            m = min(m, kv.first);
        }
        return dp[m];
    }

private:
    void addToMap(unordered_map<long long, string> &dp, string &n, long long num)
    {
        long long num1 = atoll(n.c_str());
        long long dec = abs(num - num1);
        if (dec != 0)
        {
            auto it = dp.find(dec);
            if (it == dp.end())
            {
                dp[dec] = n;
            }
            else
            {
                long long num2 = atoll(it->second.c_str());
                if (num2 > num1)
                {
                    dp[dec] = n;
                }
            }
        }
    }
    string repeated(string n)
    {
        int q = n.size() - 1;
        int p = 0;
        while (p < q)
        {
            if (n[p] != n[q])
            {
                n[q] = n[p];
            }
            --q;
            ++p;
        }
        return n;
    }
    string add(string n)
    {
        int size = n.size();
        int p = size >> 1;
        int q = p - 1;
        if (size & 1)
        {
            q = p;
        }
        while (q >= 0 && p < size)
        {
            if (n[p] != '9')
            {
                n[p] += 1;
                if (p != q)
                {
                    n[q] += 1;
                }
                return n;
            }
            n[p] = '0';
            if (p != q)
            {
                n[q] = '0';
            }
            --q;
            ++p;
        }
        return n;
    }
    string dec(string n)
    {
        int size = n.size();
        int p = size >> 1;
        int q = p - 1;
        if (size & 1)
        {
            q = p;
        }
        while (q >= 0 && p < size)
        {
            if (n[p] != '0')
            {
                n[p] -= 1;
                if (p != q)
                {
                    n[q] -= 1;
                }
                return n;
            }
            n[p] = '9';
            if (p != q)
            {
                n[q] = '9';
            }
            --q;
            ++p;
        }

        return n;
    }
    string nines(int size)
    {
        if (size == 0)
        {
            size = 1;
        }
        return string(size, '9');
    }
    string tens(int size)
    {
        int add = size - 2;
        if (add == 0)
        {
            return "11";
        }
        return "1" + string(add, '0') + "1";
    }
};

int main()
{
    FindTheClosestPalindrome cls;
    cout << cls.nearestPalindromic("9009") << " -> 8998" << endl;
    cout << cls.nearestPalindromic("358764513820540928") << " -> 358764513315467853" << endl;
    cout << cls.nearestPalindromic("2147483647") << " -> 2147447412" << endl;
    cout << cls.nearestPalindromic("11") << " -> 9" << endl;
    cout << cls.nearestPalindromic("10") << " -> 9" << endl;
    cout << cls.nearestPalindromic("123") << " -> 121" << endl;
    cout << cls.nearestPalindromic("1") << " -> 0" << endl;
    return 0;
}
