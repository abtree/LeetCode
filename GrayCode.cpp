#include <iostream>
#include <vector>

using namespace std;

//89. 格雷编码
class GaryCode {
    /*
    格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。即使有多个不同答案，你也只需要返回其中一种。格雷编码序列必须以 0 开头。

    示例 1:
    输入: 2
    输出: [0,1,3,2]
    解释:
    00 - 0
    01 - 1
    11 - 3
    10 - 2
    对于给定的 n，其格雷编码序列并不唯一。
    例如，[0,2,3,1] 也是一个有效的格雷编码序列。
    00 - 0
    10 - 2
    11 - 3
    01 - 1

    示例 2:
    输入: 0
    输出: [0]
    解释: 我们定义格雷编码序列必须以 0 开头。给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。因此，当 n = 0 时，其格雷编码序列为 [0]。
    */
public:
    vector<int> grayCode(int n) {
        int powN = 1 << n;  //将1移动n位，即使求n的平方，即格雷编码会产生n的平方个结果
        vector<int> ans(powN, 0);
        for(int i = 0; i < powN; ++i)
            ans[i] = i^i>>1;  // i 异或 (i / 2)
        return ans;
    }
public:
    vector<int> grayCode2(int n) {
        vector<int> ans={0};
        if(n==0)
            return ans;
        ans ={0,1 };
        for(int i=1 ;i<n ;i++ ){
            int lenth = ans.size();
            int addi = (1<<i);
            for( int j=0;j<lenth ;j++ ){
                ans.push_back( ans[ lenth- j-1]+addi );
            }
        }
        return ans;
    }
};

int main(int argc, char const* argv[])
{
    GaryCode cls;
    auto& ret1 = cls.grayCode(2);
    cout << "[";
    for(auto it : ret1){
        cout << it << ",";
    }
    cout << "]" << endl;

    auto& ret2 = cls.grayCode(0);
    cout << "[";
    for(auto it : ret2){
        cout << it << ",";
    }
    cout << "]" << endl;
    return 0;
}
