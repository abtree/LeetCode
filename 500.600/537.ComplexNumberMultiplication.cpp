#include <iostream>
#include <string>
using namespace std;

class ComplexNumberMultiplication
{
public:
    string complexNumberMultiply(string num1, string num2)
    {
        int a1, b1, a2, b2;
        split(num1, a1, b1);
        split(num2, a2, b2);
        int a = a1 * a2 - b1 * b2;
        int b = a1 * b2 + b1 * a2;
        return to_string(a) + "+" + to_string(b) + "i";
    }

private:
    void split(string &num, int &a, int &b)
    {
        int n = num.size();
        int i = num.find('+');
        a = atoi(num.c_str());
        b = atoi(num.substr(i + 1, n - i - 2).c_str());
    }
};

int main()
{
    ComplexNumberMultiplication cls;
    cout << cls.complexNumberMultiply("1+-1i", "0+0i").c_str() << " -> 0+0i" << endl;
    cout << cls.complexNumberMultiply("1+1i", "1+1i").c_str() << " -> 0+2i" << endl;
    cout << cls.complexNumberMultiply("1+-1i", "1+-1i").c_str() << " -> 0-2i" << endl;
    return 0;
}
