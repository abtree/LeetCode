#include <iostream>
#include <vector>

using namespace std;

//283. 移动零
class MoveZeros {
    /* 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
    */
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j< nums.size(); ++j){
            if(nums[j] == 0)
                continue;
            if(i < j){
                nums[i] = nums[j];
            }
            ++i;
        }
        while(i < nums.size()){
            nums[i] = 0;
            ++i;
        }
    }
};

int main(int argc, char const *argv[]){
    MoveZeros cls;
    vector<int> ret{0,1,0,3,12};
    cls.moveZeroes(ret);
    cout << '[';
    for(auto i: ret){
        cout << i<<",";
    }
    cout << ']'<<endl;
    return 0;
}
