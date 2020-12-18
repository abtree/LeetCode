#pragma once

//42. 接雨水
class CTrapRainWater {
	/*
	给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
	
	输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
	输出：6
	解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

	输入：height = [4,2,0,3,2,5]
	输出：9
	*/
public:
	int trap(vector<int>& height) {
		//双指针法
		int p = 0;
		int q = height.size() - 1;
		int ret = 0;
		while (p < q) {
			if (height[p] <= height[q]) {
				//移动左指针
				int cur = height[p];
				++p;
				while (p < q) {
					if (height[p] <= cur) {
						ret += cur - height[p];
						++p;
					}
					else {
						break;
					}
				}
			}
			else {
				//移动右指针
				int cur = height[q];
				--q;
				while (p < q)
				{
					if (height[q] <= cur) {
						ret += cur - height[q];
						--q;
					}
					else {
						break;
					}
				}
			}
		}
		return ret;
	}

	int trap2(vector<int>& height) {
		//动态规划法
		if (height.empty())
			return 0;
		int ans = 0;
		int size = height.size();
		vector<int> left(size), right(size);
		left[0] = height[0];
		for (int i = 1; i < size; ++i) {
			left[i] = max(left[i - 1], height[i]);
		}
		right[size - 1] = height[size - 1];
		for (int i = size - 2; i >= 0; --i) {
			right[i] = max(right[i + 1], height[i]);
		}
		for (int i = 0; i < size; ++i) {
			ans += min(left[i], right[i]) - height[i];
		}
		return ans;
	}
public:
	static void Test() {
		CTrapRainWater cls;
		int ret = cls.trap2(vector<int>{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
		cout << ret << " --> 6" << endl;
		ret = cls.trap2(vector<int>{4, 2, 0, 3, 2, 5});
		cout << ret << " --> 9" << endl;
	}
};