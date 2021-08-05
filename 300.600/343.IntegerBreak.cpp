#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class IntegerBreak {
public:
    int integerBreak(int n) {
        if (n < 4)
            return n - 1;
        /*  拆分出来的数字 不能大于3 因为 4 = 2+2 => 2*2 = 4
                                        5 = 2+3 => 2*3 = 6 > 6
            所以当拆分出来的数字 > 3时，总能将该数组再拆分：使得拆分后的数字的乘积大于原来的数字
            在这种基础上，我们拆分的3越多越好
        */
        int sec = n / 3;
        int rem = n % 3;
        int ret = 0;
        if (rem == 0) {
            return pow(3, sec);
        }
        else if (rem == 1) {
            return pow(3, sec - 1) * 4;
        }
        else {
            return pow(3, sec) * 2;
        }
    }
public:
    int integerBreak1(int n) {
        //动态规划
        vector<int> dp(n + 1, 0);   //存储当n==i时，拆分的最大值
        for (int i = 2; i <= n; ++i) {
            int curMax = 0;
            for (int j = 1;j <= i / 2;++j) {
                curMax = max(curMax, max(j * (i - j), j * dp[i - j])); //由于dp[i - j]至少被拆分为两个数， 所以i-j不拆分情况要单独判断 
            }
            dp[i] = curMax;
        }
        return dp[n];
    }
};

int main(int argc, char const* argv[]) {
    IntegerBreak cls;
    cout << cls.integerBreak1(2) << " -> 1" << endl;
    cout << cls.integerBreak1(10) << " -> 36" << endl;
    return 0;
}
