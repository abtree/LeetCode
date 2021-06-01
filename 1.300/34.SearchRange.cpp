#include <iostream>
#include <vector>

using namespace std;

//34 在排序数组中查找元素的第一个和最后一个位置
class CSearchRange {
	/*
	给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
	你的算法时间复杂度必须是 O(log n) 级别。
	如果数组中不存在目标值，返回 [-1, -1]。

	示例 1:
	输入: nums = [5,7,7,8,8,10], target = 8
	输出: [3,4]

	示例 2:
	输入: nums = [5,7,7,8,8,10], target = 6
	输出: [-1,-1]
	*/
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		//二分法
		if (nums.empty())
			return vector<int>{-1, -1};
		int start = 0;
		int end = nums.size() - 1;
		int mid = 0;
		while (start <= end) {
			if (start == end) {
				if (nums[start] == target) {
					return vector<int>{ start, start };
				}
				return vector<int>{-1, -1};
			}
			mid = start + (end - start) / 2;
			if (nums[mid] == target) {
				return vector<int>{
					getStart(nums, target, mid, start),
						getEnd(nums, target, mid, end)
				};
			}
			else if (nums[mid] < target) {
				start = mid + 1;
			}
			else if (nums[mid] > target) {
				end = mid - 1;
			}
		}
		return vector<int>{-1, -1};
	}
private:
	int getEnd(vector<int>& nums, int target, int from, int to) {
		if (from == to)
			return from;
		if (nums[to] == target)
			return to;
		//指数增长
		int cell = 1;
		int oldfrom = from;
		while (from < to) {
			from += cell;
			if (from > to) {
				from = to;
			}
			if (nums[from] > target) {
				return getEnd(nums, target, oldfrom, from - 1);
			}
			cell *= 2;
			oldfrom = from;
		}
		return from;
	}
	int getStart(vector<int>& nums, int target, int from, int to) {
		if (from == to)
			return from;
		if (nums[to] == target)
			return to;
		//指数增长
		int cell = -1;
		int oldfrom = from;
		while (from > to)
		{
			from += cell;
			if (from < to) {
				from = to;
			}
			if (nums[from] < target) {
				return getStart(nums, target, oldfrom, from + 1);
			}
			cell *= 2;
			oldfrom = from;
		}
		return from;
	}
};

int main(int argc, char const* argv[])
{
	CSearchRange cls;
	vector<int> ret = cls.searchRange(vector<int>{5, 7, 7, 8, 8, 10}, 8);
	cout << "<" << ret[0] << "," << ret[1] << "> -> <3,4>" << endl;
	ret = cls.searchRange(vector<int>{5, 7, 7, 8, 8, 10}, 6);
	cout << "<" << ret[0] << "," << ret[1] << "> -> <-1,-1>" << endl;
	return 0;
}
