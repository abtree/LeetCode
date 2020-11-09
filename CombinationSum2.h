#pragma once

//40 组合总和 II
class CombinationSum2 {
	/*
	给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
	candidates 中的每个数字在每个组合中只能使用一次。

	说明：
	所有数字（包括目标数）都是正整数。
	解集不能包含重复的组合。 

	示例 1:
	输入: candidates = [10,1,2,7,6,1,5], target = 8,
	所求解集为:
	[
		[1, 7],
		[1, 2, 5],
		[2, 6],
		[1, 1, 6]
	]

	示例 2:
	输入: candidates = [2,5,2,1,2], target = 5,
	所求解集为:
	[
	 	[1,2,2],
		[5]
	]
	*/
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		unordered_map<int, int> cans;
		for (auto it : candidates) {
			cans[it] += 1;
		}
		mRet.clear();
		vector<int> set;
		
		for (int i = 0; i < cans.size(); ++i) {
			Sum(set, 0, i, cans, target);
		}
		return mRet;
	}
private:
	void Sum(vector<int>& set, int sum, int pos, unordered_map<int, int>& cans, int target) {
		auto it = cans.begin();
		std::advance(it, pos);
		int val = it->first;
		it->second -= 1;
		set.push_back(val);
		cout << "Val: " << val << " Count: " << it->second << endl;
		sum += val;
		if (sum == target) {
			mRet.push_back(set);
			set.pop_back();
			sum -= val;
			it->second += 1;
			return;
		}
		if (sum > target) {
			set.pop_back();
			sum -= val;
			it->second += 1;
			return;
		}
		if (it->second > 0)
			Sum(set, sum, pos, cans, target);
		for (int i = pos + 1; i < cans.size(); ++i) {
			Sum(set, sum, i, cans, target);
		}
		set.pop_back();
		sum -= val;
		it->second += 1;
	}
private:
	vector<vector<int>> mRet;
public:
	static void Test() {
		CombinationSum2 cls;
		vector<vector<int>> ret = cls.combinationSum(vector<int>{10, 1, 2, 7, 6, 1, 5}, 8);
		cout << "[" << endl;
		for (auto &it : ret) {
			cout << "[";
			for (auto it1 : it) {
				cout << " " << it1;
			}
			cout << "]" << endl;
		}
		cout << "]" << endl;

		ret = cls.combinationSum(vector<int>{2, 5, 2, 1, 2}, 5);
		cout << "[" << endl;
		for (auto &it : ret) {
			cout << "[";
			for (auto it1 : it) {
				cout << " " << it1;
			}
			cout << "]" << endl;
		}
		cout << "]" << endl;
	}
};