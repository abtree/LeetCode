#pragma once

//65. 有效数字
class VaildNumber {
    /*
    验证给定的字符串是否可以解释为十进制数字。
    说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。这里给出一份可能存在于有效十进制数字中的字符列表：
    数字 0-9
    指数 - "e"
    正/负号 - "+"/"-"
    小数点 - "."
    当然，在输入中，这些字符的上下文也很重要。
    */
public:
    bool isNumber(string s) {
        int size = s.size();
        if (size == 0)
            return false;   //空字符串
        --size;
        bitset<5> flag; //0 number; 1 +-; 2 .; 3 e; 4 space
        for (int i = 0; i <= size; ++i) {
            if (std::isdigit(s[i])) {
                if (flag.test(4))
                    return false;   //空字符
                flag.set(0);    //标记已经有数字
                continue;
            }
            if (s[i] == '+' || s[i] == '-') { //如果是正负号
                if (i > 0 && s[i - 1] == 'e') {
                    if (i == size)
                        return false; //最后一位了
                    flag.set(1);    //e 后面可以跟一个正负号
                    continue;
                }
                if (flag.test(0))
                    return false;   //已经先有数字了
                if (flag.test(1))
                    return false;   //判断是否已经有正负号了
                if (flag.test(2))
                    return false;   //判断是否已经有小数点了
                if (i == size)
                    return false;   //最后一位了
                flag.set(1);
                continue;
            }
            if (s[i] == '.') { //如果是小数点
                //if (!flag.test(0))
                //   return false;   //如果小数点前面没有数字 
                if (flag.test(3))
                    return false;   //小数点前面有e
                if (flag.test(2))
                    return false;   //小数点前面有小数点
                //if (i == size)
                //    return false;   //最后一位了
                if (flag.test(4))
                    return false;   //空字符
                flag.set(2);
                continue;
            }
            if (s[i] == 'e') {  //如果是e
                if (!flag.test(0))
                    return false;   //如果e前面没有数字 
                if (flag.test(3))
                    return false;   //e前面有e
                if (i == size)
                    return false;   //最后一位了
                flag.set(3);
                continue;
            }
            if (std::isspace(s[i])) {    //空字符
                if (!flag.any())
                    continue;   //如果空字符前面啥都没有 忽略
                if (!std::isdigit(s[i - 1]) && !std::isspace(s[i - 1]) && s[i - 1] != '.')
                    return false;   //空字符前面不是数字(也不是空字符)
                if (!flag.test(4)) {
                    flag.set(4);
                    continue;   //第二次出现空字符
                }
                if (!std::isspace(s[i - 1]))
                    return false;   //上一个不是空字符
                continue;
            }
            return false;
        }
        return flag.test(0);
    }
public:
    static void Test() {
        VaildNumber cls;
        cout << boolalpha << cls.isNumber("1 .") << " -> true" << endl;
        cout << boolalpha << cls.isNumber("0") << " -> true" << endl;
        cout << boolalpha << cls.isNumber(" 0.1 ") << " -> true" << endl;
        cout << boolalpha << cls.isNumber("abc") << " -> false" << endl;
        cout << boolalpha << cls.isNumber("1 a") << " -> false" << endl;
        cout << boolalpha << cls.isNumber("2e10") << " -> true" << endl;
        cout << boolalpha << cls.isNumber(" -90e3   ") << " -> true" << endl;
        cout << boolalpha << cls.isNumber(" 1e") << " -> false" << endl;
        cout << boolalpha << cls.isNumber("e3") << " -> false" << endl;
        cout << boolalpha << cls.isNumber(" 6e-1") << " -> true" << endl;
        cout << boolalpha << cls.isNumber(" 99e2.5 ") << " -> false" << endl;
        cout << boolalpha << cls.isNumber("53.5e93") << " -> true" << endl;
        cout << boolalpha << cls.isNumber(" --6 ") << " -> false" << endl;
        cout << boolalpha << cls.isNumber("-+3") << " -> false" << endl;
        cout << boolalpha << cls.isNumber("95a54e53") << " -> false" << endl;
        cout << boolalpha << cls.isNumber("  .1  ") << " -> true" << endl;
        cout << boolalpha << cls.isNumber("  3.  ") << " -> true" << endl;
    }
};