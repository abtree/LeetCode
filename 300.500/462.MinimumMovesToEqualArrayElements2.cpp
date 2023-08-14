#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class MinimumMovesToEqualArrayElements2
{
public:
    int minMoves2(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int x = nums[n/2];
        int ret = 0;
        for(int i =0;i<n;++i){
            ret += abs(nums[i] - x);
        }
        return ret;
    }
public:
    int minMoves3(vector<int> nums) {
        int n = nums.size();
        int x = quickSelect(nums, 0, n-1, n/2);
        int ret = 0;
        for(int i =0;i<n;++i){
            ret += abs(nums[i] - x);
        }
        return ret;
    }
private:
    int quickSelect(vector<int>& a,int left, int right, int index){
        int x = partition(a, left, right);
        if (x == index){
            return a[x];
        }else if (x > index){
            return quickSelect(a, left, x-1, index);
        }else{
            return quickSelect(a, x+1, right, index);
        }
    }
    int partition(vector<int>& a, int left, int right){
        int i = rand() % (right - left + 1) + left;
        int x = a[i];
        swap(a[i], a[right]);
        int p = left;
        for(int j = left;j<right;++j){
            if(a[j] <= x){
                if(j != p){
                    swap(a[p], a[j]);
                }
                ++p;
            }
        }
        swap(a[p], a[right]);
        return p;
    }
};

int main(int argc, char const *argv[]){
    MinimumMovesToEqualArrayElements2 cls;
    cout << cls.minMoves3(vector<int>{1,2,3}) << " -> 2" << endl;
    cout << cls.minMoves3(vector<int>{1,10,2,9}) << " -> 16" << endl;
    return 0;
}
