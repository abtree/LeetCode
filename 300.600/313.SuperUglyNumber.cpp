#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_set>
#include <algorithm>
#include <set>

using namespace std;

//313. 超级丑数
class SuperUglyNumber {
    /* 编写一段程序来查找第 n 个超级丑数。超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。
    */
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        //优先队
        priority_queue<long long, vector<long long>, greater<long long>> queue;
        unordered_set<long long> repeated;
        queue.push(1);
        long long cur = 1;
        repeated.insert(1);
        while (n > 0){
            cur = queue.top();
            queue.pop();
            --n;
            for(long long c : primes){
                c*=cur;
                if(repeated.find(c) == repeated.end()){
                    queue.push(c);
                    repeated.insert(c);
                }
            }
        }
        return cur;
    }
public:
    int nthSuperUglyNumber2(int n, vector<int>& primes) {
        //优先队(set版本)
        set<long long> queue;
        queue.insert(1);
        long long cur = 1;
        while (n > 0){
            cur = *queue.begin();
            queue.erase(cur);
            --n;
            for(long long c : primes){
                queue.insert(c*cur);
            }
        }
        return cur;
    }
public:
    int nthSuperUglyNumber1(int n, vector<int>& primes) {
        //动态规划
        vector<long long> dp(n);
        dp[0] = 1;
        int size = primes.size();
        vector<int> pos(size, 0);
        vector<long long> values(size);
        for(int i = 1;i<n;++i){
            for(int j = 0; j< size; ++j){
                values[j] = primes[j]*dp[pos[j]];
            }
            dp[i] = *min_element(values.begin(), values.end());
            for(int j = 0; j< size; ++j){
                if(values[j] == dp[i]){
                    ++pos[j];
                }
            }
        }
        return dp[n-1];
    }
};

int main(int argc, char const *argv[]){
    SuperUglyNumber cls;
    cout << cls.nthSuperUglyNumber2(12, vector<int>{2,7,13,19}) << " -> 32" << endl;
    return 0;
}
