#include <iostream>
#include <vector>
#include <random>
using namespace std;

class RandomPointInNonOverlappingRectangles
{
public:
    RandomPointInNonOverlappingRectangles(const vector<vector<int>> &rects) : mRects(rects)
    {
        arr.clear();
        arr.push_back(0);
        for (auto &rect : rects)
        {
            int end = arr.back();
            end += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            arr.push_back(end);
        }
    }

    vector<int> pick()
    {
        // arr.back()为所有整数点的个数
        uniform_int_distribution<int> dis(0, arr.back() - 1);
        // 随机一个整数点
        int k = dis(gen) % arr.back();
        // 找到整数点所在矩形
        int rectIndex = upper_bound(arr.begin(), arr.end(), k) - arr.begin() - 1;
        // 该点在该矩形中的位置
        k = k - arr[rectIndex];
        // 计算出该点的坐标
        int a = mRects[rectIndex][0], b = mRects[rectIndex][1];
        int y = mRects[rectIndex][3];
        int col = y - b + 1;
        int da = k / col;
        int db = k - col * da;
        return {a + da, b + db};
    }

private:
    vector<int> arr{};
    const vector<vector<int>> mRects;
    mt19937 gen{random_device{}()};
};

void print(const vector<int> &ret)
{
    cout << "[" << ret[0] << "," << ret[1] << "]" << endl;
}
int main(int argc, char const *argv[])
{
    RandomPointInNonOverlappingRectangles cls(vector<vector<int>>{
        {-2, -2, 1, 1},
        {2, 2, 4, 6}});
    print(cls.pick());
    print(cls.pick());
    print(cls.pick());
    print(cls.pick());
    print(cls.pick());
    return 0;
}
