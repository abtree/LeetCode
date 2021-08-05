#include <iostream>
#include <vector>
using namespace std;

class CountingBits {
public:
    vector<int> countBits(int n) {
        //暴力解法
        vector<int> ret(n + 1);
        for (int i = 0; i <= n;++i) {
            int cur = 0;
            for (int x = i; x > 0; x >>= 1) {
                if (x & 1) {
                    ++cur;
                }
            }
            ret[i] = cur;
        }
        return ret;
    }
public:
    vector<int> countBits1(int n) {
        vector<int> ret(n + 1);
        ret[0] = 0;
        for (int i = 1; i <= n;++i) {
            ret[i] = ret[i - (i & (-i))] + 1;
        }
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    CountingBits cls;
    auto& ret = cls.countBits1(2);
    cout << "[";
    for (int c : ret) {
        cout << c << ",";
    }
    cout << "]" << endl;

    auto& ret1 = cls.countBits1(5);
    cout << "[";
    for (int c : ret1) {
        cout << c << ",";
    }
    cout << "]" << endl;

    auto& ret2 = cls.countBits1(20);
    cout << "[";
    for (int c : ret2) {
        cout << c << ",";
    }
    cout << "]" << endl;

    return 0;
}
