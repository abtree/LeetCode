#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class KDiffPairsInAnArray
{
public:
    int findPairs(vector<int> nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[i] - nums[j] < k)
                {
                    continue;
                }
                if (nums[i] - nums[j] == k)
                {
                    ++ans;
                }
                break;
            }
        }
        return ans;
    }

public:
    // hash标记法
    int findPairs1(vector<int> nums, int k)
    {
        // 用 unordered_set 是为了去重
        unordered_set<int> visited;
        // ans里面去重，都是以减数作为标记
        unordered_set<int> ans;
        for (int num : nums)
        {
            // x - num = k 的情况
            if (visited.contains(num + k))
            {
                ans.insert(num);
            }
            // num - x = k 的情况
            if (visited.contains(num - k))
            {
                ans.insert(num - k);
            }
            visited.insert(num);
        }
        return ans.size();
    }
};

int main()
{
    KDiffPairsInAnArray cls;
    cout << cls.findPairs1(vector<int>{3, 1, 4, 1, 5}, 2) << " -> 2" << endl;
    cout << cls.findPairs1(vector<int>{1, 2, 3, 4, 5}, 1) << " -> 4" << endl;
    cout << cls.findPairs1(vector<int>{1, 3, 1, 5, 4}, 0) << " -> 1" << endl;
    return 0;
}
