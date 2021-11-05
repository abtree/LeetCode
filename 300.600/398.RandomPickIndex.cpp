#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

//蓄水池
class RandomPickIndex {
public:
    RandomPickIndex(vector<int>& nums) {
        begin = nums.begin();
        end = nums.end();
    }
    
    int pick(int target) {
        int i = 0;
        int cnt = 0;
        int ret = 0;
        for (auto it = begin; it != end; ++it) {
            if (*it == target) {
                ++cnt;
                if (rand() % cnt == 0)
                    ret = i;
            }
            ++i;
        }
        return ret;
    }
private:
    vector<int>::iterator begin;
    vector<int>::iterator end;
};

int main(int argc, char const *argv[])
{
    srand(time(nullptr));
    vector<int> list{ 1,2,3,3,3 };
    RandomPickIndex cls(list);
    cout << cls.pick(3) << " " << cls.pick(3) << " " << cls.pick(3) << endl;
    cout << cls.pick(3) << " " << cls.pick(1) << " " << cls.pick(2) << endl;
    return 0;
}
