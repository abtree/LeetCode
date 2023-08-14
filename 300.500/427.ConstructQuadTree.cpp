#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class ConstructQuadTree{
public:
    Node* construct(vector<vector<int>>& grid) {
        function<Node* (int, int, int, int)> dfs = [&](int r0, int c0, int r1, int c1) -> Node* {
            //判断这个区间内是不是全是相同的值
            for (int i = r0;i < r1;++i) {
                for (int j = c0; j < c1;++j) {
                    if (grid[i][j] != grid[r0][c0]) {
                        //如果不是，将区间分成4个区域，再分别判断
                        return new Node(
                            true, false,
                            dfs(r0, c0, (r0 + r1) / 2, (c0 + c1) / 2),
                            dfs(r0, (c0 + c1) / 2, (r0 + r1) / 2, c1),
                            dfs((r0 + r1) / 2, c0, r1, (c0 + c1) / 2),
                            dfs((r0 + r1) / 2, (c0 + c1) / 2, r1, c1)
                        );
                    }
                }
            }
            //如果 是 该区间为叶子节点
            return new Node(grid[r0][c0], true);
        };
        return dfs(0, 0, grid.size(), grid.size());
    }
public:
    Node* construct1(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> pre(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }

        auto getSum = [&](int r0, int c0, int r1, int c1) {
            return pre[r1][c1] - pre[r1][c0] - pre[r0][c1] + pre[r0][c0];
        };

        function<Node *(int, int, int, int)> dfs = [&](int r0, int c0, int r1, int c1) {
            int total = getSum(r0, c0, r1, c1);
            if (total == 0) {
                return new Node(false, true);
            }
            if (total == (r1 - r0) * (c1 - c0)) {
                return new Node(true, true);
            }
            return new Node(
                    true,
                    false,
                    dfs(r0, c0, (r0 + r1) / 2, (c0 + c1) / 2),
                    dfs(r0, (c0 + c1) / 2, (r0 + r1) / 2, c1),
                    dfs((r0 + r1) / 2, c0, r1, (c0 + c1) / 2),
                    dfs((r0 + r1) / 2, (c0 + c1) / 2, r1, c1)
            );
        };

        return dfs(0, 0, n, n);
    }
};

void Print(Node* root) {
    cout << "[";
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0;i < size;++i) {
            auto* c = q.front();
            cout << "[" << c->isLeaf << "," << c->val << "]";
            q.pop();
            if (c->topLeft)
                q.push(c->topLeft);
            if (c->topRight)
                q.push(c->topRight);
            if (c->bottomLeft)
                q.push(c->bottomLeft);
            if (c->bottomRight)
                q.push(c->bottomRight);
        }
    }
    
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    ConstructQuadTree cls;
    Node* ret = cls.construct1(vector<vector<int>>{ {1, 1}, { 1,1 }});
    Print(ret);
    ret = cls.construct1(vector<vector<int>>{ {0}});
    Print(ret);
    ret = cls.construct1(vector<vector<int>>{ {1, 1, 0, 0}, { 1,1,0,0 }, { 0,0,1,1 }, { 0,0,1,1 }});
    Print(ret);
    ret = cls.construct1(vector<vector<int>>{ {1, 1, 1, 1, 0, 0, 0, 0}, { 1,1,1,1,0,0,0,0 }, { 1,1,1,1,1,1,1,1 }, { 1,1,1,1,1,1,1,1 }, { 1,1,1,1,0,0,0,0 }, { 1,1,1,1,0,0,0,0 }, { 1,1,1,1,0,0,0,0 }, { 1,1,1,1,0,0,0,0 }});
    Print(ret);
    return 0;
}
