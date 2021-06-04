#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

//239. 滑动窗口最大值
class SlidingWindowMaximum {
    /* 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。返回滑动窗口中的最大值。
    */
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int start = 0, end = min(k, int(nums.size()));
        int curr = 0, curv = nums[0];
        for(int i = 1; i < end; ++i){
            if(curv < nums[i]){
                curr = i;
                curv = nums[i];
            }
        }
        ret.push_back(curv);
        while(end < nums.size()){
            ++start;
            ++end;
            if(nums[end-1] > curv){
                curr = end-1;
                curv = nums[end-1];
                ret.push_back(curv);
                continue;
            }
            if(curr >= start){
                ret.push_back(curv);
                continue;
            }
            //需要重新计算最大值
            curv = nums[start];
            curr = start;
            for(int i = start+1; i < end; ++i){
                if(curv < nums[i]){
                    curr = i;
                    curv = nums[i];
                }
            }
            ret.push_back(curv);
        }
        return ret;
    }
public:
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        //优先队
        int n = nums.size();
        int start = 0, end = min(k, n);
        priority_queue<pair<int, int>> q;
        for(int i = 0; i < end; ++i){
            q.emplace(nums[i], i);
        }
        vector<int> ret={q.top().first};
        while (end < n){
            ++start;
            q.emplace(nums[end], end);
            ++end;
            while (q.top().second < start){
                q.pop();
            }
            ret.push_back(q.top().first);
        }
        return ret;
    }
public:
    vector<int> maxSlidingWindow3(vector<int>& nums, int k) {
        //双端队列(保证队列始终单调递减)
        int n = nums.size();
        deque<int> q;
        for(int i = 0; i< k; ++i){
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> ret = {nums[q.front()]};
        for(int i = k; i< n;++i){
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            while(q.front() <= i-k){
                q.pop_front();
            }
            ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    SlidingWindowMaximum cls;
    auto ret = cls.maxSlidingWindow3(vector<int>{1,3,-1,-3,5,3,6,7}, 3);
    cout << "[";
    for(auto it : ret){
        cout << it << ",";
    }
    cout << "]" << endl;

    auto ret1 = cls.maxSlidingWindow3(vector<int>{1}, 1);
    cout << "[";
    for(auto it : ret1){
        cout << it << ",";
    }
    cout << "]" << endl;

    auto ret2 = cls.maxSlidingWindow3(vector<int>{1, -1}, 1);
    cout << "[";
    for(auto it : ret2){
        cout << it << ",";
    }
    cout << "]" << endl;

    auto ret3 = cls.maxSlidingWindow3(vector<int>{9, 11}, 2);
    cout << "[";
    for(auto it : ret3){
        cout << it << ",";
    }
    cout << "]" << endl;

    auto ret4 = cls.maxSlidingWindow3(vector<int>{4, -2}, 2);
    cout << "[";
    for(auto it : ret4){
        cout << it << ",";
    }
    cout << "]" << endl;
    
    return 0;
}
