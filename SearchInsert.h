#pragma once

//35. 搜索插入位置
class CSearchInsert {
	/*
	给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
	你可以假设数组中无重复元素。

	示例 1:
	输入: [1,3,5,6], 5
	输出: 2

	示例 2:
	输入: [1,3,5,6], 2
	输出: 1

	示例 3:
	输入: [1,3,5,6], 7
	输出: 4

	示例 4:
	输入: [1,3,5,6], 0
	输出: 0
	*/
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty())
			return 0;
		int start = 0;
		int end = nums.size() - 1;
		while (start <= end) {
			if (start == end) {
				if (nums[start] >= target)
					return start;
				else
					return start + 1;
			}
			int mid = start + (end - start) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[mid] > target)
				end = (mid == end) ? (mid - 1) : mid;
			else
				start = (mid == start) ? (mid + 1) : mid;
		}
		return start;
	}
	int searchInsert2(vector<int>& nums, int target) {
		//更简洁的二分法
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (target == nums[mid])
			{
				return mid;
			}
			else if (target > nums[mid])
			{
				left = mid + 1;
			}
			else if (target < nums[mid])
			{
				right = mid - 1;
			}
		}
		return right + 1;
	}
public:
	static void Test() {
		CSearchInsert cls;
		cout << cls.searchInsert2(vector<int>{1, 3, 5, 6}, 5) << " -> 2" << endl;
		cout << cls.searchInsert2(vector<int>{1, 3, 5, 6}, 2) << " -> 1" << endl;
		cout << cls.searchInsert2(vector<int>{1, 3, 5, 6}, 7) << " -> 4" << endl;
		cout << cls.searchInsert2(vector<int>{1, 3, 5, 6}, 0) << " -> 0" << endl;
	}
};