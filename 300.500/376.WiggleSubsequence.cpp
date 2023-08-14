#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 376. 摆动序列
class WiggleSubsequence{
public:
    int wiggleMaxLength(vector<int>& nums) {
        //动态规划
        int dp = 1; //这里dp只需要保存最后值就可以了
        bool big = true;
        int i = 1;
        while(i < nums.size() && nums[i] == nums[i-1]){
            ++i;
        }
        if(i >= nums.size())
            return 1;
        if(nums[i] > nums[i-1]){
            big = false;
        }
        dp = 2;
        ++i;
        for(;i< nums.size();++i){
            if((big && nums[i] > nums[i-1]) || (!big && nums[i] < nums[i-1])){
                ++dp;
                big = !big;
            }
        }
        return dp;
    }
};

int main(int argc, char const *argv[]){
    WiggleSubsequence cls;
    cout << cls.wiggleMaxLength(vector<int>{3,3,3,2,5}) << " -> 3" << endl;
    cout << cls.wiggleMaxLength(vector<int>{1,2,3,4,5,6,7,8,9}) << " -> 2" << endl;
    cout << cls.wiggleMaxLength(vector<int>{1,17,5,10,13,15,10,5,16,8}) << " -> 7" << endl;
    cout << cls.wiggleMaxLength(vector<int>{1,7,4,9,2,5}) << " -> 6" << endl;
    return 0;
}
