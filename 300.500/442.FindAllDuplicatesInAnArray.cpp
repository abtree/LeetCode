#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

class FindAllDuplicatesInAnArray
{
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //正负号标记法
        vector<int> ret;
        for (int i = 0;i < nums.size();++i) {
            int x = abs(nums[i]);
            if (nums[x - 1] < 0) {
                //说明已经出现过
                ret.emplace_back(x);
            }
            else {
                //添加负号 标记为已经使用
                nums[x - 1] *= -1;
            }
        }
        return ret;
    }
public:
    vector<int> findDuplicates1(vector<int>& nums) {
        //位置交换法
        int n = nums.size();
        for (int i = 1;i < n;++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ret;
        for (int i = 1;i < n;++i) {
            if (nums[i] - 1 != i) {
                ret.emplace_back(nums[i]);
            }
        }
        return ret;
    }
};

void Print(vector<int>& ret) {
    cout << "[";
    for (int x : ret) {
        cout << x << ", ";
    }
    cout << "]" << endl;
}

int main(int argc, char const* argv[])
{
    FindAllDuplicatesInAnArray cls;
    auto& ret = cls.findDuplicates1(vector<int>{4, 3, 2, 7, 8, 2, 3, 1});
    Print(ret);
    auto& ret1 = cls.findDuplicates1(vector<int>{1, 1, 2});
    Print(ret1);
    auto& ret2 = cls.findDuplicates1(vector<int>{1});
    Print(ret2);
    return 0;
}
