#include <iostream>
#include <algorithm>
using namespace std;

class KthSmallestInLexicographicalOrder {
public:
    int findKthNumber(int n, int k) {
        if (k == 1)
            return 1;
        s = 1;
        this->n = n;
        next(k);
        return (int)s;
    }
private:
    void next(int k) {
        --k;
        if (s * 10 <= n) {
            //向子节点遍历
            s = s * 10;
        }
        else if (s % 10 < 9 && s + 1 <= n) {
            //找到兄弟节点
            s = s + 1;
        }
        else {
            //回退到父节点
            s /= 10;
            while (s % 10 == 9) {
                s /= 10;
            }
            s += 1;
        }
        if (k > 1) {
            next(k);
        }
    }
private:
    long long s{};
    long long n{};
public:
    int findKthNumber1(int n, int k) {
        int curr = 1;
        --k;
        while (k > 0) {
            int steps = cntsteps(n, curr);
            if (steps <= k) {
                //k在steps外，需要向下找
                k -= steps;
                ++curr;
            }
            else {
                //如果k落在steps内
                curr = curr*10;
                --k;
            }
        }
        return curr;
    }
private:
    int cntsteps(long long n, int curr) {
        int steps = 0;
        long long first = curr;
        long long last = curr;
        while (first <= n) {
            //计算该层总共有多少个数
            steps += min(last, n) - first + 1;
            // x == curr
            // first => x x0 x00 x000...
            first = first * 10;
            // last => x x9 x99 x999....
            last = last * 10 + 9;
        }
        //这是以x为根节点的所有节点数(包括x节点)
        return steps;
    }
};

int main(int argc, char const* argv[]) {
    KthSmallestInLexicographicalOrder cls;
    cout << cls.findKthNumber1(596516650, 593124772) << " -> 96947306" << endl;
    cout << cls.findKthNumber1(10, 3) << " -> 2" << endl;
    cout << cls.findKthNumber1(13, 2) << " -> 10" << endl;
    cout << cls.findKthNumber1(1, 1) << " -> 1" << endl;
    return 0;
}
