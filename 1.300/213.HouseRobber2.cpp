#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HouseRobber2 {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        if (size == 1)
            return nums[0];
        int dp1 = nums[0];
        int dp2 = max(dp1, nums[1]);
        if (size == 2)
            return dp2;
        if (size == 3)
            return max(dp2, nums[2]);
        for (int i = 2; i < size - 1; ++i) {    //第一次 (1..n-1)不偷盗最后一间
            int tmp = dp1;
            dp1 = dp2;
            dp2 = max(tmp + nums[i], dp2);
        }
        int max1 = dp2;
        dp1 = nums[1];
        dp2 = max(dp1, nums[2]);
        for (int i = 3; i < size; ++i) {    //第二次次 (2..n)不偷盗第一间
            int tmp = dp1;
            dp1 = dp2;
            dp2 = max(tmp + nums[i], dp2);
        }
        return max(max1, dp2);
    }
};

int main(int argc, char const* argv[]) {
    HouseRobber2 cls;
    cout << cls.rob(vector<int>{2, 2, 4, 3, 2, 5}) << " -> 10" << endl;
    cout << cls.rob(vector<int>{2, 3, 2}) << " -> 3" << endl;
    cout << cls.rob(vector<int>{1, 2, 3, 1}) << " -> 4" << endl;
    cout << cls.rob(vector<int>{9, 1, 1, 9}) << " -> 10" << endl;
    return 0;
}
