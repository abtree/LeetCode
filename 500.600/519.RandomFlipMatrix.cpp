#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
using namespace std;

class RandomFlipMatrix
{
public:
    RandomFlipMatrix(int m, int n) : m(m), n(n), total(m * n)
    {
        srand(time(nullptr));
    }

    vector<int> flip()
    {
        int x = rand() % total;
        vector<int> ans;
        --total;
        if (dp.contains(x))
        {
            ans = {dp[x] / n, dp[x] % n};
        }
        else
        {
            ans = {x / n, x % n};
        }
        // 将每次消耗掉的点，都移动到末尾
        if (dp.contains(total))
        {
            dp[x] = dp[total];
        }
        else
        {
            dp[x] = total;
        }
        return ans;
    }

    void reset()
    {
        total = m * n;
        dp.clear();
    }

private:
    int m{};
    int n{};
    int total{};
    unordered_map<int, int> dp;
};

void print(const vector<int> &ret)
{
    cout << "[" << ret[0] << " , " << ret[1] << "]" << endl;
}

int main()
{
    RandomFlipMatrix cls(3, 1);
    print(cls.flip());
    print(cls.flip());
    print(cls.flip());
    cls.reset();
    print(cls.flip());

    return 0;
}
