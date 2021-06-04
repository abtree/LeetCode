#include <iostream>
#include <vector>
using namespace std;

class MissingNumber {
public:
    int missingNumber(vector<int>& nums) {
        //求和公式差值
        int n = nums.size();
        //第一步 计算 1...n的和
        int t = n * (n + 1) / 2;
        //第二步 计算数组元素的和
        int x = 0;
        for (int i : nums) {
            x += i;
        }
        return t - x;
    }
public:
    int missingNumber2(vector<int>& nums) {
        //异或
        int x = 0;
        int n = nums.size();
        for(int i = 1; i<=n;++i){
            x ^= i; //第一次异或
        }
        for(int i : nums){
            x ^= i; //第二次异或
        }
        return x;
    }
};

int main(int argc, char const *argv[]){
    MissingNumber cls;
    cout << cls.missingNumber2(vector<int>{3,0,1}) << "->2" <<endl; 
    cout << cls.missingNumber2(vector<int>{0,1}) << "->2" <<endl; 
    cout << cls.missingNumber2(vector<int>{9,6,4,2,3,5,7,0,1}) << "->8" <<endl; 
    cout << cls.missingNumber2(vector<int>{0}) << "->1" <<endl; 
    return 0;
}
