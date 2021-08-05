#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// 354. 俄罗斯套娃信封问题
class RussianDollEnvelopes {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto less = [](const vector<int>& lcx, const vector<int>& rcx) -> bool {
            if (lcx[0] < rcx[0])
                return true;
            //注意：这里要保证w相同时，h按递减排列
            // 目的是忽略w相同的情况
            if (lcx[0] == rcx[0] && lcx[1] > rcx[1])
                return true;
            return false;
        };
        sort(envelopes.begin(), envelopes.end(), less);

        //贪心算法（见：300题）
        vector<int> dp;
        int size = envelopes.size();
        dp.push_back(envelopes[0][1]);
        for (int i = 1; i < size;++i) {
            if (envelopes[i][1] > dp.back()) {
                dp.push_back(envelopes[i][1]);
            }
            else {
                auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
                (*it) = envelopes[i][1];
            }
        }
        return dp.size();
    }
};

int main(int argc, char const* argv[]) {
    RussianDollEnvelopes cls;
    cout << cls.maxEnvelopes(vector<vector<int>>{
        {46, 89}, { 50,53 }, { 52,68 }, { 72,45 }, { 77,81 }
    }) << " -> 3" << endl;
    cout << cls.maxEnvelopes(vector<vector<int>>{
        {2, 100}, { 3,200 }, { 4,300 }, { 5,500 }, { 5,400 }, { 5,250 }, { 6,370 }, { 6,360 }, { 7,380 }
    }) << " -> 5" << endl;
    cout << cls.maxEnvelopes(vector<vector<int>>{
        {5, 4}, { 6,4 }, { 6,7 }, { 2,3 }
    }) << " -> 3" << endl;
    cout << cls.maxEnvelopes(vector<vector<int>>{
        {1, 1}, { 1,1 }, { 1,1 }
    }) << " -> 1" << endl;
    return 0;
}
