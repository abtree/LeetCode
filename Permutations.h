#pragma once

//46. ȫ����
class Permutations {
	/*
	����һ�� û���ظ� ���ֵ����У����������п��ܵ�ȫ���С�
	����: [1,2,3]
	���:
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
		//���ݷ�
		if (first >= len) {
			ret.emplace_back(nums);
			return;
		}
		for (int i = first; i < len; ++i) {
			swap(nums[i], nums[first]);			//ִ�н���
			track(ret, nums, first + 1, len);
			swap(nums[i], nums[first]);			//�ٽ�������
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