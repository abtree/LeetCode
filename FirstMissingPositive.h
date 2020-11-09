#pragma once

//41. 缺失的第一个正数
class FirstMissingPositive {
public:
	int firstMissingPositive(vector<int>& nums) {
		int size = nums.size() + 1;
		for (auto &it : nums) {
			if (it <= 0)
				it = size;
		}
		for (auto it1 : nums) {
			if(abs(it1) >= size)
				continue;
			if (nums[abs(it1) - 1] > 0)
				nums[abs(it1) - 1] *= -1;
		}
		for (int i = 0; i < size - 1; ++i) {
			if (nums[i] > 0)
				return i + 1;
		}
		return size;
	}

	int firstMissingPositive2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int ans = 1;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == ans) ++ans;
		}
		return ans;
	}
public:
	static void Test() {
		FirstMissingPositive cls;
		cout << cls.firstMissingPositive2(vector<int>{1}) << " -> 2" << endl;
		cout << cls.firstMissingPositive2(vector<int>{1, 2, 0}) << " -> 3" << endl;
		cout << cls.firstMissingPositive2(vector<int>{3, 4, -1, 1}) << " -> 2" << endl;
		cout << cls.firstMissingPositive2(vector<int>{7, 8, 9, 11, 12}) << " -> 1" << endl;
	}
};
