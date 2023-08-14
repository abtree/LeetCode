#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FizzBuzz{
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret(n);
        for (int i = 1; i <= n;++i) {
            if (i % 3 == 0 && i % 5 == 0) {
                ret[i-1] = "FizzBuzz";
            }
            else if (i % 3 == 0) {
                ret[i-1] = "Fizz";
            }
            else if (i % 5 == 0) {
                ret[i-1] = "Buzz";
            }
            else {
                ret[i-1] = to_string(i);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    FizzBuzz cls;
    
    vector<string>& ret = cls.fizzBuzz(3);
    cout << "[";
    for (string& s : ret) {
        cout << s.c_str() << ",";
    }
    cout << "]" << endl;
    
    vector<string>& ret1 = cls.fizzBuzz(5);
    cout << "[";
    for (string& s : ret1) {
        cout << s.c_str() << ",";
    }
    cout << "]" << endl;
    
    vector<string>& ret2 = cls.fizzBuzz(15);
    cout << "[";
    for (string& s : ret2) {
        cout << s.c_str() << ",";
    }
    cout << "]" << endl;
    return 0;
}
