#pragma once

//67. 二进制求和
class AddBinary {
    /*
    给你两个二进制字符串，返回它们的和（用二进制表示）。
    输入为 非空 字符串且只包含数字 1 和 0。

    示例 1:
    输入: a = "11", b = "1"
    输出: "100"

    示例 2:
    输入: a = "1010", b = "1011"
    输出: "10101"
     
    提示：
    每个字符串仅由字符 '0' 或 '1' 组成。
    1 <= a.length, b.length <= 10^4
    字符串如果不是 "0" ，就都不含前导零。
    */
public:
    string addBinary(string a, string b) {
        if (a.empty())
            return b;
        if (b.empty())
            return a;

        string str(max(a.size(), b.size()), '0');   //以较长字符串为长度
        int i = a.size() - 1;
        int j = b.size() - 1;
        int k = 0;
        char e = '0';
        while (i > -1 || j > -1) {
            char c = AddBinChar((i > -1 ? a[i] : '0'), (j > -1 ? b[j] : '0'), e);   //这里要判断是否有一个字符串已经取完了
            if (c < '2') {
                str[k] = c;
                e = '0';
            }
            else if (c == '2') {
                str[k] = '0';
                e = '1';
            }
            else {  //c == '3'  进位 取1
                str[k] = '1';
                e = '1';
            }
            --i;
            --j;
            ++k;
        }
        if (e != '0') {
            str.push_back('1'); //最后进位
        }
        std::reverse(str.begin(), str.end());
        return str;
    }
private:
    //求两个位相加 返回 0，1，2（进位取0）, 3(进位取1)
    char AddBinChar(char a, char b, char e) {
        char ret = '0';
        if (a == '0' && b == '1') {
            ret = '1';
        }
        else if (a == '1' && b == '0') {
            ret = '1';
        }
        else if (a == '1' && b == '1') {
            ret = '2';   //进位取‘0’
        }
        if (e == '0')
            return ret;
        return ret + 1;
    }
public:
    static void Test() {
        AddBinary cls;
        cout << cls.addBinary("11", "1").c_str() << " -> 100" << endl;
        cout << cls.addBinary("1010", "1011").c_str() << " -> 10101" << endl;
    }
};