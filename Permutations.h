#pragma once

//46. 全排列
class Permutations {
	/*
	给定一个 没有重复 数字的序列，返回其所有可能的全排列。
	输入: [1,2,3]
	输出:
	[
		[1,2,3],
		[1,3,2],
		[2,1,3],
		[2,3,1],
		[3,1,2],
		[3,2,1]
	]
	*/
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> mRet;
		track(mRet, nums, 0, nums.size());
		return mRet;
	}
private:
	void track(vector<vector<int>>& ret, vector<int>& nums, int first, int len) {
		//回溯法
		if (first >= len) {
			ret.emplace_back(nums);
			return;
		}
		for (int i = first; i < len; ++i) {
			swap(nums[i], nums[first]);			//执行交换
			track(ret, nums, first + 1, len);
			swap(nums[i], nums[first]);			//再交换回来
		}
	}
public:
	static void Test() {
		Permutations cls;
		vector<vector<int>> ret = cls.permute(vector<int>{1, 2, 3});
		cout << "[" << endl;
		for (auto& it : ret) {
			cout << "[";
			for (int i : it) {
				cout << i << ",";
			}
			cout << "]" << endl;
		}
		cout << "]" << endl;
	}
};