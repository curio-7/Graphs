class Solution {
public:
     bool dfs(int node,vector<vector<int>>& graph,vector<int> &vis,vector<int> &pathvis,vector<int>&chck){
        vis[node] = 1;
        pathvis[node] = 1;
        chck[node] = 0;
        for(auto x:graph[node]){
            if(!vis[x]){
                if(dfs(x,graph,vis,pathvis,chck)==true){
                    
                    return true;
                }
            }
            else if(pathvis[x]){
                chck[x]=0;
                return true;
            }
        }
        chck[node]=1;
        pathvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v,0);
        vector<int> pathvis(v,0);
        vector<int> chck(v,0);
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathvis,chck);
            }
        }
        vector<int>sn;
        for(int i=0;i<v;i++){
            if(chck[i]==1){
                sn.push_back(i);
            }
        }
        return sn;
    }
};