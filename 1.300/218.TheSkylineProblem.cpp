#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 218. 天际线问题
class TheSkylineProblem {
    /* 城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。给你所有建筑物的位置和高度，请返回由这些建筑物形成的 天际线 。每个建筑物的几何信息由数组 buildings 表示，其中三元组 buildings[i] = [lefti, righti, heighti] 表示：lefti 是第 i 座建筑物左边缘的 x 坐标。righti 是第 i 座建筑物右边缘的 x 坐标。heighti 是第 i 座建筑物的高度。天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，并按 x 坐标 进行 排序 。关键点是水平线段的左端点。列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0 ，仅用于标记天际线的终点。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。
    注意：输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]
    */
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<vector<int>> output;
        skyline(buildings, 0, n, output);
        return output;
    }
private:
    void skyline(vector<vector<int>>& buildings, int start, int end, vector<vector<int>>& output){
        if(end == start)
            return;
        if(end - start == 1){
            output.emplace_back(vector<int>{buildings[start][0], buildings[start][2]});
            output.emplace_back(vector<int>{buildings[start][1], 0});
            return;
        }

        vector<vector<int>> leftSkyline, rightSkyline;
        skyline(buildings, start, (end + start)/2, leftSkyline);
        skyline(buildings, (end + start)/2, end, rightSkyline);
        merge(leftSkyline, rightSkyline, output);
    }
    void merge(vector<vector<int>>& left, vector<vector<int>>& right, vector<vector<int>>& output){
        int nL = left.size(), nR = right.size();
        int pL = 0, pR =0;
        int currY = 0, leftY = 0, rightY = 0;
        int x, maxY;
        while((pL < nL) && (pR < nR)){
            if(left[pL][0] < right[pR][0]){
                x = left[pL][0];
                leftY = left[pL][1];
                ++pL;
            }else{
                x = right[pR][0];
                rightY = right[pR][1];
                ++pR;
            }
            maxY = max(leftY, rightY);
            if(currY != maxY){
                update(output, x, maxY);
                currY = maxY;
            }
        }
        append(output, left, pL, nL, currY);
        append(output, right, pR, nR, currY);
    }
    void update(vector<vector<int>>& output, int x, int y){
        if(output.empty() || (*output.rbegin())[0] != x){
            output.push_back(vector<int>{x, y});
        }else{
            (*output.rbegin())[1] = y;
        }
    }
    void append(vector<vector<int>>& output,vector<vector<int>>& skyline, int p, int n, int currY){
        while(p < n){
            if(currY != skyline[p][1]){
                update(output, skyline[p][0], skyline[p][1]);
                currY = skyline[p][1];
            }
            ++p;
        }
    }
public:
    vector<vector<int>> getSkyline2(vector<vector<int>>& buildings) {
      	priority_queue<pair<int, int>> pq;  // 保存候选建筑的高度和右边界，按高度建立大根堆
        int left = buildings[0][0], right = buildings[0][1], h = buildings[0][2];
        pq.push({ h, right });

        vector<vector<int>> ans;
        int j = 1, n = buildings.size();
        while (pq.size()) {
            // 下一个数组的左边界小于等于right（意味着下一个建筑和当前区间有重叠），且高度不高于h
            while (j < n && buildings[j][0] <= right && buildings[j][2] <= h) {
                if (buildings[j][2] == h) { // 建筑高度和h相同
                    pq.pop();
                    right = max(right, buildings[j][1]);    // 合并区间
                    pq.push({ h, right });    // 将新的右边界推入优先队列
                }
                else if (buildings[j][1] > right) {    // 右边界在当前区间外才可能构成天际线
                    pq.push({ buildings[j][2], buildings[j][1] });
                }
                j++;
            }

            // 下一个数组的左边界小于等于right（意味着下一个建筑和当前区间有重叠），且高度高于h
            if (j < n && buildings[j][0] <= right && buildings[j][2] > h) {
                if (buildings[j][0] > left) // 只有left和建筑的左边界不重合，对天际线有贡献
                    ans.push_back({ left, h });

                // 调整区间和高度
                left = buildings[j][0];
                right = buildings[j][1];
                h = buildings[j++][2];
                pq.push({ h, right });
                continue;
            }

            // 下一个数组的左边界大于right，意味着下一个建筑和当前区间没有重叠或者已经没有下一个建筑了
            if ((j < n && buildings[j][0] > right) || j == n) {
                pq.pop();
                while (pq.size())               // 弹出不可能对天际线有贡献的建筑
                    if (pq.top().second <= right)
                        pq.pop();
                    else
                        break;
                ans.push_back({ left, h });       // 将当前区间和高度推入ans
                if (pq.size()) {                // 还有候选建筑
                                                // 调整参数
                    left = right;
                    right = pq.top().second;
                    h = pq.top().first;
                }
                else {                        // 没有候选建筑
                    ans.push_back({ right, 0 });  // 由于没有和当前区间重叠的建筑了，把平地推入ans

                    if (j == n)                 // 没有下一个建筑了，结束整个循环
                        break;

                    // 调整参数为下一个建筑
                    left = buildings[j][0];
                    right = buildings[j][1];
                    h = buildings[j++][2];
                    pq.push({ h, right });
                }
            }
        }

        return ans;  
    }
};

int main(int argc, char const *argv[])
{
    TheSkylineProblem cls;
    auto &ret = cls.getSkyline2(vector<vector<int>>{
        {2,9,10},
        {3,7,15},
        {5,12,12},
        {15,20,10},
        {19,24,8}
    });
    cout << "[";
    for(auto &it : ret){
        cout << "[";
        for(auto &it1 : it){
            cout << it1 << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    auto &ret1 = cls.getSkyline2(vector<vector<int>>{
        {0,2,3},
        {2,5,3}
    });
    cout << "[";
    for(auto &it : ret1){
        cout << "[";
        for(auto &it1 : it){
            cout << it1 << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
    return 0;
}
