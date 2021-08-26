#include <iostream>
#include <vector>
using namespace std;

//357. 计算各个位数不同的数字个数
class CountNumbersWithUniqueDigits {
    /* 给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10^n 。
    */
public:
    int countNumbersWithUniqueDigits(int n) {
        /* 排列组合
            我们考虑 n = 2 的情况 ： 100 ~ 999
            第一位有9种选择: 1 ~ 9 第一位不能为0
            第二位有9种情况: 不与第一位相同就可以
            第三位有8种情况：不与第一位和第二位相同就可以
            n   sum(n)  ans(n)
            0   1       1
            1   10      10
            2   9*9     ans(1)+sum(2)
            3   9*9*8   ans(2)+sum(3)
            ...
        */
        if (n == 0)
            return 1;
        int ans = 10, dec = 9, sum = 9;
        for (int i = 1; i < n; ++i) {
            sum *= dec--;
            ans += sum;
        }
        return ans;
    }
public:
    int countNumbersWithUniqueDigits1(int n) {
        /* 动态规划 找重复出现的
            dp[i] 表示i位数中重复数字的个数 如i=2  表示 [10,99]中重复数字的个数
            很明显 dp[i] 可分为两部分
                第一部分：dp[i-1]*10 因为dp[i-1]一定有重复数字，所以在末尾加上0~9任意数字，也一定有重复数字
                第二部分: dp[i-1]不重复的数字x加上一个x中包含的数字,如"123",我们在末尾加上1或2或3都会构成重复数字
                dp[i-1]不重复数字有: 10^(i-1)-10^(i-2)-dp[i-1] 个：注意：因为我们只求i位数：如[100,999],这里-10^(i-2)是减去[0,99]
                位数应该为：i-1位
                所以有：(10^(i-1)-10^(i-2)-dp[i-1])*(i-1)
                化简得: (9*10^(i-2)-dp[i-1])*(i-1)
        */
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] * 10 + (9 * pow(10, i - 2) - dp[i - 1]) * (i - 1);
        int sum = 0;
        for (auto x : dp)
            sum += x;
        return pow(10, n) - sum;
    }
};

int main(int argc, char const* argv[]) {
    CountNumbersWithUniqueDigits cls;
    cout << cls.countNumbersWithUniqueDigits1(2) << " -> 91" << endl;
    return 0;
}
