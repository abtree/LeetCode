#include <iostream>
#include <vector>

using namespace std;

//162. 寻找峰值
class FindPeakElement
{
    /* 峰值元素是指其值大于左右相邻值的元素。给你一个输入数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。你可以假设 nums[-1] = nums[n] = -∞ 。
    */
public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 0; i< nums.size(); ++i){
            if(i > 0){
                if(nums[i-1] >= nums[i])
                    continue;
            }
            if(i < nums.size() - 1){
                if(nums[i+1] >= nums[i])
                    continue;
            }
            return i;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    FindPeakElement cls;
    cout << cls.findPeakElement(vector<int>{1,2,3,1}) << " -> 2" << endl;
    cout << cls.findPeakElement(vector<int>{1,2,1,3,5,6,4}) << " -> 1" << endl;
    return 0;
}
