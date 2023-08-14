#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class NumberOfSegmentsInAString{
public:
    int countSegments(string s) {
        stringstream ss(s);
        string str = "";
        int cnt = 0;
        while (ss >> str) {
            ++cnt;
        }
        return cnt;
    }
};

int main(int argc, char const* argv[])
{
    NumberOfSegmentsInAString cls;
    cout << cls.countSegments("Hello, my name is John") << " -> 5" << endl;
    return 0;
}
