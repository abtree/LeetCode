#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class PerfectRectangle {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        /*  在不发生碰撞的情况下 检查所有小矩形的面积和是否与大矩形相等
        */
        int col = rectangles.size();
        if (col <= 1)
            return true;    //一个的时候一定是完美矩形
        int total = count(rectangles[0]);
        vector<int> maxrect(rectangles[0]); //最后得到的大矩形
        for (int i = 1;i < col;++i) {
            //检查碰撞
            for (int j = i - 1; j >= 0; --j) {
                if (knock(rectangles[i], rectangles[j]))
                    return false;
            }
            //更新最大矩阵
            if (maxrect[0] > rectangles[i][0])
                maxrect[0] = rectangles[i][0];
            if (maxrect[1] > rectangles[i][1])
                maxrect[1] = rectangles[i][1];
            if (maxrect[2] < rectangles[i][2])
                maxrect[2] = rectangles[i][2];
            if (maxrect[3] < rectangles[i][3])
                maxrect[3] = rectangles[i][3];
            //添加小矩阵的面积
            total += count(rectangles[i]);
        }
        return count(maxrect) == total; //所有小矩阵的面积合 等于 大矩阵的面积
    }
private:
    bool knock(vector<int>& left, vector<int>& right) {
        //碰撞检测
        if (right[2] <= left[0] || left[2] <= right[0] || right[3] <= left[1] || left[3] <= right[1])
            return false;   //没有碰撞
        return true;    //碰撞
    }
    int count(vector<int>& rect) {
        return (rect[2] - rect[0]) * (rect[3] - rect[1]);
    }
};

class PerfectRectangle1 {
    /*
        思路与上面一样 在不发生碰撞的情况下 所有小矩形的面积 == 大矩形的面积
        但是优化碰撞检查 判断所有小矩形的顶点都被使用了2次（偶数次）
     */
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //这里其实是为了得到一个不重复的唯一key
        auto hash = [](int x, int y)->int {
            return x * 1024 + y;
        };
        //dp 记录每个顶点被使用的次数
        unordered_map<int, int> dp;
        //inrc 将矩阵的四个顶点加入到dp中
        auto inrc = [&](vector<int>& rect) {
            dp[hash(rect[0], rect[1])] += 1;
            dp[hash(rect[0], rect[3])] += 1;
            dp[hash(rect[2], rect[1])] += 1;
            dp[hash(rect[2], rect[3])] += 1;
        };
        //计算矩阵面积
        auto area = [](vector<int>& rect) -> int {
            return abs((rect[2] - rect[0]) * (rect[3] - rect[1]));
        };
        //这里保存最大矩阵
        vector<int> maxrect(rectangles[0]);
        inrc(rectangles[0]);
        int areas = area(rectangles[0]);  //小矩阵面积的合
        for (int i = 1; i < rectangles.size(); ++i) {
            inrc(rectangles[i]);    //统计顶点
            areas += area(rectangles[i]); //计算面积
            //更新最大矩阵
            if (maxrect[0] > rectangles[i][0])
                maxrect[0] = rectangles[i][0];
            if (maxrect[1] > rectangles[i][1])
                maxrect[1] = rectangles[i][1];
            if (maxrect[2] < rectangles[i][2])
                maxrect[2] = rectangles[i][2];
            if (maxrect[3] < rectangles[i][3])
                maxrect[3] = rectangles[i][3];
        }
        //大面积 == 小面积的合 
        if (area(maxrect) != areas)
            return false;
        //这里要将大矩形加进去 所有顶点才是偶数次
        inrc(maxrect);
        for (auto& it : dp) {
            if (it.second & 1 == 1)
                return false;   //顶点被用了基数次
        }
        return true;
    }
};

int main(int argc, char const* argv[]) {
    PerfectRectangle1 cls;
    cout << boolalpha << cls.isRectangleCover(vector<vector<int>>{ {1, 1, 3, 3}, { 3,1,4,2 }, { 3,2,4,4 }, { 1,3,2,4 }, { 2,3,3,4 }}) << " -> true" << endl;
    cout << boolalpha << cls.isRectangleCover(vector<vector<int>>{ {0, 0, 1, 1}, { 0,1,3,2 }, { 1,0,2,2 }}) << " -> false" << endl;
    cout << boolalpha << cls.isRectangleCover(vector<vector<int>>{ {1, 1, 2, 3}, { 1,3,2,4 }, { 3,1,4,2 }, { 3,2,4,4 }}) << " -> false" << endl;
    cout << boolalpha << cls.isRectangleCover(vector<vector<int>>{ {1, 1, 3, 3}, { 3,1,4,2 }, { 1,3,2,4 }, { 3,2,4,4 }}) << " -> false" << endl;
    cout << boolalpha << cls.isRectangleCover(vector<vector<int>>{ {1, 1, 3, 3}, { 3,1,4,2 }, { 1,3,2,4 }, { 2,2,4,4 }}) << " -> false" << endl;
    return 0;
}
