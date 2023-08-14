#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CombinationSum4{
public:
    int combinationSum4(vector<int>& nums, int target) {
        //暴力发 （会超时）
        sort(nums.begin(), nums.end());
        ret = 0;
        comb(nums, 0, target);
        return ret;
    }
private:
    void comb(vector<int>& nums, int sum, int target){
        for(auto c : nums){
            sum += c;
            if(sum > target)
                return;
            else if(sum == target){
                ++ret;
                return;
            }
            comb(nums, sum, target);
            sum -= c;
        }
    }
    int ret{};
public:
    int combinationSum4_2(vector<int>& nums, int target) {
        /*动态规划
        dp[i]表示目标值为i的结果
        */
       vector<long long> dp(target+1, 0);
       for(int i = 0; i<= target;++i){
           for(int c : nums){
                if(c == i){ //当前值与目标值恰好相等
                    dp[i] += 1;
                }else if(c < i){
                    dp[i] += dp[i-c];   //dp[i-c]与dp[i-c]+c个数一致
                }
                if(dp[i] > INT_MAX) //已经不满足题目要求了
                    break;
           }
       }
       return dp[target];
    }
};

int main(int argc, char const *argv[]){
    CombinationSum4 cls;
    cout << cls.combinationSum4_2(vector<int>{10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111}, 999) << " -> 1" << endl;
    cout << cls.combinationSum4_2(vector<int>{1,2,3}, 4) << " -> 7" << endl;
    cout << cls.combinationSum4_2(vector<int>{9}, 3) << " -> 0" << endl;
    cout << cls.combinationSum4_2(vector<int>{1,2,3}, 32) << " -> 181997601" << endl;
    return 0;
}
