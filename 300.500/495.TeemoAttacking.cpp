#include <iostream>
#include <vector>
using namespace std;

class TeemoAttacking
{
public:
    int findPoisonedDuration(const vector<int> &timeSeries, int duration)
    {
        vector<pair<int, int>> dp;
        for (int x : timeSeries)
        {
            if (dp.empty())
            {
                dp.push_back({x, x + duration});
            }
            else
            {
                if (dp.back().second >= x)
                {
                    dp.back().second = x + duration;
                }
                else
                {
                    dp.push_back({x, x + duration});
                }
            }
        }
        int sum = 0;
        for (auto &it : dp)
        {
            sum += it.second - it.first;
        }
        return sum;
    }

    int findPoisonedDuration1(const vector<int> &timeSeries, int duration)
    {
        int sum = 0;
        pair<int, int> ing{};
        for (int x : timeSeries)
        {
            if (ing.second >= x)
            {
                ing.second = x + duration;
                continue;
            }
            sum += ing.second - ing.first;
            ing.first = x;
            ing.second = x + duration;
        }
        sum += ing.second - ing.first;
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    TeemoAttacking cls;
    cout << cls.findPoisonedDuration1(vector<int>{1, 4}, 2) << " -> 4" << endl;
    cout << cls.findPoisonedDuration1(vector<int>{1, 2}, 2) << " -> 3" << endl;
    return 0;
}
