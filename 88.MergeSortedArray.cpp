#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//88. 合并两个有序数组
class MergeSortedArray {
    /*
    给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
    初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。

    示例 1：
    输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    输出：[1,2,2,3,5,6]

    示例 2：
    输入：nums1 = [1], m = 1, nums2 = [], n = 0
    输出：[1]
    */
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //简单解法 先插入 再排序
        for(int i = 0; i< n;++i){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
public:
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //指针法
        //1.先给nums1留出足够的空间 所以要先移动nums1的元素
        int p = m + n -1;
        int q = m -1;
        while(q >= 0){
            nums1[p] = nums1[q];
            --p;
            --q;
        }
        //2.遍历两个数组 合并
        int i = 0;
        ++p;
        ++q;
        while(i < n || p < m+n){
            if(i >= n){ //只剩nums1
                nums1[q] = nums1[p];
                ++q;
                ++p;
                continue;
            }
            if(p >= m+n){ //只剩nums2
                nums1[q] = nums2[i];
                ++q;
                ++i;
                continue;
            }
            //两个都有剩余
            if(nums1[p] <= nums2[i]){
                nums1[q] = nums1[p];
                ++p;
            }else{
                nums1[q] = nums2[i];
                ++i;
            }
            ++q;
        }
    }
};

int main(int argc, char const* argv[])
{
    MergeSortedArray cls;
    vector<int> n1{1,2,3,0,0,0};
    vector<int> n2{2,5,6};
    cls.merge2(n1, 3, n2, 3);
    cout << "[";
    for(int i : n1){
        cout << i << ",";
    }
    cout << "]" << endl;

    vector<int> n3{1};
    vector<int> n4{};
    cls.merge2(n3, 1, n4, 0);
    cout << "[";
    for(int i : n3){
        cout << i << ",";
    }
    cout << "]" << endl;

    return 0;
}
