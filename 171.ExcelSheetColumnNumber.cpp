#include <iostream>
#include <string>

using namespace std;

// 171. Excel表列序号
class ExcelSheetColumnNumber
{
    /* 给定一个Excel表格中的列名称，返回其相应的列序号。
    */
public:
    int titleToNumber(string columnTitle) {
        int col = 0;
        for (int i = 0; i < columnTitle.size(); ++i) {
            col = col * 26 + (columnTitle[i] - 'A' + 1);
        }
        return col;
    }
};

int main(int argc, char const* argv[])
{
    ExcelSheetColumnNumber cls;
    cout << cls.titleToNumber("A") << " -> 1" << endl;
    cout << cls.titleToNumber("AB") << " -> 28" << endl;
    cout << cls.titleToNumber("ZY") << " -> 701" << endl;
    cout << cls.titleToNumber("CUZ") << " -> 2600" << endl;
    cout << cls.titleToNumber("AAH") << " -> 710" << endl;
    return 0;
}
