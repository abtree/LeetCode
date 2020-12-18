#pragma once

//47. 全排列 II
class Permutation2 {
	/*
	给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

	输入：nums = [1,1,2]
	输出：
	[[1,1,2],
	[1,2,1],
	[2,1,1]]

	输入：nums = [1,2,3]
	输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
	*/
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> mRet;
		sort(nums.begin(), nums.end());
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

		unordered_set<int> used;
		for (int i = first; i < len; ++i) {
			if (i != first && nums[i] == nums[i - 1]) {
				if (nums[i] == nums[i - 1])
					continue;	//和上一个相等 ，first和i交换与和i-1交换一样
				if (nums[i] == nums[first])
					continue;	//相等 交换了等于没交换
			}

			//处理这种情况(5和7相等，4,5 5,7 == 4,7)
			/*
				[1,2,0,0,-1,1,-1],
				[1,2,0,-1,-1,1,0],  //4,5 5,7
				[1,2,0,-1,-1,1,0],  //4,7
			*/
			if (used.count(nums[i]) > 0)
				continue;
			used.insert(nums[i]);

			swap(nums[i], nums[first]);			//执行交换
			track(ret, nums, first + 1, len);
			swap(nums[i], nums[first]);			//再交换回来
		}
	}
public:
	static void Test() {
		Permutation2 cls;
		vector<vector<int>> ret = cls.permuteUnique(vector<int>{1, 2, 3});
		cout << "[" << endl;
		for (auto& it : ret) {
			cout << "[";
			for (int i : it) {
				cout << i << ",";
			}
			cout << "]" << endl;
		}
		cout << "]" << endl;

		ret.clear();
		ret = cls.permuteUnique(vector<int>{1, 1, 2});
		cout << "[" << endl;
		for (auto& it : ret) {
			cout << "[";
			for (int i : it) {
				cout << i << ",";
			}
			cout << "]" << endl;
		}
		cout << "]" << endl;

		ret.clear();
		ret = cls.permuteUnique(vector<int>{2, 2, 1, 1});
		cout << "[" << endl;
		for (auto& it : ret) {
			cout << "[";
			for (int i : it) {
				cout << i << ",";
			}
			cout << "]" << endl;
		}
		cout << "]" << endl;

		ret.clear();
		ret = cls.permuteUnique(vector<int>{-1, 2, 0, -1, 1, 0, 1});
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