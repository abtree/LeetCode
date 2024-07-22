#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class ArrayNesting
{
public:
    int arrayNesting(vector<int> nums)
    {
        int n = nums.size();
        vector<bool> visited(n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            while (!visited[nums[i]])
            {
                visited[nums[i]] = true;
                i = nums[i];
                ++cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    ArrayNesting cls;
    cout << cls.arrayNesting(vector<int>{5, 4, 0, 3, 1, 6, 2}) << " -> 4" << endl;
    cout << cls.arrayNesting(vector<int>{0, 1, 2}) << " -> 1" << endl;
    return 0;
}
