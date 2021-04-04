#include <iostream>
#include <vector>

using namespace std;

//75. 颜色分类
class SortColors {
    /*
    给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
    此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
    注意：请不要使用代码库中的排序函数来解决这道题。

    进阶：
    你能想出一个仅使用常数空间的一趟扫描算法吗？
     
    示例 1：
    输入：nums = [2,0,2,1,1,0]
    输出：[0,0,1,1,2,2]

    示例 2：
    输入：nums = [2,0,1]
    输出：[0,1,2]

    示例 3：
    输入：nums = [0]
    输出：[0]

    示例 4：
    输入：nums = [1]
    输出：[1]
     
    提示：
    n == nums.length
    1 <= n <= 300
    nums[i] 为 0、1 或 2
    */
public:
    void sortColors(vector<int>& nums) {
        //单指针法
        int size = nums.size();
        int p = 0;
        for (int i = 0; i < size;++i) {
            //第一轮循环 先转移0
            if (nums[i] == 0) {
                if (i != p)
                    swap(nums[i], nums[p]);
                ++p;
            }
        }
        for (int i = p; i < size;++i) {
            //第二轮 转移1
            if (nums[i] == 1) {
                if (i != p)
                    swap(nums[i], nums[p]);
                ++p;
            }
        }
    }
public:
    void sortColors2(vector<int>& nums) {
        //双指针法
        int size = nums.size();
        int p = 0, q = 0;
        for (int i = 0; i < size;++i) {
            if (nums[i] == 1) {
                //处理1的情况
                if (i != q) {
                    swap(nums[i], nums[q]);
                }
                ++q;
                continue;
            }
            if (nums[i] == 0) {
                //处理0情况
                if (p != q) {
                    swap(nums[p], nums[q]); //需要把p位置的1交换到q位置 
                }
                if (i != p && i != q) { //1 == q时 就是将上面的交换再交换回来了
                    swap(nums[i], nums[p]); //再把0交换到p位置
                }
                ++q;
                ++p;
            }
        }
    }
};

int main() {
    SortColors cls;
    vector<int> ret5{ 1,0 };
    cls.sortColors2(ret5);
    cout << "[";
    for (auto i : ret5) {
        cout << i << ",";
    }
    cout << "]" << endl;

    vector<int> ret1{ 2, 0, 2, 1, 1, 0 };
    cls.sortColors2(ret1);
    cout << "[";
    for (auto i : ret1) {
        cout << i << ",";
    }
    cout << "]" << endl;

    vector<int> ret2{ 2, 0, 1 };
    cls.sortColors2(ret2);
    cout << "[";
    for (auto i : ret2) {
        cout << i << ",";
    }
    cout << "]" << endl;

    vector<int> ret3{ 0 };
    cls.sortColors2(ret3);
    cout << "[";
    for (auto i : ret3) {
        cout << i << ",";
    }
    cout << "]" << endl;

    vector<int> ret4{ 1 };
    cls.sortColors2(ret4);
    cout << "[";
    for (auto i : ret4) {
        cout << i << ",";
    }
    cout << "]" << endl;
    return 0;
}