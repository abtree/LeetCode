#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 228. 汇总区间
class SummaryRanges {
    /* 给定一个无重复元素的有序整数数组 nums 。返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。列表中的每个区间范围 [a,b] 应该按如下格式输出：
    "a->b" ，如果 a != b
    "a" ，如果 a == b
    */
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int size = nums.size();
        if(size == 0)
            return ret;
        int i = 0;
        while(i< size){
            for(int j = i+1; ;++j){
                if(j >= size || nums[j] != nums[j-1] + 1){
                    if(j-1 != i){
                        ret.push_back(to_string(nums[i]) + "->"+to_string(nums[j-1]));
                    }else{
                        ret.push_back(to_string(nums[i]));
                    }
                    i = j;
                    break;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    SummaryRanges cls;
    auto& ret = cls.summaryRanges(vector<int>{0,1,2,4,5,7});
    cout << "[";
    for(auto& it : ret){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;

    auto& ret2 = cls.summaryRanges(vector<int>{0,2,3,4,6,8,9});
    cout << "[";
    for(auto& it : ret2){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;

    auto& ret3 = cls.summaryRanges(vector<int>{-1});
    cout << "[";
    for(auto& it : ret3){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;
    return 0;
}
