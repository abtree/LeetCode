#include <iostream>
#include <vector>

using namespace std;

//96. 不同的二叉搜索树
class UniqueBinarySearchTrees{
    //给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
public:
    int numTrees(int n) {
        //公式1 G(n)=G(i-1)G(n-i)|i=1...n
        vector<int> G(n+1, 0);
        G[0]=1;
        G[1]=1;
        for(int i = 2; i<= n;++i){
            for(int j = 1;j<=i;++j){
                G[i]+=G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
public:
    int numTrees2(int n) {
        //卡塔兰数Cn
        //C0 = 1, Cn+1 = [2(2n+1)/(n+2)]Cn
        long long C =1;
        for(int i = 0; i< n;++i){
            C = C*2*(2*i+1)/(i+2);
        }
        return (int)C;
    } 
};

int main(int argc, char const *argv[])
{
    UniqueBinarySearchTrees cls;
    cout << cls.numTrees2(3) << " -> 5" << endl;
    cout << cls.numTrees2(8) << " -> 1430" << endl;
    return 0;
}
