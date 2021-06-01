#include <iostream>
#include <string>

using namespace std;

//168. Excel表列名称
class ExcelSheetColumnTitle
{
    /*给定一个正整数，返回它在 Excel 表中相对应的列名称。
    */
public:
    string convertToTitle(int columnNumber) {
        string ret = "";
        while (columnNumber > 26)
        {
            int rem = columnNumber % 26;
            columnNumber /= 26;
            if (rem == 0) {
                ret.push_back('Z');
                columnNumber -= 1;
            }
            else {
                ret.push_back(rem - 1 + 'A');
            }
        }
        ret += columnNumber - 1 + 'A';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(int argc, char const* argv[])
{
    ExcelSheetColumnTitle cls;
    cout << cls.convertToTitle(2600).c_str() << " -> CUZ" << endl;
    cout << cls.convertToTitle(52).c_str() << " -> AZ" << endl;
    cout << cls.convertToTitle(1).c_str() << " -> A" << endl;
    cout << cls.convertToTitle(28).c_str() << " -> AB" << endl;
    cout << cls.convertToTitle(710).c_str() << " -> AAH" << endl;
    cout << cls.convertToTitle(701).c_str() << " -> ZY" << endl;
    return 0;
}
