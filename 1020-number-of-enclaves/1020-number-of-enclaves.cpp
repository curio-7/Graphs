class Solution {
public:
    int x_d[4] = {-1,0,1,0};
    int y_d[4] = {0,1,0,-1};
    
    void dfs(int i,int j,vector<vector<int>>&grid,int n,int m){
        grid[i][j] = 0;
        
        for(int d = 0;d<4;d++){
            int ni = i + x_d[d];
            int nj = j + y_d[d];
            if(ni>=0 && nj >=0 && ni<n && nj<m && grid[ni][nj]==1){
                dfs(ni,nj,grid,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1){
                    //boundary
                    dfs(i,j,grid,n,m);
                }
            }
        }
        int restLand = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)restLand++;
            }
        }
        
        return restLand;
    }
};