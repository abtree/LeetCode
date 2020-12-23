#pragma once

class LenOfLastWord {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;
        //先去除空格
        int size = s.size() - 1;
        for (;size >= 0;--size) {
            if (s[size] != ' ')
                break;
        }
        //计算最后一个单词的长度
        int ret = 0;
        for (;size >= 0;--size) {
            if (s[size] == ' ')
                break;
            ++ret;
        }
        return ret;
    }
public:
    static void Test() {
        LenOfLastWord cls;
        cout << cls.lengthOfLastWord("Hello World") << " -> 5" << endl;
        cout << cls.lengthOfLastWord("Hello World     ") << " -> 5" << endl;
    }
};