#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> aii;

class NextGreaterElement2
{
public:
    // 先求出最大元素
    // 再利用单调栈求解
    vector<int> nextGreaterElements(const vector<int> &nums)
    {
        int n = nums.size();
        aii m = getmax(nums, 0, n - 1);
        stack<int> st;
        vector<int> ans(n);
        ans[m.second] = -1;
        st.push(m.first);
        int i = m.second == 0 ? n - 1 : m.second - 1;
        while (i != m.second)
        {
            while (!st.empty() && nums[i] >= st.top())
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }
            st.push(nums[i]);
            --i;
            if (i < 0)
            {
                i = n - 1;
            }
        }
        return ans;
    }

private:
    aii getmax(const vector<int> &nums, int start, int end)
    {
        if (start == end)
        {
            return {nums[start], start};
        }
        int mid = (start + end) / 2;
        aii n1 = getmax(nums, start, mid);
        aii n2 = getmax(nums, mid + 1, end);
        if (n1.first > n2.first)
        {
            return n1;
        }
        return n2;
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
    NextGreaterElement2 cls;
    // [2,-1,2]
    print(cls.nextGreaterElements(vector<int>{5, 4, 3, 2, 1}));
    // [2,-1,2]
    print(cls.nextGreaterElements(vector<int>{1, 2, 1}));
    // [2,3,4,-1,4]
    print(cls.nextGreaterElements(vector<int>{1, 2, 3, 4, 3}));
    return 0;
}
