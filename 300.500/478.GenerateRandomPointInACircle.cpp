#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Solution
{
public:
    Solution(double radius, double x_center, double y_center)
        : dis(-radius, radius), xc(x_center), yc(y_center), r(radius)
    {
    }

    vector<double> randPoint()
    {
        // 在一个正方形取点
        // 并且排除在圆外的点
        while (true)
        {
            double x = dis(gen), y = dis(gen);
            // 根据勾股定理
            if (x * x + y * y <= r * r)
            {
                return {xc + x, yc + y};
            }
        }
    }

private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    double xc, yc, r;
};

class Solution1
{
public:
    Solution1(double radius, double x_center, double y_center)
        : dis(0, 1), xc(x_center), yc(y_center), r(radius)
    {
    }

    vector<double> randPoint1()
    {
        double u = dis(gen);
        double theta = dis(gen) * 2 * acos(-1.0);
        double r = sqrt(u);
        return {xc + r * cos(theta) * this->r, yc + r * sin(theta) * this->r};
    }

private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    double xc, yc, r;
};

void Print(vector<double> d)
{
    cout << "[" << d[0] << "," << d[1] << "]" << endl;
}

int main(int argc, char const *argv[])
{
    Solution cls(1.0, 0.0, 0.0);
    Print(cls.randPoint());
    Print(cls.randPoint());
    Print(cls.randPoint());

    Solution1 cls1(1.0, 0.0, 0.0);
    Print(cls1.randPoint1());
    Print(cls1.randPoint1());
    Print(cls1.randPoint1());
    return 0;
}
