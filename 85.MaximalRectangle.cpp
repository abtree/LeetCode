#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//85. 最大矩形
class MaximalRectangle {
    /*
    给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

    示例 1：
    输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    输出：6

    示例 2：
    输入：matrix = []
    输出：0

    示例 3：
    输入：matrix = [["0"]]
    输出：0

    示例 4：
    输入：matrix = [["1"]]
    输出：1

    示例 5：
    输入：matrix = [["0","0"]]
    输出：0
    */
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        /*
        算出每一行的每一个位置向上的大小，可转换为84题的柱状图最大矩形问题
        */
        int cols = matrix.size();
        int rows = matrix[0].size();
        vector<vector<int>> dp(cols, vector<int>(rows, 0));
        //先计算每一行的高度
        for(int i = 0; i < cols;++i){
            for(int j = 0; j<rows;++j){
                if(matrix[i][j] == '0')
                    continue;
                dp[i][j] = 1;
                if(i > 0)
                    dp[i][j] += dp[i-1][j];
            }
        }
        //再计算每行形成的最大矩阵
        int ret = 0;
        for(auto &it : dp){
            ret = max(ret, largestRectangleArea(it));
        }
        return ret;
    }
private:
    int largestRectangleArea(vector<int>& heights) {
        //这是柱状图求最大矩阵问题 ，参考84题
        heights.push_back(0); 
        
        int size = heights.size();
        stack<int> stk; 
        stk.push(0);
        int ret = heights[0];
        for(int i = 1; i< size; ++i){
            while(!stk.empty() && heights[stk.top()] > heights[i]){ 
                int hei = heights[stk.top()];
                stk.pop();
                int wei = i;
                if(!stk.empty()){
                   wei = i - stk.top() - 1;
                }
                ret = max(ret, wei*hei);
            }
            stk.push(i);
        }
        return ret;
    }
};

int main(int argc, char const* argv[])
{
    MaximalRectangle cls;
    cout << cls.maximalRectangle(vector<vector<char>>{
        {'1', '0', '1', '0','0'},
        {'1', '0', '1', '1','1'},
        {'1', '1', '1', '1','1'},
        {'1', '0', '0', '1','0'},
    }) << " -> 6" << endl;

    cout << cls.maximalRectangle(vector<vector<char>>{}) << " -> 0" << endl;
    cout << cls.maximalRectangle(vector<vector<char>>{{'0'}}) << " -> 0" << endl;
    cout << cls.maximalRectangle(vector<vector<char>>{{'1'}}) << " -> 1" << endl;
    cout << cls.maximalRectangle(vector<vector<char>>{{'0', '0'}}) << " -> 0" << endl;
    return 0;
}
