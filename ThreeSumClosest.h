#pragma once

//16 最接近的三数之和
class CThreeSumClosest {
	/*
	给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
	
	示例：
	输入：nums = [-1,2,1,-4], target = 1
	输出：2
	解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)
	*/
public:
	int threeSumClosest(vector<int>& nums, int target) {
		/*
		按照排序加双指针法
		*/
		if (nums.size() < 3)
			return 0;
		int ret = nums[0] + nums[1] + nums[2];
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i) {
			if(i > 0 && nums[i]==nums[i - 1])
				continue; //相同值不需要重复判断
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k) {
				int cur = nums[i] + nums[j] + nums[k];
				if (std::abs(cur - target) < std::abs(ret - target)) {
					ret = cur;
				}
				if (cur - target > 0) {
					--k;
				}
				else if (cur - target < 0) {
					++j;
				}
				else {
					return target;	//找到相等 直接返回
				}
			}
		}
		return ret;
	}
public:
	static void Test() {
		CThreeSumClosest cls;
		cout << cls.threeSumClosest(vector<int>{-1, 2, 1, -4}, 1) << " -> 2" << endl;
	}
};