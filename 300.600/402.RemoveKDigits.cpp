#include <iostream>
#include <string>

using namespace std;

class RemoveKDigits{
public:
    string removeKdigits(string num, int k) {
        /*
            从左到右，移除第一个前面比后面大的字符
            如：143 移除4
            重复k次
        */
        for (int i = 0; i < k;++i) {
            int s = num.size()-1;
            int j = 0;
            for (; j < s;++j) {
                if (num[j] > num[j + 1]) {
                    num.erase(j, 1);
                    break;
                }
            }
            if (j == s) {
                num.pop_back();
            }
        }
        while (!num.empty() && num[0] == '0')
            num.erase(0, 1);
        if (num.empty())
            return "0";
        return num;
    }
};

int main(int argc, char const* argv[]) {
    RemoveKDigits cls;
    cout << cls.removeKdigits("1432219", 3).c_str() << " -> 1219" << endl;
    cout << cls.removeKdigits("10200", 1).c_str() << " -> 200" << endl;
    cout << cls.removeKdigits("10", 2).c_str() << " -> 0" << endl;
    return 0;
}
