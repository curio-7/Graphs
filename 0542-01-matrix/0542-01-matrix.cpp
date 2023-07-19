class Solution {
public:
    int x_d[4] = {-1,0,1,0};
    int y_d[4] = {0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
	    int m = grid[0].size();
        
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>dist(n,vector<int>(m,0));
        
	    queue<pair<pair<int,int>,int>>q;
        //{{i,j},dis}
        
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==0){
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int dis = q.front().second;
	        dist[r][c]=dis;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int nr = r+x_d[i];
	            int nc = c+y_d[i];
	            if(nr>=0 && nc>=0 && nr<n &&nc<m && vis[nr][nc]==0){
	                vis[nr][nc]=1;
	                q.push({{nr,nc},dis+1});
	            }
	        }
	        
	    }
	    return dist;
    }
};