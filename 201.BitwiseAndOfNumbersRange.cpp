#include <iostream>
using namespace std;

class BitwiseAndOfNumbersRange
{
public:
    int rangeBitwiseAnd(int left, int right) {
        //位移法 
        int cnt = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            ++cnt;
        }
        return left << cnt;
    }
public:
    int rangeBitwiseAnd2(int left, int right) {
        //Brian Kernighan 算法 --- 通过 n & (n-1) 消除n最后一个1
        while (left < right) {
            right = right & (right - 1);
        }
        return right;
    }
};

int main(int argc, char const* argv[])
{
    BitwiseAndOfNumbersRange cls;
    cout << cls.rangeBitwiseAnd2(5, 7) << " -> 4" << endl;
    cout << cls.rangeBitwiseAnd2(0, 0) << " -> 0" << endl;
    cout << cls.rangeBitwiseAnd2(1, 2147483647) << " -> 0" << endl;
    return 0;
}
