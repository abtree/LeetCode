#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class QueueReconstructionByHeight
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //先排序 身高按从高到低(优先) 人数按从低到高
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] < b[0])
                return false;
            if (a[0] == b[0] && a[1] > b[1])
                return false;
            return true;
            });
        //再重新排序 人数即为插入位置
        for (int i = 0; i < people.size();++i) {
            if (i > people[i][1]) {
                int ta = people[i][0];
                int tb = people[i][1];
                int j = i;
                while (j > tb)
                {
                    people[j] = people[j - 1];
                    --j;
                }
                people[j][0] = ta;
                people[j][1] = tb;
            }
        }
        return people;
    }
};

int main(int argc, char const* argv[]) {
    QueueReconstructionByHeight cls;
    auto& ret = cls.reconstructQueue(vector<vector<int>>{ {7, 0}, { 4,4 }, { 7,1 }, { 5,0 }, { 6,1 }, { 5,2 }});
    cout << "[";
    for (auto& it : ret) {
        cout << "[" << it[0] << "," << it[1] << "],";
    }
    cout << "]" << endl;

    auto& ret1 = cls.reconstructQueue(vector<vector<int>>{ {6, 0}, { 5,0 }, { 4,0 }, { 3,2 }, { 2,2 }, { 1,4 }});
    cout << "[";
    for (auto& it : ret1) {
        cout << "[" << it[0] << "," << it[1] << "],";
    }
    cout << "]" << endl;
    
    return 0;
}
