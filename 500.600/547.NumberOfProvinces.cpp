#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class NumberOfProvinces
{
public:
    int findCircleNum(const vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        visited = vector<int>(n, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                dfs(isConnected, n, i);
                ++ans;
            }
        }
        return ans;
    }

    int findCircleNum1(const vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int ans = 0;
        queue<int> qu;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                qu.push(i);
                while (!qu.empty())
                {
                    int j = qu.front();
                    qu.pop();
                    visited[j] = 1;
                    for (int k = 0; k < n; ++k)
                    {
                        if (isConnected[j][k] == 1 && !visited[k])
                        {
                            qu.push(k);
                        }
                    }
                }
                ++ans;
            }
        }
        return ans;
    }

    int findCircleNum2(const vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> parent(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (isConnected[i][j] == 1)
                    Union(parent, i, j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (parent[i] == i)
                ++ans;
        }
        return ans;
    }

private:
    void dfs(const vector<vector<int>> &isConnected, int n, int i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (isConnected[i][j] == 1 && !visited[j])
            {
                visited[j] = 1;
                dfs(isConnected, n, j);
            }
        }
    }

private:
    vector<int> visited;

private:
    int Find(vector<int> &parent, int index)
    {
        if (parent[index] != index)
        {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }
    void Union(vector<int> &parent, int index1, int index2)
    {
        parent[Find(parent, index1)] = Find(parent, index2);
    }
};

int main(int argc, char const *argv[])
{
    NumberOfProvinces cls;
    cout << cls.findCircleNum2(vector<vector<int>>{{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}}) << " -> 1" << endl;
    cout << cls.findCircleNum2(vector<vector<int>>{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << " -> 2" << endl;
    cout << cls.findCircleNum2(vector<vector<int>>{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}) << " -> 3" << endl;
    return 0;
}
