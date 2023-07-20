class Solution {
public:
    ///THERE CAN BE ATMOST 2 MHT.
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto&x:edges){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
	       for(auto x:adj[i]){
	           indeg[x]++;
	       }
	    }
        vector<int>Ans;
        queue<int>q;
        for(int i = 0;i<indeg.size();i++){
            if(indeg[i]<=1) q.push(i),indeg[i]--;
        }
        while(!q.empty()){
            int sz = q.size();
            if(n<=2)break;
            while(sz--){
                int node = q.front();q.pop();
                n--;
                for(auto&neigh:adj[node]){
                    indeg[neigh]--;
                    if(indeg[neigh]==1)q.push(neigh);
                }
            }
        }
        while(!q.empty()){
           Ans.push_back(q.front()); q.pop();
        }
        return Ans;
    }
    
};