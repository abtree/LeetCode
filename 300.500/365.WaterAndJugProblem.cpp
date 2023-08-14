#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

//365. 水壶问题
class WaterAndJugProblem {
    /* 有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。
    你允许：
    装满任意一个水壶
    清空任意一个水壶
    从一个水壶向另外一个水壶倒水，直到装满或者倒空
    */
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (targetCapacity == jug1Capacity || targetCapacity == jug2Capacity || targetCapacity == jug1Capacity + jug2Capacity)
            return true;
        int big = max(jug1Capacity, jug2Capacity);
        int small = min(jug1Capacity, jug2Capacity);
        unordered_map<int, bool> flags;
        int x = big;
        while (x != targetCapacity) {
            if (x < small) {
                if (x + big == targetCapacity)
                    return true;
                if (flags[x])
                    return false;
                flags[x] = true;
                x = big - small + x;
            }
            else {
                x -= small;
                if (x == targetCapacity)
                    return true;
            }
        }
        return true;
    }
public:
    bool canMeasureWater1(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity)
            return false;
        if (jug1Capacity == 0 || jug2Capacity == 0) {
            return targetCapacity == 0 || jug1Capacity + jug2Capacity == targetCapacity;
        }
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }
private:
    int gcd(int a, int b) {
        int r;
        while (b > 0) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
};

int main(int argc, char const* argv[])
{
    WaterAndJugProblem cls;
    cout << boolalpha << cls.canMeasureWater1(6, 9, 1) << " -> false" << endl;
    cout << boolalpha << cls.canMeasureWater1(3, 5, 4) << " -> true" << endl;
    cout << boolalpha << cls.canMeasureWater1(2, 6, 5) << " -> false" << endl;
    cout << boolalpha << cls.canMeasureWater1(18, 7, 6) << " -> true" << endl;
    cout << boolalpha << cls.canMeasureWater1(1, 2, 3) << " -> true" << endl;
    return 0;
}
