#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

// 记录列表的变化，剩余的颜色球，达到该变化消耗的步数
struct State
{
    string board{};
    string hand{};
    int step{};
    State(const string &b, const string &h, int s)
        : board(b), hand(h), step(s) {}
};

class ZumaGame
{
public:
    int findMinStep(string board, string hand)
    {
        // 记录已经处理过的情形:board和hand都相同，防止重复处理
        unordered_set<string> visited;
        // 对hand进行排序，将相同颜色的球排在一起，方便剪枝
        sort(hand.begin(), hand.end());

        // 开始广度优先遍历
        visited.insert(board + " " + hand);
        queue<State> qu;
        qu.push(State(board, hand, 0));
        while (!qu.empty())
        {
            State curr = qu.front();
            cout << "curr " << curr.board.c_str()
                 << " " << curr.hand.c_str() << " " << curr.step << endl;
            qu.pop();

            for (int j = 0; j < curr.hand.size(); ++j)
            {
                // 第1种剪枝情况: 当前球与上一个球颜色相同，不用重复处理
                if (j > 0 && curr.hand[j - 1] == curr.hand[j])
                {
                    continue;
                }
                for (int i = 0; i <= curr.board.size(); ++i)
                {
                    // 第2种剪枝情况: 在连续相同颜色的球，插入到那个位置是一样的，因此只需要处理插入在头的情况
                    if (i > 0 && curr.board[i - 1] == curr.hand[j])
                    {
                        continue;
                    }
                    // 第3种剪枝情况:只在这两种情况插入球
                    bool choose = false;
                    // 第3_1种情况：当前球颜色与后面的球的颜色相同
                    if (i < curr.board.size() && curr.board[i] == curr.hand[j])
                    {
                        choose = true;
                    }
                    // 第3_2种情况 : 当前后颜色相同且与当前颜色不同时候放置球
                    if (i > 0 && i < curr.board.size() && curr.board[i - 1] == curr.board[i] && curr.board[i] != curr.hand[j])
                    {
                        choose = true;
                    }
                    if (choose)
                    {
                        string newBoard = clean(curr.board.substr(0, i) + curr.hand[j] + curr.board.substr(i));
                        string newHand = curr.hand.substr(0, j) + curr.hand.substr(j + 1);
                        if (newBoard.size() == 0)
                        {
                            return curr.step + 1;
                        }
                        if (!visited.count(newBoard + " " + newHand))
                        {
                            qu.push(State(newBoard, newHand, curr.step + 1));
                            visited.insert(newBoard + " " + newHand);
                        }
                    }
                }
            }
        }

        return -1;
    }

    int findMinStep1(string board, string hand)
    {
        sort(hand.begin(), hand.end());
        dp.clear();
        int ans = dfs(board, hand);
        return ans <= 5 ? ans : -1;
    }

private:
    /* 用于清除string中达到或超过3个的连续相同颜色
    先建立<颜色，连续个数>的列表
    再将 “连续个数” >= 3 的全部移除
    最后重新构建字符串
    */
    string clean(const string &s)
    {
        vector<pair<char, int>> st;
        for (char c : s)
        {
            // 移除已经满3个的 （必须与当前char不同，否则应该累加数量）
            while (!st.empty() && c != st.back().first && st.back().second >= 3)
            {
                st.pop_back();
            }
            if (st.empty() || c != st.back().first)
            {
                // 加入新元素
                st.push_back({c, 1});
            }
            else
            {
                st.back().second++;
            }
        }
        // 最有再检测一遍
        if (!st.empty() && st.back().second >= 3)
        {
            st.pop_back();
        }
        // 原有字符串
        string res = "";
        for (int i = 0; i < st.size(); ++i)
        {
            for (int j = 0; j < st[i].second; ++j)
            {
                res.push_back(st[i].first);
            }
        }
        return res;
    }

    int dfs(const string &board, const string &hand)
    {
        if (board.size() == 0)
        {
            return 0;
        }
        // 已经检测过了，不再重复检测
        if (dp.count(board + " " + hand))
        {
            return dp[board + " " + hand];
        }
        int res = 6;
        for (int j = 0; j < hand.size(); ++j)
        {
            // 第1种剪枝情况: 当前球与上一个球颜色相同，不用重复处理
            if (j > 0 && hand[j] == hand[j - 1])
            {
                continue;
            }
            for (int i = 0; i <= board.size(); ++i)
            {
                // 第2种剪枝情况: 在连续相同颜色的球，插入到那个位置是一样的，因此只需要处理插入在头的情况
                if (i > 0 && board[i - 1] == hand[j])
                {
                    continue;
                }
                // 第3种剪枝情况:只在这两种情况插入球
                bool choose = false;
                // 第3_1种情况：当前球颜色与后面的球的颜色相同
                if (i < board.size() && board[i] == hand[j])
                {
                    choose = true;
                }
                // 第3_2种情况 : 当前后颜色相同且与当前颜色不同时候放置球
                if (i > 0 && i < board.size() && board[i - 1] == board[i] && board[i] != hand[j])
                {
                    choose = true;
                }
                if (choose)
                {
                    string newBoard = clean(board.substr(0, i) + hand[j] + board.substr(i));
                    string newHand = hand.substr(0, j) + hand.substr(j + 1);
                    res = min(res, dfs(newBoard, newHand) + 1);
                }
            }
        }
        dp[board + " " + hand] = res;
        return res;
    }

private:
    unordered_map<string, int> dp;
};

int main(int argc, char const *argv[])
{
    ZumaGame cls;
    cout << cls.findMinStep1("RRWWRRBBRR", "WB") << " -> 2" << endl;
    cout << cls.findMinStep("BGGRRYY", "BBYRG") << " -> 5" << endl;
    cout << cls.findMinStep1("WRRBBW", "RB") << " -> -1" << endl;
    cout << cls.findMinStep1("WWRRBBWW", "WRBRW") << " -> 2" << endl;
    cout << cls.findMinStep1("G", "GGGGG") << " -> 2" << endl;
    cout << cls.findMinStep1("RBYYBBRRB", "YRBGB") << " -> 3" << endl;
    return 0;
}
