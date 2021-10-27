#include <iostream>
#include <vector>
using namespace std;

class EliminationGame {
public:
    int lastRemaining(int n) {
        /* 动态规划
            令 dp[i] 为 n = i 时 最后留下的值
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = dp[2];  //当n为基数时 dp[n] = dp[n-1]
            dp[4] = 2; --> dp[4] = 2 + 4 - 2*dp[2]
            dp[6] = 4; --> dp[6] = 2 + 6 - 2*dp[3]
            dp[8] = 6; --> dp[8] = 2 + 8 - 2*dp[4]
            dp[10] = 8; --> dp[10] = 2 + 10 - 2*dp[5]
            dp[12] = 6; --> dp[12] = 2 + 12 - 2*dp[6]
            dp[i] = 2 + i - 2*dp[i/2];
        */
        vector<int> vec(n + 1, 0);
        vec[1] = 1;
        for (int i = 2; i <= n;++i) {
            if (i & 1)
                vec[i] = vec[i - 1];
            else {
                vec[i] = 2 + i - 2 * vec[i / 2];
            }
        }
        return vec[n];
    }
public:
    int lastRemaining1(int n) {
        //递归法
        return dfs(n);
    }

    int dfs(int i) {
        if (i == 1)
            return 1;
        if (i == 2)
            return 2;
        if (i & 1)
            return dfs(i - 1);
        return 2 + i - 2 * dfs(i / 2);
    }
public:
    int lastRemaining2(int n) {
        /*位运算
        类似于用一根指针指着最左边的数，只有当从左到右，或者从右到左且剩余数为奇数时，才会删除最左边的数，将指针移动当前等差数列的公差即可
        举例 : 1 2 3 4 5 6 7 8 9 start = 1, step = 1, islr = true;
        第一次: start = 2, step = 1; islr = true;   删除: 1 3 5 7 9 --> start + step
        第二次: start = 2; step = 2; islr = false;  删除: 8 4 --> start 不动
        第三次: start = 6; step = 4; islr = true;  删除：2 --> start + step
        */
        int start = 1;
        int step = 1;
        bool islr = true;
        while (n > 1) {
            if (islr || (n & 1) == 1) {
                start += step;
            }
            n >>= 1;
            step <<= 1;
            islr = !islr;
        }
        return start;
    }
};

int main(int argc, char const* argv[]) {
    EliminationGame cls;
    cout << cls.lastRemaining2(9) << " -> 6" << endl;
    cout << cls.lastRemaining2(5) << " -> 2" << endl;
    cout << cls.lastRemaining2(13) << " -> 6" << endl;
    return 0;
}
