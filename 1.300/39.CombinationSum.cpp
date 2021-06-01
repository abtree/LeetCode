#include <iostream>
#include <vector>

using namespace std;

//39. 组合总和
class CombinationSum {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		mRet.clear();
		for (int i = 0; i < candidates.size(); ++i) {
			Sum(vector<int>{}, candidates[i], candidates[i], i, candidates, target);
		}
		return mRet;
	}
private:
	void Sum(vector<int> set, int add, int sum, int pos, vector<int>& candidates, int target) {
		set.push_back(add);
		if (sum == target) {
			mRet.push_back(set);
			return;
		}
		if (sum > target) {
			return;
		}
		for (int i = pos; i < candidates.size(); ++i) {
			Sum(set, candidates[i], sum + candidates[i], i, candidates, target);
		}
	}
private:
	vector<vector<int>> mRet;
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		//回溯法(不用大量拷贝set)
		mRet.clear();
		vector<int> set;
		for (int i = 0; i < candidates.size(); ++i) {
			Sum2(set, 0, i, candidates, target);
		}
		return mRet;
	}
private:
	void Sum2(vector<int>& set, int sum, int pos, vector<int>& candidates, int target) {
		set.push_back(candidates[pos]);
		sum += candidates[pos];
		if (sum == target) {
			mRet.push_back(set);
			set.pop_back();
			sum -= candidates[pos];
			return;
		}
		if (sum > target) {
			set.pop_back();
			sum -= candidates[pos];
			return;
		}
		for (int i = pos; i < candidates.size(); ++i) {
			Sum2(set, sum, i, candidates, target);
		}
		set.pop_back();
		sum -= candidates[pos];
	}
};

int main(int argc, char const* argv[])
{
	CombinationSum cls;
	vector<vector<int>> ret = cls.combinationSum2(vector<int>{2, 3, 6, 7}, 7);
	cout << "[" << endl;
	for (auto& it : ret) {
		cout << "[";
		for (auto it1 : it) {
			cout << " " << it1;
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;

	ret = cls.combinationSum2(vector<int>{2, 3, 5}, 8);
	cout << "[" << endl;
	for (auto& it : ret) {
		cout << "[";
		for (auto it1 : it) {
			cout << " " << it1;
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;
	return 0;
}
