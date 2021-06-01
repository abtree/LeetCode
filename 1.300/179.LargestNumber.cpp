#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//179. 最大数
class LargestNumber
{
    /* 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
    */
public:
    string largestNumber(vector<int>& nums) {
        //排序
        sort(nums.begin(), nums.end(), [](int& x, int& y) {
            string sx = to_string(x);
            string sy = to_string(y);
            return sy + sx < sx + sy;
            });
        if (nums[0] == 0)
            return "0";
        string ans = "";
        for (auto n : nums) {
            ans += to_string(n);
        }
        return ans;
    }
};

int main(int argc, char const* argv[])
{
    LargestNumber cls;
    cout << cls.largestNumber(vector<int>{999999991, 9}) << " -> 9999999991" << endl;
    cout << cls.largestNumber(vector<int>{10, 2}) << " -> 210" << endl;
    cout << cls.largestNumber(vector<int>{3, 30, 34, 5, 9}) << " -> 9534330" << endl;
    cout << cls.largestNumber(vector<int>{1}) << " -> 1" << endl;
    cout << cls.largestNumber(vector<int>{10}) << " -> 10" << endl;
    return 0;
}
