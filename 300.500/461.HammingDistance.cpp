#include <iostream>
#include <bitset>
using namespace std;

class HammingDistance{
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int ret = 0;
        while(z > 0){
            z = z & (z-1);
            ret++;
        }
        return ret;
    }
public:
    int hammingDistance1(int x, int y) {
        int z = x ^ y;
        int ret = 0;
        while(z > 0){
            ret += z & 1;
            z = z >> 1;
        }
        return ret;
    }
public:
    int hammingDistance2(int x, int y) {
        bitset<32> bs(x ^ y);
        return bs.count();
    }
};

int main(int argc, char const *argv[]){
    HammingDistance cls;
    cout << cls.hammingDistance2(1,4) << " -> 2" << endl;
    cout << cls.hammingDistance2(3,1) << " -> 1" << endl;
    return 0;
}
