class Solution {
public:
    int dir[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int dfs(vector<vector<int>>&vis,vector<vector<int>>&grid,int i,int j){
        vis[i][j] = 1;
        int curr = grid[i][j];
        int maxInNextStep = 0;
        //check for valid and then go in all four direction
        for(auto x:dir){
            int ni = i+x[0];
            int nj = j+x[1];
            if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size() && vis[ni][nj]==0 && grid[ni][nj]!=0){
                maxInNextStep = max(maxInNextStep,dfs(vis,grid,ni,nj));
                //unmark ni and nj from vis as afterone call they will be marked as vis
                vis[ni][nj] = 0;
            }
        }
        //make sure to unmark i and j
        vis[i][j] = 0;
        return curr + maxInNextStep;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int gold = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                //if not zero and not visited then go there
                if(!vis[i][j] && grid[i][j]!=0){
                    gold = max(gold,dfs(vis,grid,i,j));
                }
            }
        }
        return gold;
    }
    
};