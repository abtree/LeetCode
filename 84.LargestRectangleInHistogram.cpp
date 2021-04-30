#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//84. 柱状图中最大的矩形
class LargestRectInHist {
    /*
    给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
    求在该柱状图中，能够勾勒出来的矩形的最大面积。
    以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
    图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

    示例:
    输入: [2,1,5,6,2,3]
    输出: 10
    */
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
            return 0;
        //暴力法(会超时) 计算每一根柱子开始的最大面积
        int s = heights.size() - 1;
        int big = 0, cur = 0, low = 0;
        for(int i = 0; i<= s; ++i){
            for(int j = i; j<=s;++j){
                if(i == j){
                    cur = heights[i];
                    if(cur > big)
                        big = cur;
                    low = heights[i];
                    continue;
                }
                if(heights[j] < low){
                    low = heights[j];
                }
                if(low <= 0)
                    break;
                cur = low * (j-i+1);
                if(cur > big)
                    big = cur;
            }
        }
        return big;
    }
public:
    int largestRectangleArea2(vector<int>& heights) {
        /*
        单调栈
        即栈里面的元素大小单调递增,我们可以从栈顶到栈底计算从每个元素出发能形成的最大面积，但要记住最后一个元素入栈后，需要最后执行一次面积计算，所以，最后需要额外插入一个最小值。
        */
        heights.push_back(0); //最后加一个最小值，保证执行完后栈里只有这个额外值
        
        int size = heights.size();
        stack<int> stk; //保证栈是单调递增的 方便我们计算宽
        stk.push(0);
        int ret = heights[0];
        for(int i = 1; i< size; ++i){
            while(!stk.empty() && heights[stk.top()] > heights[i]){ //栈不为空 且栈顶元素大于当前元素 需要将栈顶元素退栈
                int hei = heights[stk.top()];    //当前位置的高
                stk.pop();
                int wei = i;    //如果栈空了 宽就为从开始到i的长度
                if(!stk.empty()){
                   wei = i - stk.top() - 1; //否则宽为 上一个元素到i的距离
                }
                ret = max(ret, wei*hei);    //获取最大面积
            }
            stk.push(i);    //将当前元素进栈
        }
        return ret;
    }
};

int main(int argc, char const* argv[])
{
    LargestRectInHist cls;
    cout << cls.largestRectangleArea2(vector<int>{2,1,5,6,2,3}) << " -> 10" << endl;
    cout << cls.largestRectangleArea2(vector<int>{5,2,1,2,6}) << " -> 6" << endl;
    return 0;
}
