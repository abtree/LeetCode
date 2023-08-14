#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <random>
using namespace std;

//327. 区间和的个数
class CountOfRangeSum {
    /* 给你一个整数数组 nums 以及两个整数 lower 和 upper 。求数组中，值位于范围 [lower, upper] （包含 lower 和 upper）之内的 区间和的个数 。
    区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。
    */
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        //暴力统计(会超时)
        vector<long long> dp(nums.begin(), nums.end());
        int ret = 0;
        if (dp[0] >= lower && dp[0] <= upper) {
            ++ret;
        }
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] += dp[i - 1];
            if (dp[i] >= lower && dp[i] <= upper) {
                ++ret;
            }
        }
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < i;++j) {
                long long c = dp[i] - dp[j];
                if (c >= lower && c <= upper) {
                    ++ret;
                }
            }
        }
        return ret;
    }
};

class CountOfRangeSum1 {
    //归并排序
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sum{ 0 }; //注意 这里预先插入了个 0
        for (int v : nums) {
            sum.push_back(sum.back() + v);
        }
        return countRangeSumRecursive(sum, lower, upper, 0, sum.size() - 1);
    }
private:
    int countRangeSumRecursive(vector<long long>& sum, int lower, int upper, int left, int right) {
        if (left == right)
            return 0;
        int mid = (left + right) / 2;
        int ret = countRangeSumRecursive(sum, lower, upper, left, mid);
        ret += countRangeSumRecursive(sum, lower, upper, mid + 1, right);
        //统计下标对的数量(每次递归只统计排序后的部分)
        // 注意：这里是分段有序的, left..mid有序, mid+1..right有序(因为我们是求每一个 j-i，所以j和i的顺序并不重要，所以j和i分别可以排序)
        int i = left;   //注意 由于我们在递归中 已经统计了 left..mid 和 mid+1..right 满足条件的数量
        int l = mid + 1;    //这里只需要统计 left <= i <= mid && mid + 1 <= l <= r <= right
        int r = mid + 1;    // 即跨区间的部分
        while (i <= mid) {
            // sum[l]-sum[i] 表示从i..l的区间和
            // 由于已经排序， 如果区间和小于lower 只需要将l右移，区间和就会增大
            while (l <= right && sum[l] - sum[i] < lower) ++l;
            // sum[r]-sum[i] 表示i..r的区间和
            // 由于已经排序， 如果区间和小于upper 只需要将r右移，区间和就会增大
            while (r <= right && sum[r] - sum[i] <= upper) ++r;
            // 我们已经找到了 l..r的一个满足条件的窗口
            // 即 i..l, i..l+1, ..., i..r 都是满足条件的 
            // 一共有 r - l 个满足条件的情况
            ret += (r - l);
            // 这里将 i 右移，并重新计算 l 和 r
            ++i;
        }
        //随后合并两个排序数组(这里是对left..right这部分区间排序)
        vector<long long> sorted(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        while (p1 <= mid || p2 <= right) {
            if (p1 > mid) {
                sorted[p++] = sum[p2++];
            }
            else if (p2 > right) {
                sorted[p++] = sum[p1++];
            }
            else {
                if (sum[p1] < sum[p2]) {
                    sorted[p++] = sum[p1++];
                }
                else {
                    sorted[p++] = sum[p2++];
                }
            }
        }
        //将排序后的部分写回sum数组对应的部分
        for (int i = 0; i < sorted.size(); ++i) {
            sum[left + i] = sorted[i];
        }
        return ret;
    }
};

class CountOfRangeSum2 {
    /* 线段树
        lower <= sum(i, j) <= upper
        sum(i, j) = preSum(j) - preSum(i-1)
        => preSum(i-1) <= preSum[j] - lower
           preSum(i-1) >= preSum[j] - upper
        由于经过了排序
        => index[preSum(i-1)] <= index(preSum[j] - lower)
           index[preSum(i-1)] >= index(preSum[j] - upper)
    */
private:
    struct SegNode {
        int lo{};   //区间下限
        int hi{};   //区间上限
        int add{};  //区间内满足条件的数量(即为已经插入的preSum[i]的数量)
        SegNode* lchild{};  //左子区间 lo..mid
        SegNode* rchild{};  //右子区间 mid+1..hi
        SegNode(int left, int right) :lo(left), hi(right) {}
    };
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sum{ 0 };
        for (int v : nums) {
            sum.push_back(sum.back() + v);
        }

        set<long long> allNumbers;
        for (auto x : sum) {
            allNumbers.insert(x);
            allNumbers.insert(x - lower);
            allNumbers.insert(x - upper);
        }

        //利用哈希表离散化
        unordered_map<long long, int> values;
        int idx = 0;
        for (auto x : allNumbers) {
            values[x] = idx++;
        }

