#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class MaximumXorOfTwoNumbersInAnArray{
public:
    int findMaximumXOR(vector<int>& nums) {
        //暴力破解
        int big = 0;
        for (int i = 0; i < nums.size();++i) {
            for (int j = 0; j < nums.size();++j) {
                big = max(big, nums[i] ^ nums[j]);
            }
        }
        return big;
    }
public:
    int findMaximumXOR1(vector<int>& nums) {
        /* 最终结果最好的情况是每一位都为1
            所以我们默认每一位都为1
            如果不能满足每一位都为1 则高位设置为1优于低位设置为1
            所以我们要从高位开始判断
        */
        int x = 0;
        //按位遍历(从高位到低位)，我们只判断31位，因为最高位表示符号 需要设置为0
        for (int i = 30; i >= 0; --i) {
            unordered_set<int> seen;
            for (auto c : nums) {
                seen.insert(c >> i);    //存储每个num的前i位    
            }
            //这里表示将当前x左移1位再将末位置为1
            // x/2 == x >> 1 || x * 2 == x << 1
            int xn = (x << 1) + 1;
            bool found = false;
            for (auto c : nums) {
                //这里有一个转换 x = a_i ^ a_j == a_j = x ^ a_i
                //这里xn为我们想要的结果， 我们从nums中找两个数的前i位异或的结果为xn
                if (seen.count(xn ^ (c >> i))) {
                    found = true;
                    break;
                }
            }
            if (found) {
                //说明找到一个方案可以设置当前位为1
                x = xn;
            }
            else {
                //没有一种方案可以设置当前位为1 则当前位只能为0
                x = xn - 1;
            }
        }
        return x;
    }
public:
    struct Trie {
        Trie* left{};   //表示当前位为0
        Trie* right{};  //表示当前位为1
    };
    int findMaximumXOR2(vector<int>& nums) {
        root = new Trie();
        int x = 0;
        for (int i = 1; i < nums.size(); ++i) {
            add(nums[i - 1]);
            x = max(x, check(nums[i]));
        }
        return x;
    }
private:
    void add(int num) {
        Trie* cur = root;
        for (int i = 30; i >= 0;--i) {
            int bit = (num >> i)&1; //取出num的第i位
            if (bit == 0) {
                if (!cur->left)
                    cur->left = new Trie();
                cur = cur->left;
            }
            else {
                if (!cur->right)
                    cur->right = new Trie();
                cur = cur->right;
            }
        }
    }
    int check(int num) {
        Trie* cur = root;
        int x = 0;
        for (int i = 30; i >= 0;--i) {
            int bit = (num >> i) & 1;   //取出num的第i位
            if (bit == 0) {
                //如果num的当前位为0，需要和为1的位异或才能得到1
                if (cur->right) {
                    x = (x << 1) + 1;
                    cur = cur->right;
                }
                else {
                    //否则x的第i位只能取0
                    x = (x << 1);
                    cur = cur->left;
                }
            }
            else {
                //如果num的当前位为1，需要和为0的位异或才能得到1
                if (cur->left) {
                    x = (x << 1) + 1;
                    cur = cur->left;
                }
                else {
                    //否则x的第i位只能取0
                    x = (x << 1);
                    cur = cur->right;
                }
            }
        }
        return x;
    }
private:
    //此处不考虑内存释放的问题
    Trie* root{};
};

int main(int argc, char const* argv[]) {
    MaximumXorOfTwoNumbersInAnArray cls;
    cout << cls.findMaximumXOR2(vector<int>{3,10,5,25,2,8}) << " -> 28" << endl;
    cout << cls.findMaximumXOR2(vector<int>{0}) << " -> 0" << endl;
    cout << cls.findMaximumXOR2(vector<int>{2,4}) << " -> 6" << endl;
    cout << cls.findMaximumXOR2(vector<int>{8,10,2}) << " -> 10" << endl;
    cout << cls.findMaximumXOR2(vector<int>{14,70,53,83,49,91,36,80,92,51,66,70}) << " -> 127" << endl;
    return 0;
}
