#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/* 该对象维护两个队列
    small中所有元素小于large
    small队列元素按从小到大排列，队顶元素最大
    large队列元素按从大到小排列，队顶元素最小
    删除元素时不采用实时删除，而是当元素到大队顶时删除
    当元素不能立即删除时标记元素
    large和small的有效长度，要么相等，要么smallSize = largeSize + 1
*/
class DualHeap
{
public:
    DualHeap(int _k) : k(_k) {}

public:
    // 插入元素
    void insert(int num)
    {
        if (small.empty() || num <= small.top())
        {
            small.push(num);
            ++smallSize;
        }
        else
        {
            large.push(num);
            ++largeSize;
        }
        makeBalance();
    }
    // 删除元素
    void erase(int num)
    {
        ++delayed[num];
        if (num <= small.top())
        {
            --smallSize;
            if (num == small.top())
            {
                prune(small);
            }
        }
        else
        {
            --largeSize;
            if (num == large.top())
            {
                prune(large);
            }
        }
        makeBalance();
    }
    // 获取中位元素
    double getMedian()
    {
        if (k & 1)
        {
            // 基数长度
            return small.top();
        }
        else
        {
            // 偶数长度
            return ((double)small.top() + large.top()) / 2;
        }
    }

private:
    // 调节 small和large，使它们的长度满足需求
    void makeBalance()
    {
        if (smallSize > largeSize + 1)
        {
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            prune(small);
        }
        else if (smallSize < largeSize)
        {
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            prune(large);
        }
    }
    // 从优先队列移除元素，需要考虑再平衡
    template <typename T>
    void prune(T &heap)
    {
        while (!heap.empty())
        {
            int num = heap.top();
            if (delayed.count(num))
            {
                --delayed[num];
                if (!delayed[num])
                {
                    delayed.erase(num);
                }
                heap.pop();
            }
            else
            {
                break;
            }
        }
    }

private:
    // small优先队列，元素按从小到大排列，队顶元素最大
    priority_queue<int> small{};
    // large优先队列，元素按从大到小排列，队顶元素最小
    priority_queue<int, vector<int>, greater<int>> large{};
    // 记录延迟删除元素的hash表
    unordered_map<int, int> delayed{};

    // 窗口大小
    int k{};
    // small队列有效长度
    int smallSize{};
    // large队列有效长度
    int largeSize{};
};

class SlidingWindowMedian
{
public:
    vector<double> medianSlidingWindow(vector<int> nums, int k)
    {
        DualHeap dh(k);
        for (int i = 0; i < k; ++i)
        {
            dh.insert(nums[i]);
        }
        vector<double> ans(nums.size() - k + 1);
        ans[0] = dh.getMedian();
        for (int i = k; i < nums.size(); ++i)
        {
            dh.insert(nums[i]);
            dh.erase(nums[i - k]);
            ans[i - k + 1] = dh.getMedian();
        }
        return ans;
    }
};

void Print(vector<double> ret)
{
    cout << "[";
    for (auto c : ret)
    {
        cout << c << " , ";
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    SlidingWindowMedian cls;
    // [1,-1,-1,3,5,6]
    Print(cls.medianSlidingWindow(vector<int>{1, 3, -1, -3, 5, 3, 6, 7}, 3));
    // [2,3,3,3,2,3,2]
    Print(cls.medianSlidingWindow(vector<int>{1, 2, 3, 4, 2, 3, 1, 4, 2}, 3));
    return 0;
}
