#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>
#include <numeric>
using namespace std;

class RandomPickWithWeight
{
public:
    RandomPickWithWeight(vector<int> w)
    {
        for (int x : w)
        {
            sum += x;
            radio.push_back(x);
        }
        srand(time(nullptr));
    }
    int pickIndex()
    {
        int b = rand() % sum;
        int n = radio.size();
        for (int i = 0; i < n; ++i)
        {
            if (b < radio[i])
            {
                return i;
            }
            else
            {
                b -= radio[i];
            }
        }
        return 0;
    }

private:
    vector<int> radio;
    long long sum{};
};
class RandomPickWithWeight1
{
public:
    RandomPickWithWeight1(vector<int> w) : gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0))
    {
        partial_sum(w.begin(), w.end(), back_inserter(pre));
    }
    int pickIndex()
    {
        int x = dis(gen);
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }

private:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<int> pre;
};

int main()
{
    RandomPickWithWeight cls(vector<int>{1, 3});
    cout << cls.pickIndex() << endl;
    cout << cls.pickIndex() << endl;
    cout << cls.pickIndex() << endl;
    cout << cls.pickIndex() << endl;
    cout << cls.pickIndex() << endl;
    return 0;
}
