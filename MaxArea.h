#pragma once

//11 盛最多水的容器
class CMaxArea {
	/*
	给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
	说明：你不能倾斜容器，且 n 的值至少为 2。

	示例：
	输入：[1,8,6,2,5,4,8,3,7]
	输出：49
	*/
public:
	int maxArea(vector<int>& height) {
		/*
		双循环枚举法 逻辑简单
		O(n^2)
		*/
		int n = height.size();
		if (n < 2)
			return 0;
		int ret = 0;
		for (int i = 0; i < n - 1; ++i) {
			for (int j = n-1; j > i; --j) {
				int cur = height[i] < height[j] ? height[i] : height[j];
				cur *= j - i;
				if (ret < cur)
					ret = cur;
			}
		}
		return ret;
	}
	int maxArea2(vector<int>& height) {
		/*
		双指针法(标准解法)
		首先左右两个指针i，j分别指向数组两端
		由于容器的水量是由最小高度决定的 所以对于i，j中较小的值(假如为i),此时无论怎么移动j，所得的面积都一定小于i，j的面积，所以需要移动i
		即直到i == j ，一直移动i，j中最小的一个
		O(n)
		*/
		int j = height.size() - 1;
		if (j < 1)
			return 0;
		int i = 0;
		int ret = 0;
		while (i < j) {
			int cur = 0;
			if (height[i] < height[j]) {
				cur = height[i] * (j - i);
				++i;
			}
			else {
				cur = height[j] * (j - i);
				--j;
			}
			if (ret < cur)
				ret = cur;
		}
		return ret;
	}
public:
	static void Test() {
		CMaxArea cls;
		cout << cls.maxArea2(vector<int>{ 1,8,6,2,5,4,8,3,7 }) << " -> 49" << endl;
	}
};