#include <iostream>
#include <vector>

using namespace std;

class PacificAtlanticWaterFlow{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        /* 0表示不能流入 1表示能流入 2表示待定 */ 
        //判断能流入大西洋的点
        vector<vector<int>> pacific(m, vector<int>(n, 2));
        for (int i = 0; i < m;++i) {
            pacific[i][0] = 1;
        }
        for (int j = 0; j < n;++j) {
            pacific[0][j] = 1;
        }
        for (int i = 1; i < m; ++i){
            for (int j = 1;j < n;++j) {
                if (pacific[i][j] == 2)
                    if (!can(heights, pacific, i, j)) {
                        pacific[i][j] = 0;
                    }
            }
        }

        //判断能流入大西洋的点
        vector<vector<int>> atlantic(m, vector<int>(n, 2));
        for (int i = 0; i < m;++i) {
            atlantic[i][n-1] = 1;
        }
        for (int j = 0; j < n;++j) {
            atlantic[m-1][j] = 1;
        }
        for (int i = m - 2;i >= 0;--i) {
            for (int j = n - 2;j >= 0;--j) {
                if (atlantic[i][j] == 2) {
                    if (!can(heights, atlantic, i, j)) {
                        atlantic[i][j] = 0;
                    }
                }
            }
        }

        vector<vector<int>> ret;
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    ret.push_back(vector<int>{i, j});
                }
            }
        }
        return ret;
    }
private:
    bool can(vector<vector<int>>& heights, vector<vector<int>>& dp, int i, int j) {
        for (int k = 0; k < 4;++k) {
            int ni = i + dirs[k];
            int nj = j + dirs[k + 1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && heights[ni][nj] <= heights[i][j]) {
                if (dp[ni][nj] == 1) {
                    dp[i][j] = 1;
                    return true;
                }
                else if (dp[ni][nj] == 2) {
                    dp[i][j] = 0;
                    if (can(heights, dp, ni, nj)) {
                        dp[i][j] = 1;
                        return true;
                    }
                    dp[i][j] = 2;
                }
            }
        }
        return false;
    }
private:
    int m = 0;
    int n = 0;
    vector<int> dirs{ 1,0,-1,0,1 };
};

int main(int argc, char const* argv[]) {
    PacificAtlanticWaterFlow cls;
    auto& ret = cls.pacificAtlantic(vector<vector<int>>{{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}});
    cout << "[";
    for (auto& it : ret) {
        cout << "[" << it[0] << "," << it[1] << "],";
    }
    cout << "]" << endl;

    auto& ret1 = cls.pacificAtlantic(vector<vector<int>>{ {2, 1}, {1,2}});
    cout << "[";
    for (auto& it : ret1) {
        cout << "[" << it[0] << "," << it[1] << "],";
    }
    cout << "]" << endl;

    auto& ret2 = cls.pacificAtlantic(vector<vector<int>>{{8,13,11,18,14,16,16,4,4,8,10,11,1,19,7},{2,9,15,16,14,5,8,15,9,5,14,6,10,15,5},{15,16,17,10,3,6,3,4,2,17,0,12,4,1,3},{13,6,13,15,15,16,4,10,7,4,19,19,4,9,13},{7,1,9,14,9,11,5,4,15,19,6,0,0,13,5},{9,9,15,12,15,5,1,1,18,1,2,16,15,18,9},{13,0,4,18,12,0,11,0,1,15,1,15,4,2,0},{11,13,12,16,9,18,6,8,18,1,5,12,17,13,5},{7,17,2,5,0,17,9,18,4,13,6,13,7,2,1},{2,3,9,0,19,6,6,15,14,4,8,1,19,5,9},{3,10,5,11,7,14,1,5,3,19,12,5,2,13,16},{0,8,10,18,17,5,5,8,2,11,5,16,4,9,14},{15,9,16,18,9,5,2,5,13,3,10,19,9,14,3},{12,11,16,1,10,12,6,18,6,6,18,10,9,5,2},{17,9,6,6,14,9,2,2,13,13,15,17,15,3,14},{18,14,12,6,18,16,4,10,19,5,6,8,9,1,6}});
    cout << "[";
    for (auto& it : ret2) {
        cout << "[" << it[0] << "," << it[1] << "],";
    }
    cout << "]" << endl;

    auto& ret3 = cls.pacificAtlantic(vector<vector<int>>{{11,3,2,4,14,6,13,18,1,4,12,2,4,1,16},{5,11,18,0,15,14,6,17,2,17,19,15,12,3,14},{10,2,5,13,11,11,13,19,11,17,14,18,14,3,11},{14,2,10,7,5,11,6,11,15,11,6,11,12,3,11},{13,1,16,15,8,2,16,10,9,9,10,14,7,15,13},{17,12,4,17,16,5,0,4,10,15,15,15,14,5,18},{9,13,18,4,14,6,7,8,5,5,6,16,13,7,2},{19,9,16,19,16,6,1,11,7,2,12,10,9,18,19},{19,5,19,10,7,18,6,10,7,12,14,8,4,11,16},{13,3,18,9,16,12,1,0,1,14,2,6,1,16,6},{14,1,12,16,7,15,9,19,14,4,16,6,11,15,7},{6,15,19,13,3,2,13,7,19,11,13,16,0,16,16},{1,5,9,7,12,9,2,18,6,12,1,8,1,10,19},{10,11,10,11,3,5,12,0,0,8,15,7,5,13,19},{8,1,17,18,3,6,8,15,0,9,8,8,12,5,18},{8,3,6,12,18,15,10,10,12,19,16,7,17,17,1},{12,13,6,4,12,18,18,9,4,9,13,11,5,3,14},{8,4,12,11,2,2,10,3,11,17,14,2,17,4,7},{8,0,14,0,13,17,11,0,16,13,15,17,4,8,3},{18,15,8,11,18,3,10,18,3,3,15,9,11,15,15}});
    cout << "[";
    for (auto& it : ret3) {
        cout << "[" << it[0] << "," << it[1] << "],";
    }
    cout << "]" << endl;
    return 0;
}
