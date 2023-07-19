class Solution {
public:
    bool f(vector<vector<int>>&graph,int src,vector<int>&color){
        queue<int>q;
        q.push(src);
        color[src] = 0;
        
        while(!q.empty()){
            int node = q.front();q.pop();
            
            for(auto&n : graph[node]){
                if(color[n] == color[node])return false;
                else if(color[n] == -1){
                    color[n] = !color[node];
                    q.push(n);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(f(graph,i,color) == false) return false;
            }
        }
        
        return true;
    }
};