class Solution {
public:
    int bfs(vector<int>&arr,map<int,set<int>>&mp,int n){
        vector<bool>vis(n,false);
        queue<pair<int,int>>q;
        //{idx,steps}
        q.push({0,0});
        vis[0] = true;
        
        while(!q.empty()){
            auto top = q.front();q.pop();
            int idx = top.first;
            int steps = top.second;
            if(idx == n-1)return steps;
            set<int>possibleJumps = mp[arr[idx]];
            possibleJumps.insert(idx-1);
            possibleJumps.insert(idx+1);
            
            for(auto&x:possibleJumps){
                mp[arr[idx]].erase(x);
                if(x>=0 && x<n && !vis[x]){
                    q.push({x,steps+1});
                    vis[x]=true;
                }
            }
            
        }
        return -1;
    }
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n<=2)return n-1;
        map<int,set<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].insert(i);
        }
        return bfs(arr,mp,n);
    }
};