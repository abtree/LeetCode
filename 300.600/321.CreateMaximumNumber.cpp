#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CreateMaximumNumber
{
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret(k, 0);
        int start = max(0, int(k - nums2.size()));
        int end = min(k, int(nums1.size()));
        for (int i = start; i <= end;++i) {
            vector<int> lvec = move(maxSub(nums1, i));
            vector<int> rvec = move(maxSub(nums2, k - i));
            vector<int> merged = move(merge(lvec, rvec));
            if (contrast(merged, 0, ret, 0) > 0) {
                ret.swap(merged);
            }
        }
        return ret;
    }
private:
    vector<int> maxSub(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> ret(k, 0);
        int top = -1;
        int remain = size - k;  //控制剩余数量能填满整个返回数组
        for (int i = 0; i < size;++i) {
            int num = nums[i];
            while (top >= 0 && ret[top] < num && remain > 0) {  //当remain == 0时 不能再从数组中删除元素了 因为后面剩余的元素不够填满数组
                top--;
                remain--;
            }
            if (top < k - 1) {
                ret[++top] = num;
            }
            else {
                remain--;
            }
        }
        return ret;
    }
    vector<int> merge(vector<int>& lvec, vector<int>& rvec) {
        int lsize = lvec.size();
        if (lsize == 0)
            return rvec;
        int rsize = rvec.size();
        if (rsize == 0)
            return lvec;
        vector<int> ret(lsize + rsize, 0);
        int i = 0, j = 0, k = 0;
        while (i < lsize && j < rsize) {
            /*  这里必须要比对两个字符串哪个更大 
                不然如 67, 604
                假如先选了下面一个6，会得到66704
                假如先选了上面一个6，会得到67604
            */
            if(contrast(lvec, i, rvec, j) > 0){
                ret[k] = lvec[i];
                ++i;
            }
            else {
                ret[k] = rvec[j];
                ++j;
            }
            ++k;
        }
        while (i < lsize) {
            ret[k] = lvec[i];
            ++i;
            ++k;
        }
        while (j < rsize) {
            ret[k] = rvec[j];
            ++j;
            ++k;
        }
        return ret;
    }
    int contrast(vector<int>& lvec, int i, vector<int>& rvec, int j) {
        int lsize = lvec.size();
        int rsize = rvec.size();
        while (i < lsize && j < rsize) {
            int dec = lvec[i] - rvec[j];
            if (dec != 0)
                return dec;
            ++i;
            ++j;
        }
        return (lsize - i) - (rsize - j);
    }
};

int main(int argc, char const* argv[]) {
    CreateMaximumNumber cls;
    auto ret = cls.maxNumber(vector<int>{3,4,6,5}, vector<int>{9,1,2,5,8,3}, 5);
    cout << "[";
    for(auto i : ret){
        cout << i << ",";
    }
    cout << "]" << endl;
    auto ret1 = cls.maxNumber(vector<int>{6,7}, vector<int>{6,0,4}, 5);
    cout << "[";
    for(auto i : ret1){
        cout << i << ",";
    }
    cout << "]" << endl;
    auto ret2 = cls.maxNumber(vector<int>{3,9}, vector<int>{8,9}, 3);
    cout << "[";
    for(auto i : ret2){
        cout << i << ",";
    }
    cout << "]" << endl;
    auto ret3 = cls.maxNumber(vector<int>{3,4,1,2,3,6,5}, vector<int>{9,1,2,5,8,3}, 6);
    cout << "[";
    for(auto i : ret3){
        cout << i << ",";
    }
    cout << "]" << endl;
    auto ret4 = cls.maxNumber(vector<int>{3,4,1,2,3,6,5,3,2,1}, vector<int>{9,1,2,5,8,3}, 6);
    cout << "[";
    for(auto i : ret4){
        cout << i << ",";
    }
    cout << "]" << endl;
    return 0;
}
