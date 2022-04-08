#include <iostream>
#include <vector>

using namespace std;

class ArithmeticSlices{
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        /* 穷举法
            从一个点开始 枚举能达到的最大等差数列长度 
        */
        int n = nums.size();
        if (n < 3)
            return 0;
        int ret = 0;
        for (int i = 0; i < n - 2;i++) {
            int k = nums[i + 1] - nums[i];
            for (int j = i + 2; j < n;++j) {
                if (nums[j] - k == nums[j - 1])
                    ++ret;
                else
                    break;
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    ArithmeticSlices cls;
    cout << cls.numberOfArithmeticSlices(vector<int>{1,2,3,4}) << " -> 3" << endl;
    cout << cls.numberOfArithmeticSlices(vector<int>{1}) << " -> 0" << endl;
    return 0;
}
