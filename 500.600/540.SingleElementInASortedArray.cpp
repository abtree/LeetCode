#include <iostream>
#include <vector>
using namespace std;

class SingleElementInASortedArray
{
public:
    int singleNonDuplicate(const vector<int> &nums)
    {
        int high = nums.size() - 2;
        int low = 0;
        while (low < high)
        {
            int mid = (high - low) / 2 + low;
            mid -= mid & 1; // 偶数化处理
            if (nums[mid] != nums[mid + 1])
            {
                high = mid;
            }
            else
            {
                low = mid + 2;
            }
        }
        return nums[low];
    }
};

int main()
{
    SingleElementInASortedArray cls;
    cout << cls.singleNonDuplicate(vector<int>{1, 1, 2, 3, 3, 4, 4, 8, 8}) << " -> 2" << endl;
    cout << cls.singleNonDuplicate(vector<int>{3, 3, 7, 7, 10, 11, 11}) << " -> 10" << endl;
    return 0;
}
