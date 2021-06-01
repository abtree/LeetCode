#include <iostream>
#include <vector>

using namespace std;

//189. 旋转数组
class RotateArray
{
    /* 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
    进阶：尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
    */
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size < 2 || k <= 0)
            return;
        vector<int> old;
        old.assign(nums.begin(), nums.end());
        k %= size;
        for(int i = 0; i< size; ++i){
            nums[(i+k)%size] = old[i];
        }
    }
public:
    void rotate2(vector<int>& nums, int k) {
        int size = nums.size();
        if(size < 2 || k <= 0)
            return;
        int start = 0;
        int count = 0;  //计算已经处理多少个元素
        k %= size;
        while(count < size){
            int cur = start;
            int value = nums[cur];
            do{
                cur = (cur + k)%size;
                swap(value, nums[cur]);
                ++count;
            }while(cur != start);
            ++start;    //这里需要注意：start++不会处理到已经处理过的元素，因为我们的间隔是等差的
        }
    }
public:
    void rotate3(vector<int>& nums, int k) {
        //旋转法
        int size = nums.size();
        if(size < 2 || k <= 0)
            return;
        k %= size;
        reverse(nums, 0, size -1);  //先将整个数组旋转
        reverse(nums, 0, k - 1);    //再将前k个元素旋转
        reverse(nums, k, size - 1); //再将剩余的元素旋转
    }
private:
    void reverse(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start], nums[end]);
            ++start;
            --end;
        }
    }
};

int main(int argc, char const* argv[])
{
    RotateArray cls;
    vector<int> arr{1,2,3,4,5,6,7};
    cls.rotate3(arr, 3);
    cout << "[";
    for(int c : arr){
        cout << c << ",";
    }
    cout << "]" << endl;

    vector<int> arr1{-1,-100,3,99};
    cls.rotate3(arr1, 2);
    cout << "[";
    for(int c : arr1){
        cout << c << ",";
    }
    cout << "]" << endl;
    return 0;
}
