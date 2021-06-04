#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 260. 只出现一次的数字 III
class SingleNumber3 {
    /* 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
    进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
    */
public:
    vector<int> singleNumber(vector<int>& nums) {
        //hash表 和 排序算法
        int size = nums.size();
        if(size < 3)
            return nums;
        unordered_set<int> dp;
        for(int i : nums){
            if(dp.find(i) != dp.end()){
                dp.erase(i);
            }else{
                dp.insert(i);
            }
        }
        vector<int> ret(dp.begin(), dp.end());
        return ret;
    }
public:
    vector<int> singleNumber2(vector<int>& nums) {
        if(nums.size() < 3)
            return nums;
        //分组位运算
        int ret = 0;
        for (int i : nums){
            ret^=i;
        }
        // int div = 1;
        // while((div&ret) == 0){  //找到ret中第一个1 这个1表示:两个目标数a,b在这一位上,一个是0,一个是1;我们由此可以保证将a,b分在不同组
        //     div <<= 1;
        // }
        ret &= (-ret); //与上面的循环效果一样
        int a = 0, b = 0;
        for(int i : nums){
            if(i & ret){
                a ^= i;
            }else{
                b ^= i;
            }
        }
        return vector<int>{a, b};
    }
};

int main(int argc, char const *argv[]){
    SingleNumber3 cls;
    auto& ret = cls.singleNumber2(vector<int>{1,2,1,3,2,5});
    cout << "[";
    for(int i : ret){
        cout << i << ",";
    }
    cout << "]" << endl;

    auto& ret2 = cls.singleNumber2(vector<int>{-1,0});
    cout << "[";
    for(int i : ret2){
        cout << i << ",";
    }
    cout << "]" << endl;

    auto& ret3 = cls.singleNumber2(vector<int>{0,1});
    cout << "[";
    for(int i : ret3){
        cout << i << ",";
    }
    cout << "]" << endl;

    auto& ret4 = cls.singleNumber2(vector<int>{1,2,3,4,5,6,7,5,4,3,2,1});
    cout << "[";
    for(int i : ret4){
        cout << i << ",";
    }
    cout << "]" << endl;
    return 0;
}
