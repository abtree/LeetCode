#include <iostream>
#include <string>
#include <vector>

using namespace std;

//32. 最长有效括号
class CLongestValidParentheses{
    /*
    给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

    示例 1:
    输入: "(()"
    输出: 2
    解释: 最长有效括号子串为 "()"

    示例 2:
    输入: ")()())"
    输出: 4
    解释: 最长有效括号子串为 "()()"
    */
public:
    int longestValidParentheses(string s) {
		/*  双层遍历法
			该方法不需要额外开辟空间 但是时间复杂度比较高
		*/ 
        if(s.size() < 2)
            return 0;
		max = 0;
        int begin = 0;
        if(s[0] == ')')
            begin = 1;
        int end = s.size() - 1;
        if(s[end] == '(')
            --end;
        
        for(int i = begin; i < end; ++i){
            maxvalid(s, i, end);
            if(max > end - i)
                return max; //此时后面的字符已经无法超越该值了
        }
		return max;
    }
private:
    void maxvalid(string& s, int b, int end){
        int data = 0;
        for(int i = b; i <= end; ++i){
            if(s[i] == '('){
                ++data;
                if(data > end - i)
                    return; //此时后面已经不够完成有效括号对了
            }else{
                --data;
                if(data < 0)
                    return;     //此时无论后面有什么 都无法构成有效对了
                else if(data == 0){
                    if(i - b + 1 > max)
                        max = i - b + 1;
                }
            }
        }
    }
private:
    int max{};

public:
	int longestValidParentheses2(string s) {
		//动态规划 时间复杂度为O(n) 只需要遍历一次 但是需要开辟额外空间
		if (s.size() < 2)
			return 0;
		vector<int> dp(s.size(), 0);
		int max = 0;
		for (int i = 1; i < s.size(); ++i) {
			if(s[i] == '(')
				continue;
			if (s[i - 1] == '(') {	//这里就是 `()`
				dp[i] = 2;
				if (i - 2 > 0) {
					dp[i] += dp[i - 2];
				}
			}
			else {
				// 这里排除 dp[i - 1]匹配的最大有效子串 的 前一位如果是')' 则从该位到i的字符都是有效的
				if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
					dp[i] = dp[i - 1] + 2;
					if ((i - dp[i - 1]) >= 2) //如果 前一位的前一位也是有效的 则还要加上前面的
						dp[i] += dp[i - dp[i - 1] - 2];
				}
			}
			if (dp[i] > max)
				max = dp[i];
		}
		return max;
	}
};

int main(int argc, char const *argv[])
{
    CLongestValidParentheses cls;
    cout << cls.longestValidParentheses2(")(()())(") << " -> 6" << endl;
    cout << cls.longestValidParentheses2("(()") << " -> 2" << endl;
    cout << cls.longestValidParentheses2(")()())") << " -> 4" << endl;
    return 0;
}
