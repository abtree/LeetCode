#include <iostream>
#include <vector>
using namespace std;

class IslandPerimeter{
public:
    int islandPerimeter(vector<vector<int>> grid) {
        int m = grid.size();
        if(m <= 0){
            return 0;
        }
        int n = grid[0].size();
        int ret = 0;
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                if(grid[i][j] == 0){
                    continue;
                }
                int add = 4;
                if(i > 0 && grid[i-1][j] == 1){
                    --add;
                }
                if(i+1 < m && grid[i+1][j] == 1){
                    --add;
                }
                if(j > 0 && grid[i][j-1] == 1){
                    --add;
                }
                if(j +1 < n && grid[i][j+1] == 1){
                    --add;
                }
                ret+=add;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    IslandPerimeter cls;
    cout << cls.islandPerimeter(vector<vector<int>>{{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}}) << " -> 16" << endl;
    cout << cls.islandPerimeter(vector<vector<int>>{{1}}) << " -> 4" << endl;
    cout << cls.islandPerimeter(vector<vector<int>>{{1, 0}}) << " -> 4" << endl;
    return 0;
}
