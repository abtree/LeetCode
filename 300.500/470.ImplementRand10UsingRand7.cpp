#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int rand7(){
    return rand()%7 + 1;
}

class ImplementRand10UsingRand7{
public:
    int rand10() {
        int row, col, idx;
        do{
            row = rand7();
            col = rand7();
            idx = col + (row-1)*7;
        }while(idx > 40);
        return 1 + (idx - 1) % 10;
    }
};

int main(int argc, char const *argv[])
{
    ImplementRand10UsingRand7 cls;
    cout << "[";
    for(int i =0;i<100;++i){
        cout << cls.rand10() << " , ";
    }
    cout << "]" << endl;
    return 0;
}
