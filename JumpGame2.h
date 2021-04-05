#pragma once

//45. 跳跃游戏 II
class JumpGame2 {
	/*
	给定一个非负整数数组，你最初位于数组的第一个位置。
	数组中的每个元素代表你在该位置可以跳跃的最大长度。
	你的目标是使用最少的跳跃次数到达数组的最后一个位置。

	示例:
	输入: [2,3,1,1,4]
	输出: 2
	解释: 跳到最后一个位置的最小跳跃数是 2。
	     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
	*/
public:
	int jump(vector<int>& nums) {
		//贪心算法
		int end = nums.size() - 1;
		int ret = 0;
		int cur = 0;
		while (cur < end) {
			++ret;
			if (cur + nums[cur] >= end)
				break;
			cur = NewCur(nums, cur + 1, cur + nums[cur]);
		}
		return ret;
	}
private:
	int NewCur(vector<int>& nums, int beg, int end) {
		if (beg >= end)
			return beg;
		int c = beg;
		int m = beg + nums[beg];
		int j = c + 1;
		while (j <= end) {
			if (j + nums[j] >= m) {
				c = j;
				m = j + nums[j];
			}
			++j;
		}
		return c;
	}
public:
	int jump2(vector<int>& nums) {
		//官方贪心算法
		int maxPos = 0, n = nums.size(), end = 0, step = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (maxPos >= i) {
				maxPos = max(maxPos, i + nums[i]);
				if (i == end) {
					end = maxPos;
					++step;
				}
			}
		}
		return step;
	}
public:
	static void Test() {
		JumpGame2 cls;
		cout << cls.jump(vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0}) << " --> 2" << endl;
		cout << cls.jump(vector<int>{2, 3, 1, 1, 4}) << " --> 2" << endl;
	}
};