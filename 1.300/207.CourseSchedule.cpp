#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 207. 课程表
class CourseSchedule
{
    /* 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
    例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
    */
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //深度优先遍历
        vector<vector<int>> metrix(numCourses, vector<int>{});
        vector<int> visited(numCourses, 0);

        for(auto &info : prerequisites){
            metrix[info[1]].push_back(info[0]); //构成图
        }
        for(int i = 0; i < numCourses; ++i){
            if(visited[i] == 0){
                if(!dfs(metrix, visited, i))
                    return false;
            }
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>>& metrix, vector<int>& visited, int i){
        visited[i] = 1; //正在遍历的节点
        for(auto n : metrix[i]){
            if(visited[n] == 0){
                if(!dfs(metrix, visited, n))
                    return false;
            }else if(visited[n]==1){
                return false;
            }
        }
        visited[i] = 2;
        return true;
    }
public:
    bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
        //广度优先遍历
        vector<vector<int>> metrix(numCourses, vector<int>{});
        vector<int> indeg(numCourses, 0);
        for(auto& info : prerequisites){
            metrix[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }
        queue<int> q;
        for(int i = 0; i < numCourses;++i){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty()){
            ++visited;
            int u = q.front();
            q.pop();
            for(int v : metrix[u]){
                --indeg[v];
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }
        return visited == numCourses;
    }
};

int main(int argc, char const *argv[])
{
    CourseSchedule cls;
    cout << boolalpha << cls.canFinish(2, vector<vector<int>>{{1,0}}) << " -> true" <<endl;
    cout << boolalpha << cls.canFinish(2, vector<vector<int>>{{1,0},{0,1}}) << " -> false" <<endl;
    cout << boolalpha << cls.canFinish2(2, vector<vector<int>>{{1,0}}) << " -> true" <<endl;
    cout << boolalpha << cls.canFinish2(2, vector<vector<int>>{{1,0},{0,1}}) << " -> false" <<endl;
    return 0;
}
