#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Heaters
{
public:
    int findRadius(vector<int> houses, vector<int> heaters)
    {
        // 对header进行排序
        sort(heaters.begin(), heaters.end());
        // 对houses进行排序
        sort(houses.begin(), houses.end());
        // 找到离每个房子最近的供热点
        int ma = 0;
        for (int i = 0, j = 0; i < houses.size(); ++i)
        {
            int dis = abs(houses[i] - heaters[j]);
            while (j + 1 < heaters.size() && dis >= abs(houses[i] - heaters[j + 1]))
            {
                ++j;
                dis = abs(houses[i] - heaters[j]);
            }
            ma = max(dis, ma);
        }
        // int ma = 0, i = 0;
        // for (int h : houses)
        // {
        //     int des = INT_MAX;
        //     for (int j = i; j < heaters.size(); ++j)
        //     {
        //         int x = abs(heaters[j] - h);
        //         if (x > des)
        //         {
        //             break;
        //         }
        //         des = x;
        //         i = j;
        //     }
        //     ma = max(des, ma);
        // }
        return ma;
    }
};

int main(int argc, char const *argv[])
{
    Heaters cls;
    cout << cls.findRadius(vector<int>{1, 2, 3}, vector<int>{2}) << " -> 1" << endl;
    cout << cls.findRadius(vector<int>{1, 2, 3, 4}, vector<int>{1, 4}) << " -> 1" << endl;
    cout << cls.findRadius(vector<int>{1, 5}, vector<int>{2}) << " -> 3" << endl;
    return 0;
}
