class Solution {
public:
    int xd[4] = {-1,0,1,0};
    int yd[4] = {0,1,0,-1};
    
    void dfs(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        vis[i][j] = true;
        
        for(int k=0;k<4;k++){
            int ni = i + xd[k];
            int nj = j + yd[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj] ==0 && !vis[ni][nj]){
                dfs(ni,nj,n,m,grid,vis);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)vis[i][j]=true;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j] == 0 && !vis[i][j]){
                    dfs(i,j,n,m,grid,vis);
                }
            }
        }
        
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    cnt++;
                    dfs(i,j,n,m,grid,vis);
                }
            }
        }
        
        return cnt;
    }
};