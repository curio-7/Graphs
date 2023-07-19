#define f first
#define s second
class Solution {
public:
    int x_d[4] = {-1,0,1,0};
    int y_d[4] = {0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int fresh = 0;
        int ri=0;
        int rj=0;
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    ri = i;
                    rj = j;
                    q.push({0,{ri,rj}});
                    vis[i][j]=1;
                }else if(grid[i][j]==1)fresh++;
            }
        }
        
        vis[ri][rj] = true;
       
        
        int ans = 0;
        int rotten = 0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int time = top.f;
            int i = top.s.f;
            int j = top.s.s;
            ans = max(ans,time);
            for(int d=0;d<4;d++){
                int ni = i + x_d[d];
                int nj = j + y_d[d];
                if(ni>=0 && nj>=0 && ni<n && nj<m &&
                    grid[ni][nj]==1 && !vis[ni][nj]){
                    vis[ni][nj] = true;
                    q.push({time+1,{ni,nj}});
                    rotten++;
                }
            }
        }
        
        if(rotten != fresh) return -1;

        return ans;
        
    }
};