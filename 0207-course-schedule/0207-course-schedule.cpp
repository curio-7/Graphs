class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int>adj[V];
	    for(auto x:prerequisites){
	        adj[x[0]].push_back(x[1]);
	    }
	    
	    vector<int>indeg(V,0);
	   for(int i=0;i<V;i++){
	       for(auto x:adj[i]){
	           indeg[x]++;
	       }
	   }
	   queue<int>q;
	   for(int i=0;i<V;i++){
	       if(indeg[i]==0){
	           q.push(i);
	       }
	   }
	   vector<int>ans;
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       ans.push_back(node);
	       for(auto x:adj[node]){
	           indeg[x]--;
	           if(indeg[x]==0)q.push(x);
	       }
	   }
	   if(ans.size()==V)return true;
	   else return false;
    }
};