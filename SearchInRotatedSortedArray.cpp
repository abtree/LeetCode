#pragma once

#include <iostream>
#include <vector>

using namespace std;

//33 搜索旋转排序数组
class CSearchRotatedSortedArray {
	/*
	给你一个升序排列的整数数组 nums ，和一个整数 target 。
	假设按照升序排序的数组在预先未知的某个点上进行了旋转。（例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] ）。
	请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
	 
	 示例 1：
	 输入：nums = [4,5,6,7,0,1,2], target = 0
	 输出：4

	 示例 2：
	 输入：nums = [4,5,6,7,0,1,2], target = 3
	 输出：-1

	 示例 3：
	 输入：nums = [1], target = 0
	 输出：-1

	  提示：
	  1 <= nums.length <= 5000
	  -10^4 <= nums[i] <= 10^4
	  nums 中的每个值都 独一无二
	  nums 肯定会在某个点上旋转
	  -10^4 <= target <= 10^4
	*/
public:
	int search(vector<int>& nums, int target) {
		/*
		由于只有一个拐点 采用2分法是可以处理的
		思路：
			1，二分之后我们只需要判断目标在不在有序部分的区间内
			2，如果在，就变成有序数组的二分查找了
			3，如果不在，对剩余的部分继续采用步骤1
		*/
		if (nums.empty())
			return -1;
		int end = nums.size()-1;
		int start = 0;
		int mid = 0;
		while (start <= end) {
			if (start == end)
				return nums[start] == target ? start : -1;
			mid = start + (end - start) / 2;
			//判断那边有序
			if (nums[start] <= nums[mid]) {
				//左半部分有序
				if (target >= nums[start] && target <= nums[mid]) {
					//目标可能在左半部分
					return search(nums, target, start, mid);
				}
				else {
					//目标可能在右半部分
					start = mid+1;
				}
			}
			else {
				//右半部分有序
				if (target >= nums[mid] && target <= nums[end]) {
					//目标可能在右半部分
					return search(nums, target, mid, end);
				}
				else {
					//目标可能在左半部分
					end = mid-1;
				}
			}
		}
		return -1;
	}
private:
	//对有序数组的二分查找
	int search(vector<int>& nums, int target, int start, int end) {
		if (start > end)
			return -1;
		if (start == end)
			return nums[start] == target ? start : -1;
		int mid = start + (end - start) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target)
			return search(nums, target, start, mid - 1);
		else 
			return search(nums, target, mid + 1, end);
	}
};

int main() {
	CSearchRotatedSortedArray cls;
	cout << cls.search(vector<int>{282, 283, 290, 295, 296, 297, 298, 1, 7, 8, 9, 11, 12, 15, 17, 21, 27, 28, 38, 43, 45, 50, 51, 52, 55, 59, 61, 66, 75, 82, 84, 85, 86, 87, 96, 101, 103, 105, 114, 117, 119, 120, 122, 123, 132, 138, 140, 145, 151, 152, 156, 157, 159, 163, 164, 165, 170, 172, 184, 187, 188, 189, 190, 193, 201, 204, 205, 206, 208, 215, 216, 217, 225, 232, 234, 241, 244, 248, 249, 252, 261, 262, 264, 265, 268, 271, 272, 279, 280}, 102) << " -> -1" << endl;
	cout << cls.search(vector<int>{3,1}, 1) << " -> 1" << endl;
	cout << cls.search(vector<int>{4, 5, 6, 7, 0, 1, 2}, 0) << " -> 4" << endl;
	cout << cls.search(vector<int>{4, 5, 6, 7, 0, 1, 2}, 3) << " -> -1" << endl;
	cout << cls.search(vector<int>{1}, 0) << " -> -1" << endl;

	return 0;
}