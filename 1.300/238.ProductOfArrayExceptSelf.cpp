#include <iostream>
#include <vector>

using namespace std;

//238. 除自身以外数组的乘积
class ProductOfArrayExceptSelf {
    /* 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
    提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
    说明: 请不要使用除法(如果元素包含0，除法会失败)，且在 O(n) 时间复杂度内完成此题。
    进阶：你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
    */
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> pre(size, 1);
        vector<int> last(size, 1);
        pre[0] = nums[0];
        for(int i = 1; i< size;++i){
            pre[i] = pre[i-1]*nums[i];
        }
        last[size-1] = nums[size - 1];
        for(int i =  size-2; i>= 0; --i){
            last[i] = last[i+1]*nums[i];
        }
        vector<int> ret(size, 1);
        ret[0] = last[1];
        ret[size-1] = pre[size-2];
        size -=1;
        for(int i = 1; i < size; ++i){
            ret[i] = pre[i-1] * last[i+1];
        }
        return ret;
    }
public:
    vector<int> productExceptSelf2(vector<int>& nums) {
        //用一个数组解决问题的方法
        int size = nums.size();
        vector<int> ret(size, 1);
        //先计算pre
        ret[0] = 1;
        for(int i = 1; i< size;++i){
            ret[i] = ret[i-1]*nums[i-1];
        }
        //用 r 表示last数组 并同时计算结果
        int r = nums[size-1];
        for(int i = size - 2; i >0; --i){
            ret[i] = ret[i]*r;
            r *= nums[i];
        }
        ret[0] = r;
        return ret;
    }
};

int main(int argc, char const *argv[]){
    ProductOfArrayExceptSelf cls;
    auto& ret = cls.productExceptSelf2(vector<int>{1,2,3,4});
    cout << "[";
    for(auto i : ret){
        cout << i << ",";
    }
    cout << "]" << endl;

    return 0;
}
