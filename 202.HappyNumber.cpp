#include <iostream>
#include <unordered_set>
using namespace std;

class HappyNumber
{
public:
    bool isHappy(int n) {
        unordered_set<int> repeated;
        while (n != 1) {
            int total = 0;
            repeated.insert(n);
            while (n > 0)
            {
                total += (n % 10) * (n % 10);
                n = n / 10;
            }
            if (repeated.find(total) != repeated.end())
                return false;
            n = total;
        }
        return true;
    }
public:
    bool isHappy2(int n) {
        //数学 只有进入这几个数的会进入循环  4, 16, 37, 58, 89, 145, 42, 20
        unordered_set<int> cycle{ 4, 16, 37, 58, 89, 145, 42, 20 };
        while (n != 1) {
            if (cycle.find(n) != cycle.end())
                return false;
            int total = 0;
            while (n > 0)
            {
                total += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = total;
        }
        return true;
    }
};

int main(int argc, char const* argv[])
{
    HappyNumber cls;
    cout << boolalpha << cls.isHappy2(19) << " -> true" << endl;
    cout << boolalpha << cls.isHappy2(2) << " -> false" << endl;
    return 0;
}
