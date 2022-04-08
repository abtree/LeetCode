#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class AddStrings{
public:
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        int size = min(m, n);
        int add = 0;
        string ret = "";
        for (int i = 1; i <= size; ++i) {
            int x = (num1[m - i] - '0') + (num2[n - i] - '0') + add;
            if (x >= 10) {
                x -= 10;
                add = 1;
            }
            else {
                add = 0;
            }
            ret.push_back(x + '0');
        }
        if (m > size) {
            for (int i = m-size-1; i >= 0; --i) {
                if (add > 0) {
                    int x = num1[i] - '0' + add;
                    if (x >= 10) {
                        x -= 10;
                        add = 1;
                    }
                    else {
                        add = 0;
                    }
                    ret.push_back(x + '0');
                }
                else {
                    ret.push_back(num1[i]);   
                }
            }
        }
        if (n > size) {
            for (int i = n-size-1; i >= 0; --i) {
                if (add > 0) {
                    int x = num2[i] - '0' + add;
                    if (x >= 10) {
                        x -= 10;
                        add = 1;
                    }
                    else {
                        add = 0;
                    }
                    ret.push_back(x + '0');
                }
                else {
                    ret.push_back(num2[i]);   
                }
            }
        }
        if (add > 0) {
            ret.push_back('1');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(int argc, char const* argv[]) {
    AddStrings cls;
    cout << cls.addStrings("6", "501").c_str() << " -> 507" << endl;
    cout << cls.addStrings("11", "123").c_str() << " -> 134" << endl;
    cout << cls.addStrings("456", "77").c_str() << " -> 533" << endl;
    cout << cls.addStrings("0", "0").c_str() << " -> 0" << endl;
    return 0;
}
