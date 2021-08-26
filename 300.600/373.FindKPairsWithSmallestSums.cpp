#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//373. 查找和最小的K对数字
class FindKPairsWithSmallestSums {
    /* 给定两个以升序排列的整数数组 nums1 和 nums2 , 以及一个整数 k 。
    定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
    请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
    */
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        for (int i = 0; i < k && i < nums1.size(); ++i) {   //nums1 和 nums2 只需要最多取前k个元素就行了
            heap.push({ i, 0 });
        }
        vector<vector<int>> ret;
        while (k-- > 0 && !heap.empty()) {
            auto ids = heap.top();
            heap.pop();
            ret.push_back({ nums1[ids.first], nums2[ids.second] });
            if (ids.second < nums2.size() - 1) {
                heap.push({ ids.first, ids.second + 1 });
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    FindKPairsWithSmallestSums cls;

    auto& ret4 = cls.kSmallestPairs(vector<int>{-10, -4, 0, 0, 6}, vector<int>{3, 5, 6, 7, 8, 100}, 10);
    cout << "[";
    for (auto& it : ret4) {
        cout << "[";
        cout << it[0] << "," << it[1];
        cout << "],";
    }
    cout << "]" << endl;

    auto& ret3 = cls.kSmallestPairs(vector<int>{1, 1, 2}, vector<int>{1, 2, 3}, 10);
    cout << "[";
    for (auto& it : ret3) {
        cout << "[";
        cout << it[0] << "," << it[1];
        cout << "],";
    }
    cout << "]" << endl;

    auto& ret = cls.kSmallestPairs(vector<int>{1, 7, 11}, vector<int>{2, 4, 6}, 3);
    cout << "[";
    for (auto& it : ret) {
        cout << "[";
        cout << it[0] << "," << it[1];
        cout << "],";
    }
    cout << "]" << endl;

    auto& ret1 = cls.kSmallestPairs(vector<int>{1, 1, 2}, vector<int>{1, 2, 3}, 2);
    cout << "[";
    for (auto& it : ret1) {
        cout << "[";
        cout << it[0] << "," << it[1];
        cout << "],";
    }
    cout << "]" << endl;

    auto& ret2 = cls.kSmallestPairs(vector<int>{1, 2}, vector<int>{3}, 3);
    cout << "[";
    for (auto& it : ret2) {
        cout << "[";
        cout << it[0] << "," << it[1];
        cout << "],";
    }
    cout << "]" << endl;

    return 0;
}
