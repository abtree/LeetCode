#include <iostream>
#include <unordered_set>
using namespace std;

class nqueens2{
public:
    /*
    整个解题过程为枚举，即一个位置一个位置的测试，采用递归回溯的方法
    */
    int totalNQueens(int n) {
        return backtrack(n, 0);
    }
private:
    int backtrack(int n, int row){
        if(row == n){
            // row == n 表示已经遍历完整棋盘
            // 即所以皇后都放在棋盘上了
            return 1;
        }
        int cnt = 0;
        //遍历该行的所有位置 找到可以放皇后的位置
        for (int i = 0; i < n; ++i)
        {
            //如果该列上已经有皇后 就不能放在该位置
            if(mCols.find(i) != mCols.end()){
                continue;
            }
            //如果该位置的正斜边某个位置已经有皇后 就不能放在该位置
            if(mLeft.find(row - i) != mLeft.end()){
                continue;
            }
            //如果该位置的反斜边某个位置已经有皇后 就不能放在该位置
            if(mRight.find(row+i) != mRight.end()){
                continue;
            }
            //标识该列已经有皇后
            mCols.insert(i);
            //标识该斜边已经有皇后
            mLeft.insert(row-i);
            //标识该反斜边已经有皇后
            mRight.insert(row+i);
            //继续判断下一行可以放皇后的位置
            cnt += backtrack(n, row+1);
            //取消标识
            mCols.erase(i);
            mLeft.erase(row-i);
            mRight.erase(row+i);
        }
        return cnt;
    }
private:
	/*
    mCols 记录哪些列有皇后了
    mLeft 记录正斜杠已经有皇后 (x - y相等表示在同一列, 如 【0，0】与【3，3】)
    mRight 记录反斜杠已经有皇后 (x + y相等表示在同一列，如【3,0】与【1,2】)
    */
    unordered_set<int> mCols, mLeft, mRight;
public:
    int totalNQueens2(int n) {
        return solve(n, 0, 0,0,0);
    }
private:
    int solve(int n, int row, int cols, int left, int right){
        if(row == n){
            return 1;
        }
        int cnt = 0;
        int available = ((1<<n)-1) & (~(cols | left | right));
        while (available != 0)
        {
            int pos = available & (-available);
            available = available & (available - 1);
            cnt += solve(n, row+1, cols | pos, (left | pos) << 1, (right | pos) >> 1);
        }
        return cnt;
    }
};

int main(){
    nqueens2 cls;
    cout << cls.totalNQueens(4) << " -> 2" << endl;
    cout << cls.totalNQueens(1) << " -> 1" << endl;

    cout << cls.totalNQueens2(4) << " -> 2" << endl;
    cout << cls.totalNQueens2(1) << " -> 1" << endl;
}