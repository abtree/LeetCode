#include <iostream>
#include <vector>
using namespace std;

class CoinChange2
{
public:
    int change(int amount, const vector<int> &coins)
    {
        // 此题关键在于巧妙的去重
        // 算了3=2+1 不会计算 3=1+2
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins)
        {
            for (int i = coin; i <= amount; ++i)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

int main()
{
    CoinChange2 cls;
    cout << cls.change(5, vector<int>{1, 2, 5}) << " -> 4" << endl;
    cout << cls.change(3, vector<int>{2}) << " -> 0" << endl;
    cout << cls.change(10, vector<int>{10}) << " -> 1" << endl;
    return 0;
}
