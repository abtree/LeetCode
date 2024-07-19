#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ipo
{
public:
    int findMaximizedCapital(int k, int w, const vector<int> &profits, const vector<int> &capital)
    {
        int n = profits.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i)
        {
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end());
        int curr = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        for (int i = 0; i < k; ++i)
        {
            while (curr < n && arr[curr].first <= w)
            {
                pq.push(arr[curr].second);
                ++curr;
            }
            if (!pq.empty())
            {
                w += pq.top();
                pq.pop();
            }
            else
            {
                break;
            }
        }
        return w;
    }
};

int main(int argc, char const *argv[])
{
    ipo cls;
    cout << cls.findMaximizedCapital(2, 0, vector<int>{1, 2, 3}, vector<int>{0, 1, 1}) << " -> 4" << endl;
    cout << cls.findMaximizedCapital(3, 0, vector<int>{1, 2, 3}, vector<int>{0, 1, 2}) << " -> 6" << endl;
    return 0;
}
