#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class PoorPigs{
public:
    /* 需要用到的两个公式
        C(i,0) = C(i,i) = 1
        [0 < j < i] => C(i, j) = C(i-1,j-1) + C(i-1, j)
        f(i, j) = sum(k = [0,i]) => f(k,j-1) * C(i,k)
    */
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets == 1){
            return 0;
        }
        vector<vector<int>> c(buckets+1,vector<int>(buckets+1));
        c[0][0] = 1;
        int turn = minutesToTest / minutesToDie;
        vector<vector<int>> f(buckets, vector<int>(turn+1));
        for(int i =0;i<buckets;++i){
            c[i][0] = 1;
            c[i][i] = 1;
            f[i][0] = 1;
        }
        for(int j =0;j<=turn;++j){
            f[0][j] = 1;
        }
        for(int i =1;i<buckets;i++){
            for(int j = 1;j<i;j++){
                c[i][j] = c[i-1][j-1] + c[i-1][j];
            }
            for(int j = 1; j <= turn;++j){
                for(int k = 0; k <= i;++k){
                    f[i][j] += f[k][j-1]*c[i][k];
                }
            }
            if(f[i][turn] >= buckets){
                return i;
            }
        }
        return 0;
    }
    int poorPigs1(int buckets, int minutesToDie, int minutesToTest) {
        int states = minutesToTest / minutesToDie + 1;
        int pigs = ceil(log(buckets)/log(states) - 1e-5);
        return pigs;
    }
};

int main(int argc, char const *argv[])
{
    PoorPigs cls;
    cout << cls.poorPigs1(1000, 15, 60) << " -> 5" << endl;
    cout << cls.poorPigs1(4, 15, 15) << " -> 2" << endl;
    cout << cls.poorPigs1(4, 15, 30) << " -> 2" << endl;
    return 0;
}
