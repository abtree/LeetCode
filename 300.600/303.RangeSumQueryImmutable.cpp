#include <iostream>
#include <vector>
using namespace std;

//303. 区域和检索 - 数组不可变
class NumArray {
    /*  给定一个整数数组  nums，求出数组从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点。实现 NumArray 类：
    NumArray(int[] nums) 使用数组 nums 初始化对象
    int sumRange(int i, int j) 返回数组 nums 从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点（也就是 sum(nums[i], nums[i + 1], ... , nums[j])）
    */
public:
    NumArray(vector<int>& nums) {
        int size = nums.size();
        data.resize(size);
        data[0] = nums[0];
        for (int i = 1;i < size;++i) {
            data[i] = data[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return data[right];
        return data[right] - data[left - 1];
    }
private:
    vector<int> data;
};

int main(int argc, char const* argv[]) {
    NumArray cls(vector<int>{-2, 0, 3, -5, 2, -1});
    cout << cls.sumRange(0,2) << "->1" << endl;
    cout << cls.sumRange(2,5) << "->-1" << endl;
    cout << cls.sumRange(0,5) << "->-3" << endl;
    return 0;
}
