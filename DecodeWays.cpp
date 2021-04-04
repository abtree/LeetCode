#include <iostream>
#include <string>

using namespace std;

//91. 解码方法
class DecodeWays {
    /*
    一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26
    要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"111" 可以将 "1" 中的每个 "1" 映射为 "A" ，从而得到 "AAA" ，或者可以将 "11" 和 "1"（分别为 "K" 和 "A" ）映射为 "KA" 。注意，"06" 不能映射为 "F" ，因为 "6" 和 "06" 不同。
    给你一个只含数字的 非空 字符串 num ，请计算并返回 解码 方法的 总数 。
    题目数据保证答案肯定是一个 32 位 的整数。

    示例 1：
    输入：s = "12"
    输出：2
    解释：它可以解码为 "AB"（1 2）或者 "L"（12）。

    示例 2：
    输入：s = "226"
    输出：3
    解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

    示例 3：
    输入：s = "0"
    输出：0
    解释：没有字符映射到以 0 开头的数字。含有 0 的有效映射是 'J' -> "10" 和 'T'-> "20" 。由于没有字符，因此没有有效的方法对此进行解码，因为所有数字都需要映射。

    示例 4：
    输入：s = "06"
    输出：0
    解释："06" 不能映射到 "F" ，因为字符串开头的 0 无法指向一个有效的字符。 
    */
public:
    int numDecodings(string s) {
        //如果不考虑条件的话 这个题就是 70.爬楼梯问题
        /*
        所以此题的直接思路就是在这上面优化
        70题有 f(x) = f(x-1)+f(x-2)
        此题需要区分 f(x) = f(x-1)+f(x-2)
                    f(x) = f(x-1)
                    f(x) = f(x-2);此时f(x-1)不可达
        */
        if(s[0] == '0')
            return 0;   //以0开头不合法
        int size = s.size();
        if(size == 1)
            return 1;
        if(s[0]>'2' && s[1] == '0')
            return 0;   //这里需要特殊判断 因为下面以第3位开始
        //确认到第二位的方法数量
        int dp2 = 1;
        if(s[0] == '1' && s[1] > '0')
            dp2 = 2;
        if(s[0] == '2' && s[1] > '0' && s[1] < '7')
            dp2 = 2;
        int dp1 = 1;
        for(int i = 2; i < size; ++i){
            if(s[i] == '0'){
                if(s[i-1]!='1' && s[i-1]!='2'){
                    return 0;   //不合法情况
                }else{
                    dp2 = dp1;
                    dp1 = 0;
                    continue;   //f(x) = f(x-2)
                }
            }

            if(s[i -1] == '1'){ //f(x) = f(x-1) + f(x-2)
                int t = dp2;
                dp2 += dp1;
                dp1 = t;
            }else if (s[i-1]=='2' && s[i] < '7'){ //f(x) = f(x-1) + f(x-2)
                int t = dp2;
                dp2 += dp1;
                dp1 = t;
            }else{ //f(x) = f(x-1)
                dp1 = dp2;
            }
        }
        return dp2;
    }
};

int main(int argc, char const* argv[])
{
    DecodeWays cls;
    cout << cls.numDecodings("227") << " -> 2" << endl;
    cout << cls.numDecodings("1201234") << " -> 3" << endl;
    cout << cls.numDecodings("2101") << " -> 1" << endl;
    cout << cls.numDecodings("12") << " -> 2" << endl;
    cout << cls.numDecodings("226") << " -> 3" << endl;
    cout << cls.numDecodings("0") << " -> 0" << endl;
    cout << cls.numDecodings("06") << " -> 0" << endl;
    return 0;
}
