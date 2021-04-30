#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//18 四数之和
class CFourSum {
	/*
	给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

	注意：
	答案中不可以包含重复的四元组。

	示例：
	给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
	满足要求的四元组集合为：
	[
		[-1,  0, 0, 1],
		[-2, -1, 1, 2],
		[-2,  0, 0, 2]
	]
	*/
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		/*
		由于有四个数
		a + b + c + d = target
		我们将其降维后得
		b + c + d = target - a
		于是这道题就变成了三数求和的问题(可用双指针发求解)
		*/
		if (nums.size() < 4)
			return vector<vector<int>>{};

		vector<vector<int>> ret;
		std::sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 3; ++i) {
			if(i > 0 && nums[i] == nums[i-1])
				continue;	//相同值跳过验证
			//int ntar = target - nums[i];
			for (int j = i + 1; j < nums.size() - 2; ++j) {
				if(j > i + 1 && nums[j] == nums[j - 1])
					continue;
				int m = j + 1;
				int n = nums.size() - 1;
				while (m < n) {
					if (nums[i] + nums[j] + nums[m] + nums[n] - target > 0) {
						--n;
					}
					else if (nums[i] + nums[j] + nums[m] + nums[n] - target < 0) {
						++m;
					}
					else {
						ret.push_back({ nums[i] , nums[j] , nums[m] , nums[n] });
						--n;
						do {
							++m;
						} while (m < n && nums[m] == nums[m - 1]);
					}
				}
			}
		}
		return ret;
	}
};

int main(int argc, char const *argv[])
{
	CFourSum cls;
	auto& ret = cls.fourSum(vector<int>{1, 0, -1, 0, -2, 2}, 0);
	cout << "[" << endl;
	for (auto &line : ret) {
		cout << "[";
		for (auto i : line) {
			cout << i << ",";
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;
	return 0;
}
