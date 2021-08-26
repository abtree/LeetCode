#include <iostream>
using namespace std;

// 374. 猜数字大小
class GuessNumberHigherOrLower {
public:
    int guessNumber(int n) {
        int start = 1, end = n;
        int mid = 0;
        while (start < end) {
            mid = (end - start) / 2 + start;
            int r = guess(mid);
            if (r == 0)
                return mid;
            if (r > 0) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return start;
    }
public:
    void setPick(int x) {
        pick = x;
    }
    int guess(int num) {
        if (num < pick)
            return 1;
        if (num > pick)
            return -1;
        return 0;
    }
private:
    int pick{};
};

int main(int argc, char const* argv[]) {
    GuessNumberHigherOrLower cls;
    cls.setPick(6);
    cout << cls.guessNumber(10) << " -> 6" << endl;
    cls.setPick(1);
    cout << cls.guessNumber(1) << " -> 1" << endl;
    cls.setPick(1);
    cout << cls.guessNumber(2) << " -> 1" << endl;
    cls.setPick(2);
    cout << cls.guessNumber(2) << " -> 2" << endl;
    return 0;
}
