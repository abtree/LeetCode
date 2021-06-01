#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//153. 寻找旋转排序数组中的最小值
class FindMinimumInRotatedSortedArray
{
    /* 给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
    */
public:
    int findMin(vector<int>& nums) {
        //二分法
        int end = nums.size()-1;
        int start = 0;
        while(start < end - 1){
            int mid = (end + start) / 2;
            if(nums[mid] > nums[end]){
                //在后半段
                start = mid;
            }else{
                //在前半段
                end = mid;
            }
        }
        if(start != end){
            return min(nums[start], nums[end]);
        }else{
            return nums[start];
        }
    }
public:
    int findMin2(vector<int>& nums) {
        //遍历法
        for(int i = 1; i< nums.size(); ++i){
            if(nums[i] < nums[i-1])
                return nums[i];
        }
        return nums[0];
    }
};

int main(int argc, char const* argv[])
{
    FindMinimumInRotatedSortedArray cls;
    cout << cls.findMin2(vector<int>{3,4,5,1,2}) << " -> 1" << endl;
    cout << cls.findMin2(vector<int>{4,5,6,7,0,1,2}) << " -> 0" << endl;
    cout << cls.findMin2(vector<int>{11,13,15,17}) << " -> 11" << endl;
    return 0;
}