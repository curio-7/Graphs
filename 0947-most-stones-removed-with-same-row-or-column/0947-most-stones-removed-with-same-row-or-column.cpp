class DisjointSet {
     
public: 
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }
}; 
class Solution {
    
public:
    bool inSame(vector<int>&x,vector<int>&y){
        return (x[0]==y[0] || x[1]==y[1]);
    }
    int removeStones(vector<vector<int>>& stones) {
        //our ans is = no of stones - no of strongly connected graph
        int n = stones.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(inSame(stones[i],stones[j])){
                    ds.unionByRank(i,j);
                }
            }
        }
        int nCom = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)nCom++;
        }
        return n-nCom;
    }
};