        SegNode* root = build(0, values.size() - 1);
        int ret = 0;
        for (auto x : sum) {
            int left = values[x - upper], right = values[x - lower];
            ret += count(root, left, right);
            insert(root, values[x]);
        }

        return ret;
    }
private:
    //构建平衡二叉树
    SegNode* build(int left, int right) {
        SegNode* node = new SegNode(left, right);
        if (left == right) {
            return node;
        }
        int mid = (left + right) / 2;
        node->lchild = build(left, mid);
        node->rchild = build(mid + 1, right);
        return node;
    }
    //这里insert其实是插入i（假如插入了i1,i2,i3）
    //在下次count时(假如此时为j)，就计算了 lower <= sum(j-i1) <= upper, lower <= sum(j-i2) <= upper, lower <= sum(j-i3) <= upper
    void insert(SegNode* root, int val) {
        root->add++;    //这里表示preSum[i]落在该区间
        if (root->lo == root->hi) {
            return;
        }
        int mid = (root->lo + root->hi) / 2;
        if (val <= mid) {
            insert(root->lchild, val);
        }
        else {
            insert(root->rchild, val);
        }
    }
    //统计当前位置j的元素 与以插入元素 i1,i2,... 满足 lower <= sum(i,j) <= upper的个数
    int count(SegNode* root, int left, int right) const {
        /* 这里 index 对应的值的大小
            preSum[i] - upper <= preSum[j] <= preSum[i] - lower
            => lower <= preSum[j] - preSum[i] <= upper    (即为满足条件的结果)
        */
        if (left > root->hi || right < root->lo) {
            return 0;
        }
        if (left <= root->lo && root->hi <= right) {
            return root->add;   //这里的add即为preSum[i]的个数，即 preSum[j]-preSum[i]满足条件的个数
        }
        return count(root->lchild, left, right) + count(root->rchild, left, right);
    }
};

class CountOfRangeSum3 {
    // 动态增加节点的线段树(其实就是上面算法 不用index 替代preSum[i]值，而直接用值)
private:
    struct SegNode {
        long long lo{}; //区间内最小值
        long long hi{}; //区间内最大值
        int add{};  //区间i的个数
        SegNode* lchild{};  //lo..mid
        SegNode* rchild{};  //mid+1..hi
        SegNode(long long left, long long right) :lo(left), hi(right) {}
    };
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sum{ 0 };
        for (int v : nums) {
            sum.push_back(sum.back() + v);
        }

        long long lbound = LLONG_MAX, rbound = LLONG_MIN;
        for (auto x : sum) {
            lbound = min({ lbound, x, x - lower, x - upper });
            rbound = max({ rbound, x, x - lower, x - upper });
        }

        SegNode* root = new SegNode(lbound, rbound);
        int ret = 0;
        for (auto x : sum) {
            ret += count(root, x - upper, x - lower);
            insert(root, x);
        }
        return ret;
    }
private:
    void insert(SegNode* root, long long val) {
        root->add++;
        if (root->lo == root->hi)
            return;
        long long mid = (root->lo + root->hi) >> 1;
        if (val <= mid) {
            if (!root->lchild) {
                root->lchild = new SegNode(root->lo, mid);
            }
            insert(root->lchild, val);
        }
        else {
            if (!root->rchild) {
                root->rchild = new SegNode(mid + 1, root->hi);
            }
            insert(root->rchild, val);
        }
    }
    int count(SegNode* root, long long left, long long right) const {
        if (!root)
            return 0;
        if (left > root->hi || right < root->lo)
            return 0;
        if (left <= root->lo && root->hi <= right)
            return root->add;
        return count(root->lchild, left, right) + count(root->rchild, left, right);
    }
};

class CountOfRangeSum4 {
    // 树化数组
private:
    class BIT {
    private:
        vector<int> tree;
    public:
        BIT(int n) :tree(n + 1) {}
        static constexpr int lowbit(int x) {
            return x & (-x);
        }
        void update(int x, int d) {
            while (x < tree.size()) {
                tree[x] += d;
                x += lowbit(x);
            }
        }
        int query(int x) const {
            int ans = 0;
            while (x) {
                ans += tree[x];
                x -= lowbit(x);
            }
            return ans;
        }
    };
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sum{ 0 };
        for (int v : nums) {
            sum.push_back(sum.back() + v);
        }

        set<long long> allNumbers;
        for (auto x : sum) {
            allNumbers.insert(x);
            allNumbers.insert(x - lower);
            allNumbers.insert(x - upper);
        }

        //利用哈希表离散化
        unordered_map<long long, int> values;
        int idx = 0;
        for (auto x : allNumbers) {
            values[x] = idx++;
        }

