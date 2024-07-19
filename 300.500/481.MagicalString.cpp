#include <iostream>
#include <string>
using namespace std;

class MagicalString
{
public:
    /* 可通过初始字符串"122"构造出任意长度n的字符串
        他满足两个要求:
            1.新增加的字符串长度，为当前慢指针指向字符的值
            2.新增字符串需要填入的值，与上一个字符串正好相反：上一个填的1，这个就填2
     */
    int magicalString(int n)
    {
        if (n < 4)
        {
            return 1;
        }
        string dp(n, '0');
        dp[0] = '1';
        dp[1] = '2';
        dp[2] = '2';
        // 结果
        int res = 1;
        // 慢指针
        int i = 2;
        // 快指针
        int j = 3;
        while (j < n)
        {
            // 需要增加字符串的长度
            int size = dp[i] - '0';
            // 需要增加的字符
            char c = dp[j - 1] == '1' ? '2' : '1';
            while (size > 0 && j < n)
            {
                dp[j] = c;
                if (c == '1')
                {
                    ++res;
                }
                ++j;
                --size;
            }
            ++i;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    MagicalString cls;
    cout << cls.magicalString(6) << " -> 3" << endl;
    cout << cls.magicalString(1) << " -> 1" << endl;
    return 0;
}
