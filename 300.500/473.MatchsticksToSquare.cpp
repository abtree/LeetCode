#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class MatchsticksToSquare{
public:
    bool makesquare(vector<int> matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0){
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> edges(4);
        return dfs(0, matchsticks, edges, sum / 4);
    }
    bool dfs(int index, vector<int>& matchsticks, vector<int>& edges, int len){
        if(index == matchsticks.size()){
            return true;
        }
        for(int i =0;i<edges.size();++i){
            edges[i] += matchsticks[index];
            if(edges[i] <= len && dfs(index+1,matchsticks, edges, len)){
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }
    bool makesquare1(vector<int> matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0){
            return false;
        }
        int edge = sum / 4;
        int size = matchsticks.size();
        vector<int> dp(1<<size, -1);
        dp[0]=0;
        for(int s=1;s<(1<<size);++s){
            for(int k=0;k<size;++k){
                if(s & (1<<k) == 0){    //这里表示第k根已经放进去了 所以不重复放
                    continue;
                }
                int s1 = s & ~(1 << k);  //s1标识s去掉第k根
                if(dp[s1] >= 0 && dp[s1] + matchsticks[k] <= edge){
                    dp[s] = (dp[s1] + matchsticks[k]) % edge;
                    break;
                }
            }
        }
        return dp[(1<<size) - 1] == 0;
    }
};

int main(){
    MatchsticksToSquare cls;
    cout << boolalpha << cls.makesquare1(vector<int>{1,1,2,2,2}) << " -> true" << endl;
    cout << boolalpha << cls.makesquare1(vector<int>{3,3,3,3,4}) << " -> false" << endl;
    return 0;
}
