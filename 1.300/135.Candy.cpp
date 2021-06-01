#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//135. 分发糖果
class Candy
{
    /*老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。你需要按照以下要求，帮助老师给这些孩子分发糖果：
    每个孩子至少分配到 1 个糖果。评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。那么这样下来，老师至少需要准备多少颗糖果呢？
    */
public:
    int candy(vector<int>& ratings) {
        //两次遍历法
        vector<int> dp(ratings.size(), 1);
        for(int i = 1; i< ratings.size(); ++i){
            if(ratings[i] > ratings[i-1])
                dp[i] = dp[i-1]+1;
        }
        int ret = max(dp[ratings.size()-1], 1);
        int cur = 1;
        for(int i = ratings.size()-2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]){
                cur = cur+1;
            }else{
                cur = 1;
            }
            ret += max(dp[i], cur);
        }
        return ret;
    }
public:
    int candy2(vector<int>& ratings) {
        //单次循环
        int n = ratings.size();
        int ret = 1;
        int inc = 1; //最近的递增序列的长度
        int dec = 0; //当前递减序列的长度
        int pre = 1; //前一个同学分得的糖果数量
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre;
                inc = pre;
            } else {
                dec++;
                if (dec == inc) {
                    dec++;
                }
                ret += dec;
                pre = 1;
            }
        }
        return ret;
    }
};

int main(int argc, char const* argv[])
{
    Candy cls;
    cout << cls.candy2(vector<int>{1,0,2}) << " -> 5" << endl;
    cout << cls.candy2(vector<int>{1,2,2}) << " -> 4" << endl;
    return 0;
}
