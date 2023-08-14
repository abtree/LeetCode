#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IntegerReplacement{
public:
    int integerReplacement(int n) {
        //会超时 改用递归就不会超时了
        if (n == 1)
            return 0;
        if (n == 2)
            return 1;
        int s = n;
        if (n & 1)
            s += 1;
        vector<int> dp(s+1, 0);
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 4; i <= s; i += 2) {
            dp[i] = dp[i / 2] + 1;
            dp[i - 1] = min(dp[i - 2], dp[i]) + 1;
        }
        return dp[n];
    }
public:
    int integerReplacement2(int n) {
        if (n == 1)
            return 0;
        if(n == INT_MAX)
            return integerReplacement(n-1);
        if (n & 1)
            return min(integerReplacement(n - 1), integerReplacement(n + 1)) + 1;
        else
            return integerReplacement(n >> 1)+1;
    }
};

int main(int argc, char const* argv[]) {
    IntegerReplacement cls;
    cout << cls.integerReplacement2(200000000) << " -> 32" << endl;
    cout << cls.integerReplacement2(8) << " -> 3" << endl;
    cout << cls.integerReplacement2(7) << " -> 4" << endl;
    cout << cls.integerReplacement2(4) << " -> 2" << endl;
    return 0;
}
