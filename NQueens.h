#pragma once

class NQueens {
private:
    vector<vector<string>> msol;
public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> cols(n);
        unordered_set<int> left(n);
        unordered_set<int> right(n);
        msol.clear();

        int row = 0;
        vector<string> sol(n, string(n, '.'));
        checkARow(sol, cols, left, right, row, n);
        return msol;
    }
private:
    void checkARow(vector<string>& sol, unordered_set<int>& cols, unordered_set<int>& left, unordered_set<int>& right, int row, int n) {
        if (row == n) {
            msol.push_back(sol);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (cols.find(i) != cols.end())
                continue;
            if (left.find(i - row) != left.end())
                continue;
            if (right.find(i + row) != right.end())
                continue;
            //该值可用
            cols.insert(i);
            left.insert(i - row);
            right.insert(i + row);
            sol[row][i] = 'Q';
            checkARow(sol, cols, left, right, row + 1, n);
            sol[row][i] = '.';
            cols.erase(i);
            left.erase(i - row);
            right.erase(i + row);
        }
    }

public:
    vector<vector<string>> solveNQueens2(int n) {
        //上面的版本优化性能后的版本
        vector<int> cols(n, 0);
        vector<int> left(2 * n, 0);
        vector<int> right(2 * n, 0);
        msol.clear();

        int row = 0;
        vector<string> sol(n, string(n, '.'));
        checkARow2(sol, cols, left, right, row, n);
        return msol;
    }
private:
    void checkARow2(vector<string>& sol, vector<int>& cols, vector<int>& left, vector<int>& right, int row, int n) {
        if (row == n) {
            msol.push_back(sol);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (cols[i] == 1)
                continue;
            int l = i - row + n;
            if (left[l] == 1)
                continue;
            int r = i + row;
            if (right[r] == 1)
                continue;
            //该值可用
            cols[i] = 1;
            left[l] = 1;
            right[r] = 1;
            sol[row][i] = 'Q';
            checkARow2(sol, cols, left, right, row + 1, n);
            sol[row][i] = '.';
            cols[i] = 0;
            left[l] = 0;
            right[r] = 0;
        }
    }
public:
    static void Test() {
        NQueens cls;
        vector<vector<string>> ret = cls.solveNQueens2(4);
        cout << "[" << endl;
        for (auto& it : ret) {
            cout << '[' << endl;
            for (auto& it1 : it) {
                cout << it1.c_str() << endl;
            }
            cout << ']' << endl;
        }
        cout << "]" << endl;
    }
};