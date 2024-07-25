#include <iostream>
#include<vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DistributeCandies
{
public:
    int distributeCandies(vector<int> candyType) {
        int eat = candyType.size() / 2;
        unordered_map<int, int> dp;
        for(int c : candyType){
            dp[c]++;
        }
        int types = 0;
        for (auto& it : dp){
            if(it.second > 0){
                ++types;
            }
        }
        return min(eat, types);
    }
};

int main(int argc, char const *argv[])
{
    DistributeCandies cls;
    cout << cls.distributeCandies(vector<int>{1,1,2,2,3,3}) << " -> 3" << endl;
    cout << cls.distributeCandies(vector<int>{1,1,2,3}) << " -> 2" << endl;
    cout << cls.distributeCandies(vector<int>{6,6,6,6}) << " -> 1" << endl;
    return 0;
}
