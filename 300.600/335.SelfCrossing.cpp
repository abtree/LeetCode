#include <iostream>
#include <vector>
using namespace std;

// 335. 路径交叉
class SelfCrossing {
public:
    bool isSelfCrossing(vector<int>& distance) {
        /*  这里不相交只有三种情况
            1、圈一直扩大
            2、圈一直缩小
            3、圈先扩大，再在另一个地方一直缩小(注意由扩大变缩小的边界情况)
            注意：先缩小再扩大是一定相交的
        */
        //在头上插入4个元素， 避免处理边界问题(这里必须插入4个0 否则解是不对的)
        distance.insert(distance.begin(), 4, 0);
        int size = distance.size();
        int i = 4;
        //圈一直扩大的情况
        while (i < size && distance[i] > distance[i - 2])
            ++i;
        if (i == size)
            return false;   //圈一直扩大 所以不相交
        //这里是处理两个圈相交的情况
        if (distance[i] >= distance[i - 2] - distance[i - 4])
            distance[i - 1] -= distance[i - 3];
        //圈一直缩小(这里圈不能在扩大了，扩大一定相交)
        ++i;
        while (i < size && distance[i] < distance[i - 2])
            ++i;
        return i != size;
    }
public:
    bool isSelfCrossing2(vector<int>& distance) {
        //不拷贝数组的情况
        int size = distance.size();
        if (size < 4) {
            return false;
        }
        int i = 2;
        while (i < size && distance[i] > distance[i - 2])
            ++i;
        if (i == size) {
            return false;
        }
        if ((i == 3 && distance[i] == distance[i - 2]) || (i > 3 && distance[i] >= distance[i - 2] - distance[i - 4]))
            distance[i - 1] -= distance[i - 3];
        ++i;
        while (i < size && distance[i] < distance[i - 2]) {
            ++i;
        }
        return i != size;
    }
public:
    bool isSelfCrossing1(vector<int>& distance) {
        //直接判断相交情况
        int n = distance.size();
        for (int i = 3;i < n;i++) {
            if (i >= 3 && distance[i - 3] >= distance[i - 1] && distance[i] >= distance[i - 2])
                return true;
            else if (i >= 4 && distance[i - 3] == distance[i - 1] && distance[i - 2] >= distance[i - 4] && (distance[i - 4] + distance[i]) >= distance[i - 2])  // 图如： 1, 1, 2, 1, 1
                return true;
            else if (i >= 5 && distance[i - 4] <= distance[i - 2] && distance[i - 3] >= distance[i - 5] && distance[i - 3] >= distance[i - 1] && (distance[i - 5] + distance[i - 1]) >= distance[i - 3] && (distance[i - 4] + distance[i]) >= distance[i - 2])
                return true;    // 图如： 1, 1, 2, 2, 1, 1
        }
        return false;
    }
};

int main(int argc, char const* argv[]) {
    SelfCrossing cls;
    cout << boolalpha << cls.isSelfCrossing2(vector<int>{1, 1, 2, 2, 1, 1}) << " -> true" << endl;
    cout << boolalpha << cls.isSelfCrossing2(vector<int>{1, 1, 2, 3, 3, 3, 1}) << " -> true" << endl;
    cout << boolalpha << cls.isSelfCrossing2(vector<int>{1, 1, 2, 1, 1}) << " -> true" << endl;
    cout << boolalpha << cls.isSelfCrossing2(vector<int>{2, 1, 1, 2}) << " -> true" << endl;
    cout << boolalpha << cls.isSelfCrossing2(vector<int>{1, 2, 3, 4}) << " -> false" << endl;
    cout << boolalpha << cls.isSelfCrossing2(vector<int>{1, 1, 1, 1}) << " -> true" << endl;
    cout << boolalpha << cls.isSelfCrossing2(vector<int>{1, 4, 3, 2, 5}) << " -> true" << endl;
    return 0;
}
