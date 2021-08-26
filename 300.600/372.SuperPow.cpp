#include <iostream>
#include <vector>
using namespace std;

// 372. 超级次方
class SuperPow {
    /* 你的任务是计算 a^b % 1337，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
    */
public:
    int superPow(int a, vector<int>& b) {
        /* (a*b)%k = (a%k)(b%k)%k
            证明：令 a=Ak+B (0<=B<k); b=Ck+D (0<=D<k)
            ab = (Ak+B)(Ck+D) = ACK^2+ADk+BCk+BD
            => ab%k = BD%k : 解释 由于原式中"ACK^2+ADk+BCk"一定是k的倍数,所以求模后余数为0，也就是余数为BD，但BD可能大于k，所以还要对BD求模
            又因为 B=a%k, D=b%k
            带入原式得: (a%k)(b%k)%k = (a*b)%k
        */
        /* 本题可改写为 (a%1337)(b%1337)%1337
            本题还要证明:a^b%k=(a%k)^b
        */
        if (b.empty())
            return 1;   //任何数的0次都是1
        a %= base;
        int last = b.back();
        b.pop_back();

        int p1 = myPow(a, last);
        int p2 = (int)myPow(superPow(a, b), 10);    //注意 这里算10次不能用系统函数pow，可能越界
        return (p1 * p2) % base;
    }
    int myPow(int a, int k) {
        int res = 1;
        for (int i = 0;i < k;++i) {
            res *= a;
            res %= base;    //这里其实可以放到外面（但为了防止越界，在for循环里面求余）
        }
        return res;
    }
    int myPow2(int a, int k) {
        //采用2分发优化
        if (k == 0)
            return 1;
        if (k % 2 == 1) {
            //k为奇数
            return (myPow2(a, k - 1) * a) % base; //转化为偶数
        }
        else {
            //k为偶数
            int mid = myPow2(a, k / 2);
            return (mid * mid) % base;
        }
    }
private:
    const int base{ 1337 };
};

int main(int argc, char const* argv[]) {
    SuperPow cls;
    cout << cls.superPow(2, vector<int>{3}) << " -> 8" << endl;
    cout << cls.superPow(2, vector<int>{1, 0}) << " -> 1024" << endl;
    cout << cls.superPow(1, vector<int>{4, 3, 3, 8, 5, 2}) << " -> 1" << endl;
    cout << cls.superPow(INT_MAX, vector<int>{2, 0, 0}) << " -> 1198" << endl;
    return 0;
}
