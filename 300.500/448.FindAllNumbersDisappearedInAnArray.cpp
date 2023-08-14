#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class FindAllNumbersDisappearedInAnArray
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0;i < n;++i) {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0) {
                nums[x - 1] *= -1;
            }
        }
        vector<int> ret;
        for (int i = 0;i < n;++i) {
            if (nums[i] > 0)
                ret.emplace_back(i + 1);
        }
        return ret;
    }
};

void Print(vector<int>& x) {
    cout << "[";
    for (int i : x) {
        cout << i << ",";
    }
    cout << "]" << endl;
}

int main(int argc, char const* argv[])
{
    FindAllNumbersDisappearedInAnArray cls;
    auto& ret = cls.findDisappearedNumbers(vector<int>{4,3,2,7,8,2,3,1});
    Print(ret);
    auto& ret1 = cls.findDisappearedNumbers(vector<int>{1,1});
    Print(ret1);
    return 0;
}
