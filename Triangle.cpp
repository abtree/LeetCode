#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//120. 三角形最小路径和
class Triangle
{
    /*给定一个三角形 triangle ，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
    */
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //递归计算（会超时）
        ret = INT_MAX;
        minimum(triangle, 0, 0, 0);
        return ret; 
    }
private:
    void minimum(vector<vector<int>>& triangle, int layer, int pos, int cur){
        if(layer >= triangle.size()){
            if(cur < ret)
                ret = cur;
            return;
        }
        cur += triangle[layer][pos];
        minimum(triangle, layer+1, pos, cur);
        minimum(triangle, layer+1, pos+1, cur);
    }
private:
    int ret{};
public:
    int minimumTotal2(vector<vector<int>>& triangle){
        /* 动态规划 f(i,j)为到i行j列的最短路径 c(i,j)为第i行j列元素的值
            临界条件 f(0,0) = c(0,0)
            转移方程 f(i,j) = min[f(i-1,j-1), f(i-1,j)] + c(i, j)
                    注意考虑两个边界情况
        */
        int size = triangle.size();
        if(size < 1)
            return 0;
        vector<vector<int>> dp(size, vector<int>(size, 0));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < size;++i){
            for(int j = 0; j<=i; ++j){
                if(j == 0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                } else if(j == i){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                } else{
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                }
            }
        }
        return *std::min_element(dp[size-1].begin(), dp[size-1].end());
    }
public:
    int minimumTotal3(vector<vector<int>>& triangle){
        //倒推法(另一种动态规划)
        if(triangle.empty())
            return 0;
        int size = triangle.size();
        if(size < 2){
            return triangle[0][0];
        }
        for(int i = size - 2; i >= 0; --i){
            for(int j = 0; j <= i; ++j){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

int main(int argc, char const* argv[])
{
    Triangle cls;
    vector<vector<int>> vec1{
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    cout << cls.minimumTotal3(vec1) << " -> 11" << endl;

    vector<vector<int>> vec2{{-10}};
    cout << cls.minimumTotal3(vec2) << " -> -10" << endl;
    return 0;
}
