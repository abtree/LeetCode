#include <iostream>
#include <vector>
using namespace std;

class CircularArrayLoop{
public:
    bool circularArrayLoop(vector<int> nums) {
        int n = nums.size();
        auto next = [&](int cur){
            //保证 最后结果一定在[0,n]之间
            return ((cur+nums[cur])%n+n)%n;
        };
        for(int i =0;i<n;++i){
            //标记nums[i]已经访问过了
            if(!nums[i])
                continue;
            int slow = i, fast = next(i);
            //保证nums[slow]和nums[fast]非0且符号相同(题目要求)
            while(nums[slow]*nums[fast] > 0 && nums[slow]*nums[next(fast)] >0){
                if(slow == fast){
                    if(slow != next(slow)){
                        return true;
                    }else{
                        //改环长度为1 不满足题目要求
                        break;
                    }
                }
                slow = next(slow);
                fast = next(next(fast));
            }
            //将访问过的点都标记为0
            int add = i;
            while(nums[add] * nums[next(add)] > 0){
                int tmp = add;
                add = next(add);
                nums[tmp] = 0;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    CircularArrayLoop cls;
    cout << boolalpha << cls.circularArrayLoop(vector<int>{2,-1,1,2,2}) << " -> true" << endl;
    cout << boolalpha << cls.circularArrayLoop(vector<int>{-1,2}) << " -> false" << endl;
    cout << boolalpha << cls.circularArrayLoop(vector<int>{-2,1,-1,-2,-2}) << " -> false" << endl;
    cout << boolalpha << cls.circularArrayLoop(vector<int>{1,-1,5,1,4}) << " -> true" << endl;
    cout << boolalpha << cls.circularArrayLoop(vector<int>{-1,-2,-3,-4,-5,6}) << " -> false" << endl;
    return 0;
}
