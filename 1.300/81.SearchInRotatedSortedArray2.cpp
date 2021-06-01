#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//81. 搜索旋转排序数组 II
class SearchInRotatedSortedArray2 {
    /*
    假设按照升序排序的数组在预先未知的某个点上进行了旋转。
    ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
    编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

    示例 1:
    输入: nums = [2,5,6,0,0,1,2], target = 0
    输出: true

    示例 2:
    输入: nums = [2,5,6,0,0,1,2], target = 3
    输出: false

    进阶:
    这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
    这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
    */
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;
        return lookfor(nums, target, 0, nums.size() - 1);
    }
private:
    bool lookfor(vector<int>& nums, int target, int begin, int end) {
        //暴力二分（性能还不错,但还可以优化）
        if (begin > end){
            return false;
        }
        if (begin == end)
            return (nums[begin] == target);
        int mid = (end - begin) / 2 + begin;
        if (nums[mid] == target)
            return true;
        return lookfor(nums, target, begin, mid-1)  || lookfor(nums, target, mid+1, end);
    }
public:
    bool search2(vector<int>& nums, int target) {
        //二分优化版 一次删除一半数据(二分法的精髓就是一次努力删除一半的数据)
        if (nums.empty())
            return false;
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            
            if (nums[mid] > nums[left]) { // mid左边的数组[left, mid)是有序的
                // target 就在[left, mid)中
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < nums[left]) {// mid 右边(mid, right)是有序的
                // target 就在(mid, right)中
                if (target > nums[mid] && target <= nums[right - 1])
                    left = mid + 1;
                else
                    right = mid;
            } else if (nums[mid] == nums[left]) {
                    left++;
            }
        }

        return false;
    }
public:
    bool search3(vector<int>& nums, int target) {
        //调用系统函数
        return find(nums.begin(), nums.end(), target) != nums.end();
    }
};

int main() {
    SearchInRotatedSortedArray2 cls;
    cout << boolalpha << cls.search2(vector<int>{ 1,0,1,1,1 }, 0) << " -> true" << endl;
    cout << boolalpha << cls.search2(vector<int>{ 2, 5, 6, 0, 0, 1, 2 }, 0) << " -> true" << endl;
    cout << boolalpha << cls.search2(vector<int>{ 2, 5, 6, 0, 0, 1, 2 }, 3) << " -> false" << endl;
    return 0;
}
