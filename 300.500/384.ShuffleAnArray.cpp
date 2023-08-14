#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

class ShuffleAnArray{
public:
    ShuffleAnArray(vector<int>& nums) {
        orinum = nums;
        randnum = nums;
        srand(time(nullptr));
    }
    
    vector<int> reset() {
        return orinum;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i< randnum.size(); ++i){
            int p = rand()%(randnum.size()-i)+i;
            swap(randnum[i], randnum[p]);
        }
        return randnum;
    }
private:
    vector<int> orinum;
    vector<int> randnum;
};

int main(int argc, char const *argv[]){
    ShuffleAnArray cls(vector<int>{1,2,3});
    cls.shuffle();
    cls.reset();
    cls.shuffle();
    return 0;
}
