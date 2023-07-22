class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n+1];
        for(int i=0;i<n;++i){
            if(manager[i]==-1)continue;
            adj[manager[i]].push_back(i);
        }
        int time = informTime[headID];
        queue<pair<int,int>>q;
        q.push({informTime[headID],headID});
        
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int t = top.first;
            int head = top.second;
            
            for(auto subor:adj[head]){
                time = max(time,t+informTime[subor]);
                q.push({informTime[subor]+t,subor});
            }
        }
        return time;
    }
};