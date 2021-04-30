#pragma once

#include <iostream>
#include <vector>
using namespace std;

//80. 删除排序数组中的重复项 II
class CRemoveDuplicates2 {
    /*
    给定一个增序排列数组 nums ，你需要在 原地 删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
    不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
    示例 1：
    输入：nums = [1,1,1,2,2,3]
    输出：5, nums = [1,1,2,2,3]
    解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。 你不需要考虑数组中超出新长度后面的元素。

    示例 2：
    输入：nums = [0,0,1,1,1,1,2,3,3]
    输出：7, nums = [0,0,1,1,2,3,3]
    解释：函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。 你不需要考虑数组中超出新长度后面的元素。
    */
public:
    int removeDuplicates(vector<int>& nums) {
        // 最大重复次数两次
        int maxRepeat = 2;
        if (nums.size() <= maxRepeat)
            return nums.size();
        // 慢指针slow指向索引为1的位置
        int slow = maxRepeat - 1;
        for (int fast = maxRepeat; fast < nums.size(); fast++) {
            // nums[fast] != nums[slow - maxRepeat + 1]
            // 保证在区间[0,slow]中元素最多不会超过2次
            if (nums[fast] != nums[slow - maxRepeat + 1]) {
                // 先扩展区间
                slow++;
                // 再赋值
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};

int main() {
    CRemoveDuplicates2 cls;
    vector<int> vec1{ 1,1,1,2,2,3 };
    int len = cls.removeDuplicates(vec1);
    cout << "[";
    for (int i = 0; i < len;++i) {
        cout << vec1[i] << ",";
    }
    cout << "]" << endl;

    vector<int> vec2{ 0,0,1,1,1,1,2,3,3 };
    len = cls.removeDuplicates(vec2);
    cout << "[";
    for (int i = 0; i < len;++i) {
        cout << vec2[i] << ",";
    }
    cout << "]" << endl;

    vector<int> vec3{ 1,1,2,3,3 };
    len = cls.removeDuplicates(vec3);
    cout << "[";
    for (int i = 0; i < len;++i) {
        cout << vec3[i] << ",";
    }
    cout << "]" << endl;
    return 0;
}