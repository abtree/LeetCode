#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class ConstructTheRectangle
{
public:
    vector<int> constructRectangle(int area)
    {
        int w = sqrt(1.0 * area);
        while (area % w)
        {
            --w;
        }
        return {area / w, w};
    }
};

void print(vector<int> pair)
{
    cout << "[" << pair[0] << "," << pair[1] << "]" << endl;
}

int main(int argc, char const *argv[])
{
    ConstructTheRectangle cls;
    // [2, 2]
    print(cls.constructRectangle(4));
    // [37, 1]
    print(cls.constructRectangle(37));
    // [427,286]
    print(cls.constructRectangle(122122));
    return 0;
}
