#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

class Pattern132{
public:
    //以中间值（最大值）为基准 枚举
    bool find132pattern(vector<int> nums) {
        int n = nums.size();
        if(n < 3){
            return false;
        }
        int left_min = nums[0];
        multiset<int> right_all;
        for(int j = 2;j<n;++j){
            right_all.insert(nums[j]);
        }
        for(int i = 1;i<n-1;++i){
            if(left_min < nums[i]){
               auto it = right_all.upper_bound(left_min);
               if(it != right_all.end() && *it < nums[i]){
                    return true;
               }
            }
            left_min = min(nums[i], left_min);
            //注意 这里因为用了find函数 所以 当有相同值时 只会删除一个
            right_all.erase(right_all.find(nums[i+1]));
        }
        return false;
    }
    //以i值（最小值）为基准 枚举
    bool find132pattern1(vector<int> nums) {
        int n = nums.size();
        if(n < 3){
            return false;
        }
        //stack存入备选的第三个值（中间大小值）,存入方式为单调递减
        stack<int> candidate_k;
        //栈底存储的为第二个值(最大值)
        candidate_k.push(nums[n-1]);
        //max_k为第三个值
        int max_k = INT_MIN;
        for(int i = n-2;i>=0;--i){
            if(nums[i] < max_k){
                return true;
            }
            //这里其实我们取的是最底下的值 即栈中的最大值
            //当然 其实不一定会一次就取到最底下的值，但最底下的值一定可以作为第二值的(最大值)
            while(!candidate_k.empty() && nums[i] > candidate_k.top()){
                max_k = candidate_k.top();
                candidate_k.pop();
            }
            //这里将新的最大值写入栈中
            if(nums[i] > max_k){
                candidate_k.push(nums[i]);
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Pattern132 cls;
    cout << std::boolalpha << cls.find132pattern1(vector<int>{1,2,3,4}) << " -> false" << endl;
    cout << std::boolalpha << cls.find132pattern1(vector<int>{3,1,4,2}) << " -> true" << endl;
    cout << std::boolalpha << cls.find132pattern1(vector<int>{-1,3,2,0}) << " -> true" << endl;
    return 0;
}
