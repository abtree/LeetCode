#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//1 两数之和
class CTwoNumAdd {
	/*
	给定一个整数数组nums和一个目标值target,请你在该数组中找出和为目标值的那两个整数,并返回他们的数组下标.你可以假设每种输入只会对应一个答案.但是,数组中同一个元素不能使用两遍.

	示例:
	给定 nums = [2, 7, 11, 15], target = 9
	因为 nums[0] + nums[1] = 2 + 7 = 9
	所以返回 [0, 1]
	*/
public:
	//时间优先法
	vector<int> twoSum(vector<int>& nums, int target) {
		/*
		在遍历数组的过程中
		1 如果当前数组元素值 与已经变量过的一个数组元素值 之和为目标值 输出两个值的下标
		2 如果当前数组元素值无法与已经变量的某个值之和为目标值 将当前元素值存入临时map 以便之后使用
		注意：如果数组中存在重复的值，如果两个重复值之和恰巧为目标值 将会输出两个值的下标，否则只需要记录其中一个值和对应的下标即可
		*/
		unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); ++i) {
			if (mp.count(target - nums[i]) > 0) {
				return vector<int>{i, mp[target - nums[i]]};
			}
			else {
				mp.insert({ nums[i], i });
			}
		}
		return vector<int>{};
	}
	//空间优先法
	vector<int> twoSum2(vector<int>& nums, int target) {
		/*
		这个方法逻辑简单 而且不需要开辟辅助空间
		缺点是需要运行更多的时间
		*/
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				//if(j == i)
				//	continue;	//排除自己相加
				if (nums[i] + nums[j] == target) {
					return vector<int>{i, j};
				}
			}
		}
		return vector<int>{};
	}
};

int main(int argc, char const *argv[])
{
	int typ = 1;

	vector<int> nums{ 2, 7, 4, 11, 15, 4 };
	CTwoNumAdd two;
	if (typ == 1) {
		auto ret = two.twoSum2(nums, 8);
		if (!ret.empty(), ret.size() == 2) {
			cout << ret[0] << " " << ret[1] << endl;
		}
		else {
			cout << "ret is empty" << endl;
		}
	}
	else {
		auto ret = two.twoSum2(nums, 8);
		if (!ret.empty(), ret.size() == 2) {
			cout << ret[0] << " " << ret[1] << endl;
		}
		else {
			cout << "ret is empty" << endl;
		}
	}
	return 0;
}
