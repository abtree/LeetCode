#pragma once

//62. 不同路径
class UniquePaths {
    /*
    一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
    机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
    问总共有多少条不同的路径？

    示例 1：
    输入：m = 3, n = 7
    输出：28

    示例 2：
    输入：m = 3, n = 2
    输出：3
    解释：
    从左上角开始，总共有 3 条路径可以到达右下角。
    1. 向右 -> 向右 -> 向下
    2. 向右 -> 向下 -> 向右
    3. 向下 -> 向右 -> 向右
    */
public:
    int uniquePaths(int m, int n) {
        /*
            由于只能 向右 或 向下 移动 (这点很重要)
            以 3， 7 为例
            我们总共需要向下移动 3-1=2 步
            我们总共需要向右移动 7-1=6 步

            由于在排列中 向下与向下，向右与向右为相同元素 位置无关
            我们可以这样理解:
            在向下移动的6步中 有7个位置可以插入第一次的向下
            之后有8个位置可以插入第二个向下，但由于向下两个在一起时与位置无关，所以结果要除以2
            如果需要插入第3个，就有9个位置可以插入，最后结果需要除以3
        */
        if (m > n) {
            swap(m, n);
        }
        if (m == 1)
            return 1;
        unsigned long long ret = 1;
        for (int i = 1; i < m; ++i) {
            ret = ret * n / i;
            ++n;
        }
        return (int)ret;
    }
public:
    int uniquePaths2(int m, int n) {
        /*
        动态规划
        我们用f(i, j)表示从左上角走到(i, j)的路径数量，其中i和j的范围分别是[0, m)和[0, n)。
        由于我们每一步只能从向下或者向右移动一步，因此要想走到(i,j)，如果向下走一步，那么会从(i-1, j)走过来；如果向右走一步，那么会从(i,j−1)走过来。因此我们可以写出动态规划转移方程：
        f(i, j) = f(i-1, j) + f(i, j-1)
        需要注意的是，如果 i=0，那么 f(i-1,j)并不是一个满足要求的状态，我们需要忽略这一项；同理，如果 j=0，那么 f(i,j-1)并不是一个满足要求的状态，我们需要忽略这一项。
        初始条件为 f(0,0)=1，即从左上角走到左上角有一种方法。
        最终的答案即为 f(m-1,n-1)。
        */
        vector<vector<int>> f(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            f[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            f[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
public:
    static void Test() {
        UniquePaths cls;
        cout << cls.uniquePaths2(3, 7) << " -> 28" << endl;
        cout << cls.uniquePaths2(3, 2) << " -> 3" << endl;
        cout << cls.uniquePaths2(3, 3) << " -> 6" << endl;
        cout << cls.uniquePaths2(51, 9) << " -> 1916797311" << endl;
    }
};