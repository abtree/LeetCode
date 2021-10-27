#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class KthSmallestElementInASortedMatrix{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //优先队
        priority_queue<int> que;
        for(auto& row : matrix){
            for(auto c : row){
                que.push(c);
            }
        }
        while(que.size() > k){
            que.pop();
        }
        return que.top();
    }
public:
    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        //按行排序
        vector<int> dp(matrix.size(), 0);
        int size = matrix[0].size();
        int ret = 0;
        while (k > 0)
        {
            int curr = 0;
            ret = INT_MAX;
            for(int i = 0; i< matrix.size();++i){
                if(dp[i] < size && matrix[i][dp[i]] < ret){
                    curr = i;
                    ret = matrix[i][dp[i]];
                }
            }
            dp[curr]+=1;
            --k;
        }
        return ret;
    }
public:
    int kthSmallest2(vector<vector<int>>& matrix, int k) {
        //二分统计法
        int left = matrix[0][0];
        int right = matrix.back().back();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(count(matrix, mid) >= k){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
private:
    int count(vector<vector<int>>& matrix, int mid){
        int i = matrix.size()-1;
        int j = 0;
        int num = 0;
        while (i >= 0 && j < matrix[0].size()){
            if(matrix[i][j] <= mid){
                num += i+1;
                ++j;
            }else{
                --i;
            }
        }
        return num;
    }
};

int main(int argc, char const *argv[]){
    KthSmallestElementInASortedMatrix cls;
    cout << cls.kthSmallest2(vector<vector<int>>{{-5, -4}, {-5, -4}}, 2) << " -> -5" << endl;
    cout << cls.kthSmallest2(vector<vector<int>>{{1,5,9},{10,11,13},{12,13,15}}, 8) << " -> 13" << endl;
    cout << cls.kthSmallest2(vector<vector<int>>{{-5}}, 1) << " -> -5" << endl;
    cout << cls.kthSmallest2(vector<vector<int>>{{1,3,5},{6,7,12},{11,14,14}}, 3) << " -> 5" << endl;
    return 0;
}
