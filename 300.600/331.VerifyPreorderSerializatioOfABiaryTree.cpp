#include <iostream>
#include <vector>
#include <string>

using namespace std;

class VerifyPreorderSerializatioOfABiaryTree {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.compare("#") == 0)
            return true;    //空二叉树满足需求
        vector<int> dp; //记录每个节点的子节点数
        int pos = -1;
        int max = -1;
        char* token = strtok((char*)preorder.c_str(), ",");
        while (token) {
            if (strcmp(token, "#") == 0) {
                if (pos < 0)
                    return false;   //没有父节点 就不需要'#'
                if (dp[pos] > 1)
                    return false;
                dp[pos] += 1;
                while (pos > -1 && dp[pos] == 2) {
                    --pos;  //当前节点满了 子节点只能加在父节点上
                }
            }
            else {
                if (pos > -1) { //设置父节点有一个子节点
                    dp[pos] += 1;
                }
                else if (max > -1) {
                    return false;   //表示已经有一颗二叉树了， 不能再新建一颗
                }
                ++pos;
                if (pos <= max) {
                    dp[pos] = 0;
                }
                else {
                    dp.push_back(0);
                    ++max;
                }
            }
            token = strtok(nullptr, ",");
        }
        return pos == -1;
    }
public:
    bool isValidSerialization2(string preorder) {
        //计数法 记录当前数中可以填充的子节点总数，只要总数大于0，就还能填充,也还需要填充
        int seat = 1;   //默认有一个位置
        char* token = strtok((char*)preorder.c_str(), ",");
        while (token) {
            if (seat <= 0)
                return false;
            --seat;
            if (strcmp(token, "#") != 0) {
                seat += 2;
            }
            token = strtok(nullptr, ",");
        }
        return seat == 0;   //最后位置要被坐满
    }
};

int main(int argc, char const* argv[]) {
    VerifyPreorderSerializatioOfABiaryTree cls;
    cout << boolalpha << cls.isValidSerialization2("#,7,6,9,#,#,#") << " -> false" << endl;
    cout << boolalpha << cls.isValidSerialization2("9,3,4,#,#,1,#,#,#,2,#,6,#,#") << " -> false" << endl;
    cout << boolalpha << cls.isValidSerialization2("9,3,4,#,#,1,#,#,2,#,6,#,#") << " -> true" << endl;
    cout << boolalpha << cls.isValidSerialization2("1,#") << " -> false" << endl;
    cout << boolalpha << cls.isValidSerialization2("9,#,#,1") << " -> false" << endl;
    cout << boolalpha << cls.isValidSerialization2("#") << " -> true" << endl;
    return 0;
}
