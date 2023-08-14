#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class AssignCookies
{
public:
    int findContentChildren(vector<int> g, vector<int> s) {
        sort(g.begin(), g.end(), [](int a, int b){
            return a < b;
        });
        sort(s.begin(), s.end(), [](int a, int b){
            return a < b;
        });
        int i = 0, j = 0, r = 0;
        while(i < s.size() && j < g.size()){
            if(s[i] >= g[j]){
                i++;
                j++;
                r++;
            }else{
                i++;
            }
        }
        return r;
    }
};

int main(int argc, char const *argv[])
{
    AssignCookies cls;
    cout << cls.findContentChildren(vector<int>{1,2,3}, vector<int>{1,1}) << " -> 1" << endl;
    cout << cls.findContentChildren(vector<int>{1,2,3}, vector<int>{1,2}) << " -> 2" << endl;
    cout << cls.findContentChildren(vector<int>{10,9,8,7}, vector<int>{5,6,7,8}) << " -> 2" << endl;
    return 0;
}
