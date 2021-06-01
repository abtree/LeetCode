#include <iostream>
#include <vector>

using namespace std;

// 216. 组合总和 III
class CombinationSum3
{
    /* 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
    说明：所有数字都是正整数。解集不能包含重复的组合。 
    */
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ret.clear();
        tmp.clear();
        combination(k, n, 0, 0);
        return ret;
    }
private:
    void combination(int k, int n, int p, int sum){
        for (int i = p+1; i < 10; ++i) {
            if(k > 1){
                tmp.push_back(i);
                sum += i;
                combination(k-1,n,i,sum);
                tmp.pop_back();
                sum -= i;
            }else{
                if (sum + i == n) {
                    tmp.push_back(i);
                    ret.emplace_back(tmp);
                    tmp.pop_back();
                    return;
                }
            }
        }
    }
private:
    vector<vector<int>> ret;
    vector<int> tmp;
};

int main(int argc, char const* argv[])
{
    CombinationSum3 cls;
    auto &ret = cls.combinationSum3(3, 7);
    cout << "[";
    for(auto &it : ret){
        cout << "[";
        for(auto it1 : it){
            cout << it1 << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    auto &ret1 = cls.combinationSum3(3, 9);
    cout << "[";
    for(auto &it : ret1){
        cout << "[";
        for(auto it1 : it){
            cout << it1 << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
    return 0;
}
