#include <iostream>
#include <cmath>
using namespace std;

// 319. 灯泡开关
class BulbSwitcher {
    /* 初始时有 n 个灯泡处于关闭状态。对某个灯泡切换开关意味着：如果灯泡状态为关闭，那该灯泡就会被开启；而灯泡状态为开启，那该灯泡就会被关闭。
    第 1 轮，每个灯泡切换一次开关。即，打开所有的灯泡。
    第 2 轮，每两个灯泡切换一次开关。 即，每两个灯泡关闭一个。
    第 3 轮，每三个灯泡切换一次开关。
    第 i 轮，每 i 个灯泡切换一次开关。 而第 n 轮，你只切换最后一个灯泡的开关。
    找出 n 轮后有多少个亮着的灯泡。
    */
public:
    int bulbSwitch(int n) {
        /*  1: 1
            2: 1 0
            3: 1 0 0
            4: 1 0 0 1
            5: 1 0 0 1 0
            6: 1 0 0 1 0 0
            7: 1 0 0 1 0 0 0
            8: 1 0 0 1 0 0 0 0
            9: 1 0 0 1 0 0 0 0 1
           10: 1 0 0 1 0 0 0 0 1 0
           只有完全平方上的数，最终结果才是1
        */
        return sqrt(n);
    }
};

int main(int argc, char const *argv[]){
    BulbSwitcher cls;
    cout << cls.bulbSwitch(3) << "-> 1" << endl;
    cout << cls.bulbSwitch(0) << "-> 0" << endl;
    cout << cls.bulbSwitch(1) << "-> 1" << endl;
    return 0;
}
