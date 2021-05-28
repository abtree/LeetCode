#include <iostream>
#include <algorithm>
using namespace std;

class RectangleArea {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area = (ax2 - ax1) * (ay2 - ay1);
        area += (bx2 - bx1) * (by2 - by1);
        if (ax1 > bx2 || ax2 < bx1)
            return area;   //不相交
        if (ay1 > by2 || ay2 < by1)
            return area;   //不相交
        ax1 = max(ax1, bx1);
        ax2 = min(ax2, bx2);
        bx1 = ax2 - ax1;
        ay1 = max(ay1, by1);
        ay2 = min(ay2, by2);
        by1 = ay2 - ay1;
        return area - bx1 * by1;
    }
};

int main(int argc, char const* argv[])
{
    RectangleArea cls;
    cout << cls.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << " -> 45" << endl;
    cout << cls.computeArea(-2, -2, 2, 2, -2, -2, 2, 2) << " -> 16" << endl;
    return 0;
}
