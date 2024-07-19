#include <iostream>
#include <vector>
using namespace std;

class TotalHammingDistance
{
public:
    /* 首先需要逐位统计，每一位上有多少个1和多少个0
        则可以得出，每一个1和0的组合都会产生一个汉明距离
        即总共可以产生c * (size - c)个距离：c为1的个数，size为nums长度
    */
    int totalHammingDistance(vector<int> nums)
    {
        int size = nums.size();
        int sum = 0;
        for (int i = 0; i < 30; ++i)
        {
            int c = 0;
            for (int val : nums)
            {
                c += (val >> i) & 1;
            }
            sum += c * (size - c);
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    TotalHammingDistance cls;
    cout << cls.totalHammingDistance(vector<int>{4, 14, 2}) << " -> 6" << endl;
    cout << cls.totalHammingDistance(vector<int>{4, 14, 4}) << " -> 4" << endl;
    return 0;
}
