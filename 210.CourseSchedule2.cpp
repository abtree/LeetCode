#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 210. 课程表 II
class CourseSchedule2
{
    /* 现在你总共有 n 门课需要选，记为 0 到 n-1。在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1],给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
    */
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //深度优先
        vector<vector<int>> metrix(numCourses);
        vector<int> visited(numCourses, 0);
        vector<int> ret;
        //转图
        for(auto &info : prerequisites){
            metrix[info[1]].push_back(info[0]);
        }
        //拓扑
        for(int i =0;i<numCourses;++i){
            if(visited[i] == 0){
                if(!dfs(metrix, visited, ret, i))
                    return vector<int>{};
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
private:
    bool dfs(vector<vector<int>>& metrix, vector<int>& visited, vector<int>& ret, int n){
        visited[n] = 1;
        for(auto i : metrix[n]){
            if(visited[i] == 0){
                if(!dfs(metrix, visited, ret, i))
                    return false;
            }else if(visited[i] == 1){
                return false;
            }
        }
        visited[n] = 2;
        ret.push_back(n);
        return true;
    }
public:
    vector<int> findOrder2(int numCourses, vector<vector<int>>& prerequisites) {
        //广度优先拓扑
        vector<vector<int>> metrix(numCourses);
        vector<int> indeg(numCourses);
        //转图
        for(auto& info : prerequisites){
            metrix[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }
        queue<int> q;
        for(int i =0 ;i< numCourses;++i){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        vector<int> ret;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ret.push_back(u);
            for(auto v : metrix[u]){
                --indeg[v];
                if(indeg[v] == 0)
                    q.push(v);
            }
        }
        if(ret.size() != numCourses)
            return vector<int>{};
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    CourseSchedule2 cls;
    auto &ret = cls.findOrder2(2, vector<vector<int>>{{1,0}});
    cout << "[";
    for(auto it : ret){
        cout << it << ",";
    }
    cout << "]" << endl;

    auto &ret1 = cls.findOrder2(4, vector<vector<int>>{{1,0},{2,0},{3,1},{3,2}});
    cout << "[";
    for(auto it : ret1){
        cout << it << ",";
    }
    cout << "]" << endl;
    return 0;
}
