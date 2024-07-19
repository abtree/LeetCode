#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Matrix01
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<int>> seen(m, vector<int>(n, 0));
        queue<pair<int, int>> qu;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 0)
                {
                    qu.push({i, j});
                    seen[i][j] = 1;
                }
            }
        }
        while (!qu.empty())
        {
            auto cur = qu.front();
            qu.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nx = cur.first + dirs[i][0];
                int ny = cur.second + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && seen[nx][ny] == 0)
                {
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    seen[nx][ny] = 1;
                    qu.push({nx, ny});
                }
            }
        }

        return dist;
    }

private:
    int dirs[4][2]{{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

public:
    vector<vector<int>> updateMatrix1(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, m + n));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i > 0)
                {
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                }
                if (j > 0)
                {
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (i + 1 < m)
                {
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j + 1 < n)
                {
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }
        return dist;
    }
};

void print(vector<vector<int>> &mat)
{
    cout << "[";
    for (auto &m : mat)
    {
        cout << "[";
        for (auto x : m)
        {
            cout << x << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    Matrix01 cls;
    vector<vector<int>> mat{
        {0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    mat = cls.updateMatrix1(mat);
    print(mat);

    mat = vector<vector<int>>{
        {0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    mat = cls.updateMatrix1(mat);
    print(mat);
    return 0;
}
