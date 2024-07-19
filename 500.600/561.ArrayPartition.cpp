#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ArrayPartition
{
public:
    int arrayPairSum(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = 0; i < nums.size(); i += 2)
        {
            ret += nums[i];
        }
        return ret;
    }
};

int main()
{
    ArrayPartition cls;
    cout << cls.arrayPairSum(vector<int>{1, 4, 3, 2}) << " -> 4" << endl;
    cout << cls.arrayPairSum(vector<int>{6, 2, 6, 5, 1, 2}) << " -> 9" << endl;
    return 0;
}
