#include <iostream>
#include <string>
#include <array>
using namespace std;

//273. 整数转换英文表示
class IntegerToEnglishWords {
    /* 将非负整数 num 转换为其对应的英文表示。
    */
public:
    string numberToWords(int num) {
        if (num == 0) {
            return less20[0];
        }
        //分段
        string ret = "";
        int div = 1e9;
        if (num >= div) {
            ret += trinums(num / div) + "Billion ";
            num %= div;
        }
        div /= 1e3;
        if (num >= div) {
            ret += trinums(num / div) + "Million ";
            num %= div;
        }
        div /= 1e3;
        if (num >= div) {
            ret += trinums(num / div) + "Thousand ";
            num %= div;
        }
        if (num > 0) {
            ret += trinums(num);
        }
        ret.pop_back();
        return ret;
    }
private:
    string trinums(int num) {
        string ret = "";
        int tail = num % 100;
        num /= 100;
        if (num > 0) {
            ret += less20[num] + "Hundred ";
        }
        if (tail == 0)
            return ret;
        if (tail < 20) {
            ret += less20[tail];
        }
        else {
            num = tail / 10;
            tail %= 10;
            ret += tens[num - 2];
            if (tail > 0) {
                ret += less20[tail];
            }
        }
        return ret;
    }
private:
    array<string, 20> less20{
        "Zero","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ",
        "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "
    };
    array<string, 8> tens{
        "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "
    };
};

int main(int argc, char const* argv[]) {
    IntegerToEnglishWords cls;
    cout << "0:" << cls.numberToWords(0).c_str() << endl;
    cout << "123:" << cls.numberToWords(123).c_str() << endl;
    cout << "12345:" << cls.numberToWords(12345).c_str() << endl;
    cout << "1234567:" << cls.numberToWords(1234567).c_str() << endl;
    cout << "1234567891:" << cls.numberToWords(1234567891).c_str() << endl;
    return 0;
}
