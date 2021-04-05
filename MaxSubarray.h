#pragma once

//53. 最大子序和
class MaxSubarray {
    /*
    给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
    示例:
        输入: [-2,1,-3,4,-1,2,1,-5,4]
        输出: 6
        解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
    */
public:
    int maxSubArray(vector<int>& nums) {
        //动态规划
        int pre = 0;
        int max = nums[0];
        for (auto& it : nums) {
            pre = (pre < 0) ? it : pre + it;
            if (max < pre)
                max = pre;
        }
        return max;
    }
public:
    //分治 解法
    struct Status {
        int lSum,   //从最左边出发的最大子串
            rSum,   //从最右边出发的最大子串
            mSum,   //最大子串
            iSum;   //总和
    };

    //合并两个分治
    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;     //合并总和=左边总和+右边总和
        int lSum = max(l.lSum, l.iSum + r.lSum);    //可能等于左边最大lsum 或者 左边总和 + 右边lsum (取两者大的) 
        int rSum = max(r.rSum, r.iSum + l.rSum);    //同上 可能等于右边rsum 或者 右边isum + 左边rsum (取两者大的)
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);   //三个情况 左边msum,右边msum或者 左边rsum+右边lsum
        return Status{ lSum, rSum, mSum, iSum };
    };

    Status get(vector<int>& a, int l, int r) {
        if (l == r) {
            return Status{ a[l], a[l], a[l], a[l] };
        }
        int m = (l + r) >> 1;
        //这里递归不断细分 直到只有一个元素
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        //这里将分治合并
        return pushUp(lSub, rSub);
    }

    int maxSubArray2(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
public:
    static void Test() {
        MaxSubarray cls;
        cout << cls.maxSubArray(vector<int>{1}) << " -> 1" << endl;
        cout << cls.maxSubArray(vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4}) << " -> 6" << endl;
    }
};