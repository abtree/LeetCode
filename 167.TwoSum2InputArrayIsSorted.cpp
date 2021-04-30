#include <iostream>
#include <vector>

using namespace std;

//167. 两数之和 II - 输入有序数组
class TwoSum2InputArrayIsSorted
{
    /* 给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
    */
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() < 3)
            return vector<int>{1,2};
        for(int i = 0; i< numbers.size();++i){
            for(int j = i+1;j<numbers.size(); ++j){
                int k = numbers[i] + numbers[j];
                if(k == target)
                    return vector<int>{i+1, j+1};
                if(k > target)
                    break;
            }
        }
        return vector<int>{};
    }
public:
    vector<int> twoSum2(vector<int>& numbers, int target) {
        //双指针法
        if(numbers.size() < 3)
            return vector<int>{1,2};
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j){
            int k = numbers[i] + numbers[j];
            if(k == target)
                return vector<int>{i+1, j+1};
            if(k < target)
                ++i;
            else
                --j;
        }
        return vector<int>{};
    }
};

int main(int argc, char const *argv[])
{
    TwoSum2InputArrayIsSorted cls;

    auto& ret = cls.twoSum2(vector<int>{2,7,11,15}, 9);
    cout << "[";
    for(auto i : ret){
        cout << i << ",";
    }
    cout << "]" << endl;

    auto& ret1 = cls.twoSum2(vector<int>{2,3,4}, 6);
    cout << "[";
    for(auto i : ret1){
        cout << i << ",";
    }
    cout << "]" << endl;

    auto& ret3 = cls.twoSum2(vector<int>{-1, 0}, -1);
    cout << "[";
    for(auto i : ret3){
        cout << i << ",";
    }
    cout << "]" << endl;
    return 0;
}
