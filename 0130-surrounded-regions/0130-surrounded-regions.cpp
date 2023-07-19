class Solution {
public:
    int x_d[4] = {-1,0,1,0};
    int y_d[4] = {0,1,0,-1};
    
    void dfs(int i,int j,vector<vector<char>>&grid,int n,int m,vector<vector<bool>>&vis){
        vis[i][j] = true;
        
        for(int d = 0;d<4;d++){
            int ni = i + x_d[d];
            int nj = j + y_d[d];
            if(ni>=0 && nj >=0 && ni<n && nj<m && grid[ni][nj]=='O' && !vis[ni][nj]){
                dfs(ni,nj,grid,n,m,vis);
            }
        }
    }
    
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]=='O' && !vis[i][j]){
                    //boundary 
                    dfs(i,j,grid,n,m,vis);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='O'){
                    grid[i][j] = 'X';
                }
            }
        }
        
    }
};