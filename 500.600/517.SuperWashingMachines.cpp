#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class SuperWashingMachines
{
public:
    int findMinMoves(const vector<int> &machines)
    {
        int tot = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (tot % n)
        {
            return -1;
        }
        // 平均值
        int avg = tot / n;
        int sum = 0, ans = 0;
        for (int num : machines)
        {
            // 计算出达到平均值的差值
            num -= avg;
            // 达到平均还需要的步数(由后面的元素提供,可正可负,最终会为0)
            sum += num;
            ans = max(ans, max(abs(sum), num));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    SuperWashingMachines cls;
    cout << cls.findMinMoves(vector<int>{1, 0, 5}) << " -> 3" << endl;
    cout << cls.findMinMoves(vector<int>{0, 3, 0}) << " -> 2" << endl;
    cout << cls.findMinMoves(vector<int>{0, 2, 0}) << " -> -1" << endl;
    return 0;
}
