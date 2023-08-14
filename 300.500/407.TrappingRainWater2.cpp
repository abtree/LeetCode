#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> pii;

class TrappingRainWater2{
public:
    int trapRainWater1(vector<vector<int>>& heightMap) {
        /* 最小堆 从最低的边沿开始扩散
        */
        if (heightMap.size() < 3 || heightMap[0].size() < 3)
            return 0;   //要想接的住水，行列都至少需要3行
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;  //优先队用于找出边界中最小元素
        vector<vector<bool>> visited(m, vector<bool>(n, false));    //标记哪些位置已经访问过
        //将边界加入队列
        for (int j = 0; j < n;++j) {
            pq.push({ heightMap[0][j], j });
            visited[0][j] = true;
        }
        for (int j = 0; j < n;++j) {
            pq.push({ heightMap[m-1][j], (m-1)*n+j });
            visited[m-1][j] = true;
        }
        for (int i = 1; i < m - 1;++i) {
            pq.push({ heightMap[i][0], i*n });
            visited[i][0] = true;
        }
        for (int i = 1; i < m - 1;++i) {
            pq.push({ heightMap[i][n-1], i*n+n-1 });
            visited[i][n-1] = true;
        }
        //返回结果
        int res = 0;
        //四个方向:左下右上 => (x-1,y),(x, y+1),(x+1,y),(x,y-1)
        int dirs[] = { -1, 0, 1, 0, -1 };
        while (!pq.empty())
        {
            //取出边界中最矮的点
            pii curr = pq.top();
            //我们将这个点剔除队列，因为我们取这个点周围的四个点，这四个点会堵上这个点
            pq.pop();
            //取出当前最小点周围的四个点，目的是堵住这个点
            for (int k = 0; k < 4; ++k) {
                int nx = curr.second / n + dirs[k];
                int ny = curr.second % n + dirs[k + 1];
                //防止越界
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    if (heightMap[nx][ny] < curr.first) {
                        //取出的点比当前点低，可以装水
                        res += curr.first - heightMap[nx][ny];
                    }
                    visited[nx][ny] = true;
                    //这里的高度为两者中高的，如果新点比老点低 装水 并且依然以老点为界，否则以新点为界，不能装水
                    pq.push({ max(heightMap[nx][ny], curr.first), nx * n + ny });
                }
            }
        }
        
        return res;
    }
public:
    int trapRainWater2(vector<vector<int>>& heightMap) {
        /* 广度优先遍历
        */
        if (heightMap.size() < 3 || heightMap[0].size() < 3)
            return 0;   //要想接的住水，行列都至少需要3行
        int m = heightMap.size();
        int n = heightMap[0].size();
        //四个方向:左下右上 => (x-1,y),(x, y+1),(x+1,y),(x,y-1)
        int dirs[] = { -1, 0, 1, 0, -1 };
        //找出最大高度
        int maxHeight = 0;
        for (int i = 0; i < m; ++i) {
            maxHeight = max(maxHeight, *max_element(heightMap[i].begin(), heightMap[i].end()));
        }
        //先初始 每个格子都能接水到maxHeight高
        vector<vector<int>> water(m, vector<int>(n, maxHeight));
        //queue中存放调整过的点 这些点会触发其周围的点的调整
        queue<pii> qu;
        //将边界加入队列(边界是不能接水的)
        for (int j = 0; j < n;++j) {
            if (water[0][j] > heightMap[0][j]) {
                water[0][j] = heightMap[0][j];
                qu.push({ 0, j });
            }
        }
        for (int j = 0; j < n;++j) {
            if (water[m - 1][j] > heightMap[m - 1][j]) {
                water[m - 1][j] = heightMap[m - 1][j];
                qu.push({ m - 1, j });
            }
        }
        for (int i = 1; i < m - 1;++i) {
            if (water[i][0] > heightMap[i][0]) {
                water[i][0] = heightMap[i][0];
                qu.push({ i, 0 });
            }
        }
        for (int i = 1; i < m - 1;++i) {
            if (water[i][n - 1] > heightMap[i][n - 1]) {
                water[i][n - 1] = heightMap[i][n - 1];
                qu.push({ i, n - 1 });
            }
        }
        //调整周围的点
        while (!qu.empty()) {
            int x = qu.front().first, y = qu.front().second;
            qu.pop();
            //调整周围的点
            for (int i = 0; i < 4;++i) {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;   //越界
                }
                //如果当前点比旁边点要高 且 当前点大于他实际高度 说明水溢出了 需要调整当前点高度
                if (water[x][y] < water[nx][ny] && water[nx][ny] > heightMap[nx][ny]) {
                    water[nx][ny] = max(water[x][y], heightMap[nx][ny]);
                    qu.push({ nx, ny });
                }
            }
        }
        //计算水位
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //这里water一定高于heightMap
                res += water[i][j] - heightMap[i][j];
            }
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    TrappingRainWater2 cls;
    cout << cls.trapRainWater1(vector<vector<int>>{ {1, 4, 3, 1, 3, 2}, { 3,2,1,3,2,4 }, { 2,3,3,2,3,1 }}) << " -> 4" << endl;
    cout << cls.trapRainWater1(vector<vector<int>>{ {3, 3, 3, 3, 3}, { 3,2,2,2,3 }, { 3,2,1,2,3 }, { 3,2,2,2,3 }, { 3,3,3,3,3 }}) << " -> 10" << endl;
    cout << cls.trapRainWater2(vector<vector<int>>{ {1, 4, 3, 1, 3, 2}, { 3,2,1,3,2,4 }, { 2,3,3,2,3,1 }}) << " -> 4" << endl;
    cout << cls.trapRainWater2(vector<vector<int>>{ {3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}}) << " -> 10" << endl;
    return 0;
}