        int ret = 0;
        BIT bit(values.size());
        for (int i = 0; i < sum.size(); ++i) {
            int left = values[sum[i] - upper], right = values[sum[i] - lower];
            ret += bit.query(right + 1) - bit.query(left);
            bit.update(values[sum[i]] + 1, 1);
        }
        return ret;
    }
};

class CountOfRangeSum5 {
    //平衡二叉搜索树
private:
    struct BalancedNode {
        long long val{};
        long long seed{};
        int count{ 1 };
        int size{ 1 };
        BalancedNode* left{};
        BalancedNode* right{};
        BalancedNode(long long _val, long long _seed) :val(_val), seed(_seed) {}
        BalancedNode* leftRotate() {
            int prev_size = size;
            int curr_size = (left ? left->size : 0) + (right->left ? right->left->size : 0) + count;
            BalancedNode* root = right;
            right = root->left;
            root->left = this;
            root->size = prev_size;
            size = curr_size;
            return root;
        }
        BalancedNode* rightRotate() {
            int prev_size = size;
            int curr_size = (right ? right->size : 0) + (left->right ? left->right->size : 0) + count;
            BalancedNode* root = left;
            left = root->right;
            root->right = this;
            root->size = prev_size;
            size = curr_size;
            return root;
        }
    };
    class BalancedTree {
    public:
        BalancedTree() :gen(random_device{}()), dis(LLONG_MIN, LLONG_MAX) {}
        long long getSize() const {
            return size;
        }
        void insert(long long x) {
            ++size;
            root = insert(root, x);
        }
        long long lowerBound(long long x) const {
            BalancedNode* node = root;
            long long ans = LLONG_MAX;
            while (node) {
                if (x == node->val) {
                    return x;
                }
                if (x < node->val) {
                    ans = node->val;
                    node = node->left;
                }
                else {
                    node = node->right;
                }
            }
            return ans;
        }
        long long upperBound(long long x) const {
            BalancedNode* node = root;
            long long ans = LLONG_MAX;
            while (node) {
                if (x < node->val) {
                    ans = node->val;
                    node = node->left;
                }
                else {
                    node = node->right;
                }
            }
            return ans;
        }
        pair<int, int> rank(long long x) const {
            BalancedNode* node = root;
            int ans = 0;
            while (node) {
                if (x < node->val) {
                    node = node->left;
                }
                else {
                    ans += (node->left ? node->left->size : 0) + node->count;
                    if (x == node->val) {
                        return { ans - node->count + 1, ans };
                    }
                    node = node->right;
                }
            }
            return { INT_MIN, INT_MAX };
        }
    private:
        BalancedNode* insert(BalancedNode* node, long long x) {
            if (!node) {
                return new BalancedNode(x, dis(gen));
            }
            ++node->size;
            if (x < node->val) {
                node->left = insert(node->left, x);
                if (node->left->seed > node->seed) {
                    node = node->rightRotate();
                }
            }
            else if (x > node->val) {
                node->right = insert(node->right, x);
                if (node->right->seed > node->seed) {
                    node = node->leftRotate();
                }
            }
            else {
                ++node->count;
            }
            return node;
        }
    private:
        BalancedNode* root{};
        int size{};
        mt19937 gen{};
        uniform_int_distribution<long long> dis{};
    };
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sum{ 0 };
        for (int v : nums) {
            sum.push_back(sum.back() + v);
        }

        BalancedTree* treap = new BalancedTree();
        int ret = 0;
        for (auto x : sum) {
            long long numleft = treap->lowerBound(x - upper);
            int rankLeft = (numleft == LLONG_MAX ? treap->getSize() + 1 : treap->rank(numleft).first);
            long long numRight = treap->upperBound(x - lower);
            int rankRight = (numRight == LLONG_MAX ? treap->getSize() : treap->rank(numRight).first - 1);
            ret += (rankRight - rankLeft + 1);
            treap->insert(x);
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    CountOfRangeSum5 cls;
    cout << cls.countRangeSum(vector<int>{INT_MIN, 0, INT_MIN, INT_MAX}, -564, 3864) << " -> 3" << endl;
    cout << cls.countRangeSum(vector<int>{INT_MAX, INT_MIN, -1, 0}, -1, 0) << " -> 4" << endl;
    cout << cls.countRangeSum(vector<int>{-2, 5, -1}, -2, 2) << " -> 3" << endl;
    cout << cls.countRangeSum(vector<int>{0}, 0, 0) << " -> 1" << endl;
    cout << cls.countRangeSum(vector<int>{-2, 5, 6, -1}, -2, 2) << " -> 2" << endl;
    return 0;
}
