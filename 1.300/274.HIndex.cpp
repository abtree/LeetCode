#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

// 274. H 指数
class HIndex {
    /* 给定一位研究者论文被引用次数的数组（被引用次数是非负整数）。编写一个方法，计算出研究者的 h 指数。
    h 指数的定义：h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。且其余的 N - h 篇论文每篇被引用次数 不超过 h 次。
    例如：某人的 h 指数是 20，这表示他已发表的论文中，每篇被引用了至少 20 次的论文总共有 20 篇。
    */
public:
    int hIndex(vector<int>& citations) {
        /* 排序 (巧妙借用了数组长度与次数的关系)
            如 : 6 5 3 1 0  (引用次数)
                 1 2 3 4 5  (数组长度)
                 T T T F F  (是否满足H)
            很明显可以看出 大于3次的有3篇 为最大取值
        */
       sort(citations.begin(), citations.end(), greater<int>());
       for(int i = citations.size()-1; i >= 0; --i){
           if(citations[i] > i){
               return i+1;
           }
       }
       return 0;
    }
public:
    int hIndex2(vector<int>& citations) {
        //统计排序
        int n = citations.size();
        vector<int> dp(n+1, 0);
        for(int i: citations){
            if(i > n){
                ++dp[n];
            }else{
                ++dp[i];
            }
        }
        int s = 0;  //这个是总值
        for(int i = n; i > 0; --i){
            s += dp[i];
            if(s >= i)
                return i;
        }
        return 0;
    }
};

int main(int argc, char const *argv[]){
    HIndex cls;
    cout << cls.hIndex2(vector<int>{3,0,6,1,5}) << "->3"<<endl;
    cout << cls.hIndex(vector<int>{3,0,6,1,5}) << "->3"<<endl;
    return 0;
}
