#pragma once

//66. 加一
class CPlusOne {
    /*
    给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
    最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
    你可以假设除了整数 0 之外，这个整数不会以零开头。

    示例 1：
    输入：digits = [1,2,3]
    输出：[1,2,4]
    解释：输入数组表示数字 123。

    示例 2：
    输入：digits = [4,3,2,1]
    输出：[4,3,2,2]
    解释：输入数组表示数字 4321。

    示例 3：
    输入：digits = [0]
    输出：[1]
     
    提示：
    1 <= digits.length <= 100
    0 <= digits[i] <= 9
    */
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty())
            return vector<int>{1};

        for (int i = digits.size() - 1; i >= 0;--i) {
            if (digits[i] == 9)
                digits[i] = 0;  //进位
            else {
                ++digits[i];
                return digits;  //不进位
            }
        }
        //最后一位需要进位的话 所有位全为0 所以可以在最后加0 第一位设置为1 
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
public:
    static void Test() {
        CPlusOne cls;
        auto ret = cls.plusOne(vector<int>{1, 2, 3});
        cout << "[";
        for (auto it : ret) {
            cout << it << ",";
        }
        cout << "]" << endl;

        auto ret1 = cls.plusOne(vector<int>{4, 3, 2, 1});
        cout << "[";
        for (auto it : ret1) {
            cout << it << ",";
        }
        cout << "]" << endl;

        auto ret2 = cls.plusOne(vector<int>{0});
        cout << "[";
        for (auto it : ret2) {
            cout << it << ",";
        }
        cout << "]" << endl;
    }
};