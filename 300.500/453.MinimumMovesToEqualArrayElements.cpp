#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinimumMovesToEqualArrayElements{
public:
    int minMoves(vector<int> nums) {
        //该题每次操作让n-1个元素加1 等价于 让一个元素减1(即不加1的那个元素减1)
        //于是 我们只需要计算将所有元素减到最小元素值即可
        int minN = *min_element(nums.begin(), nums.end());
        int ret = 0;
        for(int i: nums){
            ret += (i - minN);
        }
        return ret;
    }
};

int main(){
    MinimumMovesToEqualArrayElements cls;
    cout << cls.minMoves(vector<int>{1,2,3}) << " -> 3" << endl;
    cout << cls.minMoves(vector<int>{1,1,1}) << " -> 0" << endl;
}