class Solution {
public:
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>adj(n);
        set<int>st(restricted.begin(),restricted.end());
        for(auto&x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int steps = 0;
        vector<int>vis(n,false);
        queue<int>q;
        q.push(0);
        vis[0] = true;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            steps++;
            for(auto&neigh:adj[node]){
                if(!vis[neigh] && st.find(neigh)==st.end()){
                    
                    vis[neigh] = true;
                    q.push(neigh);
                }
                
            }
        }
        return steps;
        
    }
};