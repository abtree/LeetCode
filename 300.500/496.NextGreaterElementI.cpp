#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class NextGreaterElementI
{
public:
    // 先找到 nums2中每个元素和离他最近比他大的元素（向后），并构建一个hash表
    vector<int> nextGreaterElement(const vector<int> &nums1, const vector<int> &nums2)
    {
        // 存储元素和离他最近大于他的元素
        unordered_map<int, int> dp;
        // 单调栈，临时存储备选元素
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; --i)
        {
            int num = nums2[i];
            while (!st.empty() && num >= st.top())
            {
                st.pop();
            }
            dp[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        vector<int> ret(nums1.size());
        for (int i = 0; i < nums1.size(); ++i)
        {
            ret[i] = dp[nums1[i]];
        }
        return ret;
    }
};

void print(const vector<int> &ret)
{
    cout << "[";
    for (int x : ret)
    {
        cout << x << ",";
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    NextGreaterElementI cls;
    // [-1,3,-1]
    print(cls.nextGreaterElement(vector<int>{4, 1, 2}, vector<int>{1, 3, 4, 2}));
    // [3,-1]
    print(cls.nextGreaterElement(vector<int>{2, 4}, vector<int>{1, 2, 3, 4}));
    return 0;
}
