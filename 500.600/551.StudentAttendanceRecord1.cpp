#include <iostream>
#include <string>
using namespace std;

class StudentAttendanceRecord1
{
public:
    bool checkRecord(string s)
    {
        int as = 0;
        int ls = 0;
        for (char c : s)
        {
            if (c == 'A')
            {
                ++as;
                if (as > 1)
                {
                    return false;
                }
                ls = 0;
            }
            else if (c == 'L')
            {
                ++ls;
                if (ls > 2)
                {
                    return false;
                }
            }
            else
            {
                ls = 0;
            }
        }
        return true;
    }
};

int main()
{
    StudentAttendanceRecord1 cls;
    cout << boolalpha << cls.checkRecord("PPALLP") << " -> true" << endl;
    cout << boolalpha << cls.checkRecord("PPALLL") << " -> false" << endl;
    return 0;
}
