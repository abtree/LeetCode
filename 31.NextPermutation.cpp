#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//31. 下一个排列
class CNextPermutation{
    /*
    实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
    如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
    必须原地修改，只允许使用额外常数空间。

    以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1
    */
public:
    void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2)
			return;
		int end = nums.size() - 1;
		for (int i = end - 1; i >= 0; --i) {
			if (nums[i] < nums[i + 1]) {
				//先找到一个替换该位置的值
				for (int j = end; j > i; --j) {
					if (nums[j] > nums[i]) {
						//交换这两个点
						swap(nums[i], nums[j]);
						//在将后面的数组倒叙
						reverse(nums.begin() + i + 1, nums.end());
						return;
					}
				}
			}
		}
		//这是不存在下一个更大序列的情况
		reverse(nums.begin(), nums.end());
    }
};

int main(int argc, char const *argv[])
{
	CNextPermutation cls;
	vector<int> ret{ 1, 2, 3 };
	cls.nextPermutation(ret);
	cout << "[";
	for (auto &it : ret) {
		cout << it << ",";
	}
	cout << "]" << endl;

	vector<int>ret1{ 3, 2, 1 };
	cls.nextPermutation(ret1);
	cout << "[";
	for (auto &it1 : ret1) {
		cout << it1 << ",";
	}
	cout << "]" << endl;

	vector<int>ret2{ 1, 1, 5 };
	cls.nextPermutation(ret2);
	cout << "[";
	for (auto &it2 : ret2) {
		cout << it2 << ",";
	}
	cout << "]" << endl;
	return 0;
}
