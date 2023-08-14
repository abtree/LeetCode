#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinimumNumberOfArrowsToBurstBalloons{
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //需要先排序
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] < b[0])
                return true;
            if(a[0] > b[0])
                return false;
            if(a[1] < b[1])
                return true;
            return false;
        });
        //再找最大子区间
        vector<pair<int, int>> dp;
        for(auto& point : points){
            bool find = false;
            for(auto& x : dp){
                if(x.first > point[1] || x.second < point[0]){
                    continue;
                }
                find = true;
                x.first = max(x.first, point[0]);
                x.second = min(x.second, point[1]);
            }
            if(!find){
                dp.push_back({point[0], point[1]});
            }
        }
        return dp.size();
    }
public:
    int findMinArrowShots1(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        //简化版 思路与上面一样 但排序后 只考虑右边界
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int pos = points[0][1];
        int ans = 1;
        for(auto& point : points){
            if(point[0] > pos){
                ++ans;
                pos = point[1];
            }
        }
        return ans;
    }
};

int main(){
    MinimumNumberOfArrowsToBurstBalloons cls;
    vector<vector<int>> dp3{
        {3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}
    };
    cout << cls.findMinArrowShots1(dp3) << " -> 2" << endl;

    vector<vector<int>> dp{
        {10,16},{2,8},{1,6},{7, 12}
    };
    cout << cls.findMinArrowShots1(dp) << " -> 2" << endl;

    vector<vector<int>> dp1{
        {1,2},{3,4},{5,6},{7, 8}
    };
    cout << cls.findMinArrowShots1(dp1) << " -> 4" << endl;

    vector<vector<int>> dp2{
        {1,2},{2,3},{3,4},{4, 5}
    };
    cout << cls.findMinArrowShots1(dp2) << " -> 2" << endl;
}