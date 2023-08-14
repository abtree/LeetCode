#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//307. 区域和检索 - 数组可修改
class NumArray {
    /* 给你一个数组 nums ，请你完成两类查询，其中一类查询要求更新数组下标对应的值，另一类查询要求返回数组中某个范围内元素的总和。
    实现 NumArray 类：
    NumArray(int[] nums) 用整数数组 nums 初始化对象
    void update(int index, int val) 将 nums[index] 的值更新为 val
    int sumRange(int left, int right) 返回子数组 nums[left, right] 的总和（即，nums[left] + nums[left + 1], ..., nums[right]）
    */
public:
    NumArray(vector<int>& nums) {
        //半暴力法(会超时)
        dat.clear();
        dat.insert(dat.end(), nums.begin(), nums.end());
        pre.clear();
        pre.resize(nums.size(), 0);
        pre[0] = nums[0];
        for(int i = 1; i<nums.size(); ++i){
            pre[i] = pre[i-1]+nums[i];
        }
    }
    
    void update(int index, int val) {
        int dec = val - dat[index];
        dat[index] = val;
        while(index < pre.size()){
            pre[index] += dec;
            ++index;
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return pre[right];
        return pre[right] - pre[left-1];
    }
private:
    vector<int> dat;
    vector<int> pre;
};

class NumArray1 {
    //分块法（暴力法的优化版本）
public:
    NumArray1(vector<int>& nums) {
        block = sqrt(nums.size());  //以sqrt(n)为分块大小
        int size = nums.size() / block + 1;
        dat.clear();
        dat.resize(nums.size(), 0);
        pre.clear();
        pre.resize(size, 0);
        for(int i = 0; i< nums.size(); ++i){
            dat[i] = nums[i];
            pre[i/block] += nums[i];
        }
    }
    
    void update(int index, int val) {
        pre[index/block] += val - dat[index];
        dat[index] = val;
    }
    
    int sumRange(int left, int right) {
        int l = left / block;
        int start = l * block;
        int r = right / block;
        int end = min((int)dat.size()-1, (r+1)*block-1);
        int ret = 0;
        while(l <= r){
            ret+= pre[l];
            ++l;
        }
        while(start < left){
            ret -= dat[start];
            ++start;
        }
        while(end > right){
            ret -= dat[end];
            --end;
        }
        return ret;
    }
private:
    int block{};
    vector<int> dat;
    vector<int> pre;
};

class NumArray2 {
    /* 线性树法
    其实是构建了一颗平衡二叉树:特点是 父节点是两个子节点的和（即父节点的范围是两个子节点范围的和）
    如 子节点范围分别是[0-1][2-3],父节点范围就为[0-3]
    update时 我们需要从叶子节点一直向上修改到根节点
    */
public:
    NumArray2(vector<int>& nums) {
        size = nums.size();
        tree.clear();
        tree.resize(size*2, 0); //平衡二叉树的节点数为2n-1（n为叶子节点数）
        for(int i = size, j = 0; i < 2*size;++i,++j){
            tree[i] = nums[j];  // 填充所有叶子节点值
        }
        for(int i = size-1; i>0;--i){
            tree[i] = tree[i*2] + tree[i*2+1];  //根据子节点 计算父节点的值
        }
    }
    
    void update(int index, int val) {
        index += size;
        tree[index] = val;  //修改叶子节点
        while(index > 1){
            //根据叶子节点修改父节点
            int left = index;
            int right = index;
            if(index % 2 == 0){
                right+=1;    //修改的是左子节点
            }else{
                left-=1; //修改的是右子节点
            }
            index /= 2;
            tree[index] = tree[left] + tree[right];
        }
    }
    
    int sumRange(int left, int right) {
        left += size;
        right += size;
        int ret = 0;
        while(left <= right){
            if((left % 2) == 1){    //如果left指向的右节点（需要单独加上该节点，并且left指向下一位）
                ret += tree[left];  
                ++left; //这里是left值已经计算了 所以范围缩小，减去left
            }
            if((right % 2) == 0){   //如果right指向的左节点(需要单独加上该节点,并且right指向上一位)
                ret += tree[right];
                --right;
            }
            left/=2;
            right/=2;
        }
        return ret;
    }
private:
    int size{};
    vector<int> tree;   //用数组模拟二叉树
};

int main(int argc, char const *argv[]){
    NumArray2 cls(vector<int>{1,3,5});
    cout << cls.sumRange(0,2) << " -> 9" << endl;
    cls.update(1,2);
    cout << cls.sumRange(0,2) << " -> 8" << endl;
    return 0;
}

