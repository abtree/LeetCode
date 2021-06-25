#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 310. 最小高度树
class MinimunHeightTrees {
    /* 树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
    */
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //暴力层序遍历（会超时）
        minHight = n;
        ret.clear();
        //构建图
        vector<vector<int>> map(n);
        for (auto &it : edges){
            map[it[0]].push_back(it[1]);
            map[it[1]].push_back(it[0]);
        }
        //连接最多的节点 一定是层级最少的（这里单独计算，方便以后剪枝）
        int maxLink = 0;
        for(auto& it : map){
            if(it.size() > maxLink)
                maxLink = it.size();
        }
        layer(map, maxLink);
        //以每一个节点为根节点 遍历
        for(int i = 0; i<n;++i){
            if(i != maxLink)
                layer(map, i);
        }
        return ret;
    }
private:
    void layer(vector<vector<int>>& map, int r){
        //层序遍历
        int layer = 1;
        queue<int> q;
        vector<bool> used(map.size(), false);   //由于构造了环 所以需要标记哪些节点已被使用
        used[r] = true;
        for(auto i : map[r]){
            q.push(i);
            used[i] = true;
        }
        while (!q.empty()){
            layer += 1;
            if(layer > minHight)
                return; //剪枝
            int size = q.size();
            for(int i = 0; i< size; ++i){
                int c = q.front();
                q.pop();
                for(auto k : map[c]){
                    if(!used[k]){
                        q.push(k);
                        used[k] = true;
                    }
                }
            }    
        }
        if(layer < minHight){
            ret.clear();
            minHight = layer;
        }
        ret.push_back(r);
    }
private:
    int minHight{};
    vector<int> ret;
public:
    vector<int> findMinHeightTrees2(int n, vector<vector<int>>& edges) {
        /* 优化后的层序遍历
            实际是找关联节点最多的节点,思路上每次减掉图中所有叶子节点(与其它节点关联为1的节点)，剩余节点构成的图会出现新的叶子节点，直到只剩下叶子节点
        */
       //特殊处理节点数为1 和 2的情况
       if(n == 1){
           return vector<int>{0};
       }
       if(n == 2){  //这个可以不特殊处理
           return vector<int>{0,1};
       }
       //构建图 同时统计关联度
       vector<int> degree(n, 0);
       vector<vector<int>> map(n);
       for(auto &it : edges){
           ++degree[it[0]];
           ++degree[it[1]];
           map[it[0]].push_back(it[1]);
           map[it[1]].push_back(it[0]);
       }
       //初始化队列
       queue<int> q;
       for(int i =0;i<n;++i){
           if(degree[i] == 1){
               q.push(i);
           }
       }
       while(n > 2){    //最终结果最多两个
           int size = q.size();
           n -= size;
           for(int i = 0; i< size;++i){
                int c = q.front();
                q.pop();
                for(auto k : map[c]){
                    --degree[k];
                    if(degree[k] == 1){
                        q.push(k);
                    }
                }
           }
       }
       //将结果取出
       vector<int> ret;
       while(!q.empty()){
           ret.push_back(q.front());
           q.pop();
       }
       return ret;
    }
};

int main(int argc, char const *argv[]){
    MinimunHeightTrees cls;
    auto ret = cls.findMinHeightTrees2(4, vector<vector<int>>{{1,0},{1,2},{1,3}});
    cout << "[";
    for(auto it : ret){
        cout << it << ",";
    }
    cout << "]" << endl;

    auto ret1 = cls.findMinHeightTrees2(6, vector<vector<int>>{{3,0},{3,1},{3,2},{3,4},{5,4}});
    cout << "[";
    for(auto it : ret1){
        cout << it << ",";
    }
    cout << "]" << endl;

    auto ret2 = cls.findMinHeightTrees2(1, vector<vector<int>>{});
    cout << "[";
    for(auto it : ret2){
        cout << it << ",";
    }
    cout << "]" << endl;

    auto ret3 = cls.findMinHeightTrees2(2, vector<vector<int>>{{0,1}});
    cout << "[";
    for(auto it : ret3){
        cout << it << ",";
    }
    cout << "]" << endl;

    return 0;
}
