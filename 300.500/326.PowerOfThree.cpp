#include <iostream>
#include <vector>
using namespace std;

// 326. 3的幂
class PowerOfThree {
    /* 给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x
    */
public:
    bool isPowerOfThree(int n) {
        if (n == 1)
            return true;
        long long i = 1;
        vector<long long> queue;
        long long p = 3;
        while (i < n) {
            queue.push_back(p);
            if (i * p == n)
                return true;
            if (i * p > n)
                break;
            i *= p;
            p *= p;
        }
        while (i < n) {
            int pos = 0;
            if (i * queue[pos] > n)
                return false;
            while (pos < queue.size()) {
                if (i * queue[pos] == n)
                    return true;
                if (i * queue[pos] > n)
                    break;
                i *= queue[pos];
                ++pos;
            }
        }
        return false;
    }
public:
    bool isPowerOfThree1(int n) {
        /*  这里要注意
            因为n 为int类型 所以最大值不会大于 INT_MAX
            而小于 INT_MAX 的最大的3的幂次为 3^19 = 1162261467 => 3^20 > INT_MAX
            所以我们返回true的情况: 3^19 / 3^x => x < 19 : 通过上下约分可知 结果为 3^(19-x) 余数为 0
            既有下面的计算式
        */
        return n > 0 && 1162261467 % n == 0;
    }
};

int main(int argc, char const* argv[]) {
    PowerOfThree cls;
    cout << boolalpha << cls.isPowerOfThree1(3) << " -> true" << endl;
    cout << boolalpha << cls.isPowerOfThree1(27) << " -> true" << endl;
    cout << boolalpha << cls.isPowerOfThree1(0) << " -> false" << endl;
    cout << boolalpha << cls.isPowerOfThree1(9) << " -> true" << endl;
    cout << boolalpha << cls.isPowerOfThree1(45) << " -> false" << endl;
    return 0;
}
