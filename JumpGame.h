#pragma once

//55. 跳跃游戏
class CJumpGame {
    /*
    给定一个非负整数数组，你最初位于数组的第一个位置。
    数组中的每个元素代表你在该位置可以跳跃的最大长度。
    判断你是否能够到达最后一个位置。

    示例 1:
    输入: [2,3,1,1,4]
    输出: true
    解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。

    示例 2:
    输入: [3,2,1,0,4]
    输出: false
    解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
    */
public:
    bool canJump2(vector<int>& nums) {
        //判断0是否可以被跳过
        int i = nums.size() - 1;
        if (i <= 0)
            return true;
        int need = 0;
        for (;i >= 0;--i) {
            if (nums[i] > need) {
                if (need > 0)
                    need = 0;
            }
            else if (need > 0 && nums[i] == need && i + need == nums.size() - 1) {  //如果0在末尾，能到达0就可以了
                need = 0;
            }
            else {
                ++need;
            }
        }
        return need == 0;
    }
public:
    static void Test() {
        CJumpGame cls;
        cout << boolalpha << cls.canJump2(vector<int>{1, 0, 2, 2, 0}) << " -> false" << endl;
        cout << boolalpha << cls.canJump2(vector<int>{2, 0, 0}) << " -> true" << endl;
        cout << boolalpha << cls.canJump2(vector<int>{0}) << " -> true" << endl;
        cout << boolalpha << cls.canJump2(vector<int>{2, 3, 1, 1, 4}) << " -> true" << endl;
        cout << boolalpha << cls.canJump2(vector<int>{3, 2, 1, 0, 4}) << " -> false" << endl;
    }
};