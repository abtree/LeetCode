#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//15 三数之和
class CThreeSums {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return vector<vector<int>>{};
		//先排序
		std::sort(nums.begin(), nums.end());

		vector<vector<int>> ret{};

		for (int i = 0; i < nums.size() - 2; ++i) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;	//这里是为了去重 如4个0的情况
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] > 0) {
					//此时k需要减小
					--k;
				}
				else if (nums[i] + nums[j] + nums[k] < 0) {
					//此时j需要增大
					++j;
				}
				else {
					vector<int>{nums[i], nums[j], nums[k] };
					ret.push_back(std::move(vector<int>{nums[i], nums[j], nums[k] }));
					--k;
					do {
						++j;
					} while (j < k && nums[j] == nums[j - 1]);
				}
			}
		}
		return ret;
	}
	vector<vector<int>> threeSum2(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3) {
			return res;
		}
		int maxNum = 0;
		int minNum = 0;
		for (const int d : nums) {
			maxNum = maxNum < d ? d : maxNum;
			minNum = minNum > d ? d : minNum;
		}
		const int tb_size = maxNum - minNum + 1;
		vector<char> rec(tb_size, 0);
		for (const int d : nums) {
			if (++rec[d - minNum] > 3) {
				rec[d - minNum] = 3;
			}
		}
		if (rec[-minNum] == 2) {
			rec[-minNum] = 1;
		}
		vector<int> v;
		for (int i = 0; i < tb_size; ++i)
			if (rec[i] > 0) {
				v.push_back(i + minNum);
			}
		const int vsz = v.size();
		for (int i = 0; i < vsz; ++i) {
			const int vmin = v[i];
			if (vmin > 0) {
				break;
			}
			for (int j = i; j < vsz; ++j) {
				const int vmid = v[j];
				const int target = -vmin - vmid;
				if (target < vmid) {
					break;
				}
				if (target > maxNum || rec[target - minNum] == 0) {
					continue;
				}
				if (rec[vmid - minNum] > 1 || vmin < vmid && vmid < target) {
					res.push_back({ vmin, vmid, target });
				}
			}
		}
		return res;
	}
public:
	void Print(vector<vector<int>>& ret) {
		cout << "{ \r\n";
		for (auto& it : ret) {
			cout << "[ ";
			for (auto& it1 : it) {
				cout << it1 << ", ";
			}
			cout << "] \r\n";
		}
		cout << "} \r\n";
	}
};

int main(int argc, char const* argv[])
{
	CThreeSums cls;
	auto& ret0 = cls.threeSum2(vector<int>{-2, 0, 0, 2, 2});
	cls.Print(ret0);
	auto& ret = cls.threeSum2(vector<int>{0, 0, 0, 0});
	cls.Print(ret);
	auto& ret1 = cls.threeSum2(vector<int>{-1, 0, 1, 2, -1, -4});
	cls.Print(ret1);
	return 0;
}
