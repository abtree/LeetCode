#include <iostream>
#include <vector>

using namespace std;

//292. Nim 游戏
class NimGame {
    /*  你和你的朋友，两个人一起玩 Nim 游戏：桌子上有一堆石头。你们轮流进行自己的回合，你作为先手。每一回合，轮到的人拿掉 1 - 3 块石头。拿掉最后一块石头的人就是获胜者。假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 n 的情况下赢得游戏。如果可以赢，返回 true；否则，返回 false 。
    */
public:
    bool canWinNim(int n) {
        //动态规划
        if (n < 4)
            return true;
        bool b1 = true;
        bool b2 = true;
        bool b3 = true;
        for (int i = 4; i <= n;++i) {
            bool b = !(b1 && b2 && b3);
            b1 = b2;
            b2 = b3;
            b3 = b;
        }
        return b3;
    }
public:
    bool canWinNim2(int n) {
        //数学归纳
        return n % 4 != 0;
    }
};

int main(int argc, char const* argv[]) {
    NimGame cls;
    cout << boolalpha << cls.canWinNim2(4) << "->false" << endl;
    cout << boolalpha << cls.canWinNim2(1) << "->true" << endl;
    cout << boolalpha << cls.canWinNim2(2) << "->true" << endl;
    cout << boolalpha << cls.canWinNim2(5) << "->true" << endl;
    cout << boolalpha << cls.canWinNim2(7) << "->true" << endl;
    cout << boolalpha << cls.canWinNim2(8) << "->false" << endl;
    return 0;
}
