#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class ContiguousArray
{
public:
    int findMaxLength(vector<int> nums)
    {
        int sum = 0;
        unordered_map<int, int> dp;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i])
            {
                sum += 1;
            }
            else
            {
                sum -= 1;
            }

            if (sum == 0)
            {
                ans = i + 1;
            }
            else
            {
                auto it = dp.find(sum);
                if (it != dp.end())
                {
                    ans = max(ans, i - it->second);
                }
                else
                {
                    dp[sum] = i;
                }
            }
        }
        return ans;
    }
};

int main()
{
    ContiguousArray cls;
    cout << cls.findMaxLength(vector<int>{0, 1, 1}) << " -> 2" << endl;
    cout << cls.findMaxLength(vector<int>{0, 1, 0}) << " -> 2" << endl;
    cout << cls.findMaxLength(vector<int>{0, 1}) << " -> 2" << endl;
    return 0;
}
