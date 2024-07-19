#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxConsecutiveOnes
{
public:
    // 动态规划
    // 由于当前结果只与上一结果相关，可以省略dp数组
    int findMaxConsecutiveOnes(vector<int> nums)
    {
        int last = 0;
        int m = 0;
        for (int c : nums)
        {
            if (c == 0)
            {
                last = 0;
            }
            else
            {
                ++last;
                m = max(m, last);
            }
        }
        return m;
    }
};

int main(int argc, char const *argv[])
{
    MaxConsecutiveOnes cls;
    cout << cls.findMaxConsecutiveOnes(vector<int>{1, 1, 0, 1, 1, 1}) << " -> 3" << endl;
    cout << cls.findMaxConsecutiveOnes(vector<int>{1, 0, 1, 1, 0, 1}) << " -> 2" << endl;
    return 0;
}
