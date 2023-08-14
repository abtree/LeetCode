#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class ThirdMaximumNumber{
public:
    int thirdMax(vector<int>& nums) {
        //贪心算法
        vector<int> dp; //存储由大到小元素
        unordered_set<int> repeated;    //去重
        for (int x : nums) {
            //重复判断
            if (repeated.count(x) > 0)
                continue;
            repeated.insert(x);
            //队列为空 直接加入
            if (dp.empty()) {
                dp.push_back(x);
                continue;
            }
            //元素比队列最小元素还小，如果队列未满3个原始 加入该元素 否则 忽略该元素
            if (x < dp.back()) {
                if (dp.size() < 3)
                    dp.push_back(x);
                continue;
            }
            //如果队列未满三个元素 加入该元素 否则该元素替换最后一个元素
            if (dp.size() < 3) {
                dp.push_back(x);
            }
            else {
                dp.back() = x;
            }
            //将加入的元素调到合适的位置
            for (int i = dp.size() - 1; i > 0; --i) {
                if (dp[i] > dp[i - 1]) {
                    swap(dp[i], dp[i - 1]);
                }
                else {
                    break;
                }
            }
        }
        //队列小于3 取最大元素
        if (dp.size() < 3)
            return dp[0];
        return dp.back();   //取第三大元素
    }
public:
    int thirdMax1(vector<int>& nums) {
        //set排序去重
        set<int> dp;
        for (int x : nums) {
            dp.insert(x);
        }
        if (dp.size() < 3) {
            return *dp.rbegin();
        }
        else {
            auto it = dp.rbegin();
            advance(it, 2);
            return *it;
        }
    }
public:
    int thirdMax2(vector<int>& nums) {
        int* a = nullptr;
        int* b = nullptr;
        int* c = nullptr;
        for (auto &x : nums) {
            if (!a || x > *a){
                c = b;
                b = a;
                a = &x;
            }
            else if (x < *a && (!b || x > *b)) {
                c = b;
                b = &x;
            }
            else if (b && x < *b && (!c || x > *c)) {
                c = &x;
            }
        }
        return c ? *c : *a;
    }
};

int main(int argc, char const* argv[]) {
    ThirdMaximumNumber cls;
    cout << cls.thirdMax2(vector<int>{1,2,2,5,3,5}) << " -> 2" << endl;
    cout << cls.thirdMax2(vector<int>{3, 2, 1}) << " -> 1" << endl;
    cout << cls.thirdMax2(vector<int>{1,2}) << " -> 2" << endl;
    cout << cls.thirdMax2(vector<int>{2,2,3,1}) << " -> 1" << endl;
    return 0;
}
