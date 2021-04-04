#pragma once

//60. 排列序列
class PermutationSequence {
    /*
    给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。
    按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
    "123"
    "132"
    "213"
    "231"
    "312"
    "321"
    给定 n 和 k，返回第 k 个排列。

    示例 1：
    输入：n = 3, k = 3
    输出："213"

    示例 2：
    输入：n = 4, k = 9
    输出："2314"

    示例 3：
    输入：n = 3, k = 1
    输出："123"
     
    提示：
    1 <= n <= 9
    1 <= k <= n!
    */
public:
    string getPermutation(int n, int k) {
        /*
        依次计算 每一位需要填入的数字
        */
        vector<int> vec(n, 0);
        vector<int> used(n, 0);
        //先算出阶乘的值
        vec[0] = 1;
        for (int i = 1; i < n; ++i) {
            vec[i] = i * vec[i - 1];
        }
        string ret(n, '0');
        //再求出每一位的值
        int p = 0;
        for (int j = 0; j < n;++j) {
            if (k > 0) {
                p = k / vec[n - j - 1];
                k = k % vec[n - j - 1];
                if (k == 0) {
                    --p;
                    k = vec[n - j - 1];
                }
            }
            else {
                p = 0;
            }
            for (int i = 0; i < n;++i) {
                if (!used[i]) {
                    if (p <= 0) {
                        ret[j] = (i + 1) + '0';
                        used[i] = 1;
                        break;
                    }
                    else {
                        --p;
                    }
                }
            }
        }
        return ret;
    }
public:
    static void Test() {
        PermutationSequence cls;
        cout << cls.getPermutation(3, 2).c_str() << " -> 132" << endl;
        cout << cls.getPermutation(3, 3).c_str() << " -> 213" << endl;
        cout << cls.getPermutation(4, 9).c_str() << " -> 2314" << endl;
        cout << cls.getPermutation(3, 1).c_str() << " -> 123" << endl;
    }
};