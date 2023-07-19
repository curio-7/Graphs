class Solution {
private:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void dfs(vector<vector<int>>&vis,int i,int j,int color,vector<vector<int>>& image,int val){
        vis[i][j]=color;
        for(auto d : dir) {
            int ni = i + d.first;
            int nj = j + d.second;
            if(ni >= 0 && ni < image.size() && nj >= 0 && nj < image[0].size() && image[ni][nj] == val && vis[ni][nj]!=color) {
                dfs(vis,ni,nj,color,image,val);
            }   
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>vis = image;
        int val = image[sr][sc];
        dfs(vis,sr,sc,color,image,val);
        return vis;
    }
};