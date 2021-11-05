#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class RotateFunction{
public:
    int maxRotateFunction(vector<int>& nums) {
        long long v = 0, x = 0, r = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            v += i * nums[i];
            x += nums[i];
        }
        r = max(r, v);
        for (int i = n - 1; i > 0;--i) {
            v = (v + x) - (n * nums[i]);
            r = max(r, v);
        }
        return (int)r;
    }
};

int main(int argc, char const* argv[]) {
    RotateFunction cls;
    cout << cls.maxRotateFunction(vector<int>{4, 3, 2, 6}) << " -> 26" << endl;
    return 0;
}
