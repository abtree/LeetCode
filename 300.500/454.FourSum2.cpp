#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class FourSum2{
public:
    int fourSumCount(vector<int> nums1, vector<int> nums2, vector<int> nums3, vector<int> nums4) {
        if(nums1.empty())
            return 0;
        unordered_map<int, int> dp;
        for(int a : nums1){
            for(int b: nums2){
                dp[a+b]++;
            }
        }
        int ans = 0;
        for(int c : nums3){
            for(int d : nums4){
                ans += dp[-c-d];
            }
        }
        return ans;
    }
};

int main(){
    FourSum2 cls;
    cout << cls.fourSumCount(vector<int>{1,2},vector<int>{-2,-1},vector<int>{-1,2},vector<int>{0,2}) << " -> 2" << endl;
    cout << cls.fourSumCount(vector<int>{0},vector<int>{0},vector<int>{0},vector<int>{0}) << " -> 1" << endl;
}