#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//149. 直线上最多的点数
class MaxPointsOnALine
{
    /* 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。 */
public:
    int maxPoints(vector<vector<int>>& points) {
        //枚举法
        int ret = 1;
        for (int i = 0; i < points.size();++i) {
            ret = max(ret, count(points, i));
        }
        return ret;
    }
private:
    int count(vector<vector<int>>& points, int center) {
        unordered_map<double, int> lines;
        int maxCount = 0;
        for (int i = 0; i < points.size(); ++i) {
            if (i == center)
                continue;   //一样的点
            if (points[i][0] == points[center][0]) {
                maxCount += 1;    //斜率无穷大的点 需要特殊处理
                continue;
            }
            //其它斜率
            double key = (double)(points[center][1] - points[i][1]) / (double)(points[center][0] - points[i][0]);
            lines[key] += 1;
        }
        //返回点的最大值
        for (auto& it : lines) {
            if (it.second > maxCount) {
                maxCount = it.second;
            }
        }
        return maxCount + 1;
    }
};

int main(int argc, char const* argv[])
{
    MaxPointsOnALine cls;

    cout << cls.maxPoints(vector<vector<int>>{
        {1,1},{2,2},{3,3}
    }) << " -> 3" << endl;

    cout << cls.maxPoints(vector<vector<int>>{
        {1,1},{3,2},{5,3},{4,1},{2,3},{1,4}
    }) << " -> 4" << endl;
    return 0;
}
