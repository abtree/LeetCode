#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

typedef pair<int, int> param2;

//315. 计算右侧小于当前元素的个数
class CountOfSmallerNumberAfterSelf {
    /* 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
    */
public:
    vector<int> countSmaller(vector<int>& nums) {
        //用map实现的优先队（会超时）
        map<int, pair<int, int>> tmp;
        int n = nums.size();
        vector<int> ret(n, 0); 
        tmp[nums.back()] = make_pair(0,0);  //first:小于他的数的个数 second:等于他的数的个数
        for(int i = n-2; i >= 0; --i){
            auto it = tmp.rbegin();
            for(; it != tmp.rend(); ++it){
                if(it->first > nums[i]){
                    it->second.first+=1;    //小于他的数增加一个，即nums[i]
                    continue;
                }else if(it->first == nums[i]){
                    it->second.second += 1; //等于于他的数增加一个，即nums[i]
                    ret[i] = it->second.first;
                }else{
                    ret[i] = it->second.first + it->second.second+1;
                    tmp[nums[i]] = make_pair(ret[i], 0);
                }
                break;
            }
            if(it == tmp.rend()){
                tmp[nums[i]] = make_pair(ret[i], 0);
            }
        }
        return ret;
    } 
public:
    vector<int> countSmaller1(vector<int>& nums) {
        //用数组代替map提高性能
        vector<param2> tmp(nums.size());
        Init(nums, tmp);
        vector<int> ret(nums.size(), 0);
        for(int i = nums.size()-1; i >= 0; --i){
            int sum = 0;
            for(auto &it : tmp){
                if(it.first < nums[i]){
                    sum += it.second;
                }else{
                    it.second+=1;
                    break;
                }
            }
            ret[i] = sum;
        }
        return ret;
    }
private:
    void Init(vector<int>& nums, vector<param2>& back){
        for(int i = 0; i< nums.size(); ++i){
            back[i].first = nums[i];
        }
        sort(back.begin(), back.end(), [](const param2& a, const param2& b) -> bool {
            return a.first < b.first;
        });
        auto end = unique(back.begin(), back.end(), [](const param2& a, const param2& b) -> bool {
            return a.first == b.first;
        });
        back.resize(distance(back.begin(), end));
    }
public:
    vector<int> countSmaller2(vector<int>& nums) {
        /* 通过树状数组提高效率(树状数组其实是一个平衡二叉树)
           树状数组的特点:
           假如原数组 A[8] 有八个元素
           则映射到树状数组C[8]满足
                C[1] = A[1]
                C[2] = A[1] + A[2]
                C[3] = A[3]
                C[4] = C[2] + A[3] + A[4]
                C[5] = A[5]
                C[6] = A[5] + A[6]
                C[7] = A[7]
                C[8] = C[4] + C[6] + A[7] + A[8]
            此时我们求： 小于 A[2] = C[1]
                         小于 A[3] = C[2]
                         小于 A[4] = C[2]+C[3]
                         小于 A[5] = C[4]
                         小于 A[6] = C[4] + C[5]
                         小于 A[7] = C[4] + C[6]
                         小于 A[8] = C[7] + C[6] + C[4]
            更新时: 更新 A[1] -> C[1], C[2], C[4], C[8]
                    更新 A[2] -> C[2], C[4], C[8]
                    更新 A[3] -> C[3], C[4], C[8]
                    更新 A[4] -> C[4], C[8]
                    更新 A[5] -> C[5], C[6], C[8]
                    更新 A[6] -> C[6], C[8]
                    更新 A[7] -> C[7], C[8]
                    更新 A[8] -> C[8]
            从上面的列表可以看出：树状数组可以通过位运算来更新和求解
        */
        vector<int> ret(nums.size());
        vector<int> a, c;
        //排序并去重
        a.assign(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        
        c.resize(nums.size() + 1, 0);
        for(int i = nums.size()-1; i>= 0; --i){
            int id = distance(a.begin(), lower_bound(a.begin(), a.end(), nums[i])) + 1;
            //query result
            int sum = 0;
            int pos = id-1;
            while(pos > 0){
                sum+=c[pos];
                pos-=(pos&(-pos));
            }
            ret[i] = sum;
            //update
            while(id < c.size()){
                c[id] += 1;
                id += (id&(-id));
            }
        }
        return ret;
    }
public:
    vector<int> countSmaller3(vector<int>& nums) {
        //分治(归并排序)
        mIndex.clear();
        mIndex.resize(nums.size());
        mTmp.clear();
        mTmp.resize(nums.size());
        mTmpIndex.clear();
        mTmpIndex.resize(nums.size());
        mAns.clear();
        mAns.resize(nums.size());
        for(int i = 0;i<nums.size(); ++i){
            mIndex[i] = i;
        }
        div(nums, 0, nums.size()-1);
        return mAns;
    }
private:
    void div(vector<int>& nums, int start, int end){
        if(start >= end)
            return;
        int mid = (start + end) >> 1;
        div(nums, start, mid);
        div(nums, mid+1, end);
        merge(nums, start, mid, end);
    }
    void merge(vector<int>& nums, int start, int mid, int end){
        int i = start, p = start, j = mid+1;
        while(i <= mid && j<= end){
            if(nums[i] <= nums[j]){
                mTmp[p] = nums[i];
                mTmpIndex[p] = mIndex[i];
                mAns[mIndex[i]] += (j-mid-1);
                ++i;
            }else{
                mTmp[p] = nums[j];
                mTmpIndex[p] = mIndex[j];
                ++j;
            }
            ++p;
        }
        while(i <= mid){
            mTmp[p] = nums[i];
            mTmpIndex[p] = mIndex[i];
            mAns[mIndex[i]] += (j-mid-1);
            ++i;
            ++p;
        }
        while(j <= end){
            mTmp[p] = nums[j];
            mTmpIndex[p] = mIndex[j];
            ++j;
            ++p;
        }
        for(int k = start; k <= end;++k){
            mIndex[k] = mTmpIndex[k];
            nums[k] = mTmp[k];
        }
    }
private:
    vector<int> mIndex;
    vector<int> mTmp;
    vector<int> mTmpIndex;
    vector<int> mAns;
};

int main(int argc, char const *argv[]){
    CountOfSmallerNumberAfterSelf cls;

    auto& ret3 = cls.countSmaller3(vector<int>{1,0,2});
    cout << "[";
    for(auto it : ret3){
        cout << it << ",";
    }
    cout << "]" << endl;

    auto& ret = cls.countSmaller3(vector<int>{5,2,6,1});
    cout << "[";
    for(auto it : ret){
        cout << it << ",";
    }
    cout << "]" << endl;

    auto& ret1 = cls.countSmaller3(vector<int>{2,0,1});
    cout << "[";
    for(auto it : ret1){
        cout << it << ",";
    }
    cout << "]" << endl;

    auto& ret2 = cls.countSmaller3(vector<int>{3,2,2,1,1,1});
    cout << "[";
    for(auto it : ret2){
        cout << it << ",";
    }
    cout << "]" << endl;
    return 0;
}
