#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int val{};
    int index{};
};


class ContainsDuplicate3 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        vector<Node> tmp(n);
        for (int i = 0; i < n; ++i) {
            tmp[i].val = nums[i];
            tmp[i].index = i;
        }
        sort(tmp.begin(), tmp.end(), [](const Node& a, const Node& b) {
            return a.val < b.val;
            });
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((long long)tmp[j].val - (long long)tmp[i].val > (long long)t)
                    break;
                if (abs(tmp[j].index - tmp[i].index) <= k)
                    return true;
            }
        }
        return false;
    }
public:
    int getID(int x, long w) {
        return x < 0 ? (x + 1ll) / w - 1 : x / w;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //分桶法 将k(0, t)分到一个组 则组内必定满足要求 相邻组需要判断
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long x = nums[i];
            int id = getID(x, t + 1ll);
            if (mp.count(id)) { //同一组
                return true;
            }
            if (mp.count(id - 1) && abs(x - mp[id - 1]) <= t) { //向上的相邻组
                return true;
            }
            if (mp.count(id + 1) && abs(x - mp[id + 1]) <= t) { //向下的相邻组
                return true;
            }
            mp[id] = x; //这里不存在替换 因为替换就return true了
            if (i >= k) {   //删除i-k的元素 因为距离已经不满足要求
                mp.erase(getID(nums[i - k], t + 1ll));
            }
        }
        return false;
    }
};

int main(int argc, char const* argv[])
{
    ContainsDuplicate3 cls;
    cout << boolalpha << cls.containsNearbyAlmostDuplicate(vector<int>{INT_MIN, INT_MAX}, 1, 1) << " -> false" << endl;
    cout << boolalpha << cls.containsNearbyAlmostDuplicate(vector<int>{1, 2, 1, 1}, 1, 0) << " -> true" << endl;
    cout << boolalpha << cls.containsNearbyAlmostDuplicate(vector<int>{1, 2, 3, 1}, 3, 0) << " -> true" << endl;
    cout << boolalpha << cls.containsNearbyAlmostDuplicate(vector<int>{1, 0, 1, 1}, 1, 2) << " -> true" << endl;
    cout << boolalpha << cls.containsNearbyAlmostDuplicate(vector<int>{1, 5, 9, 1, 5, 9}, 2, 3) << " -> false" << endl;
    return 0;
}
