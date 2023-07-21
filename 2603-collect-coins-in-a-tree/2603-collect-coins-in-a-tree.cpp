class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> adj(n);

        // Create adjacency list from edges
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<int> leafWithCoins;
        queue<int> q;

        // Find all leaf nodes and add them to queue
        for(int i = 0;i<n;i++){
            if(adj[i].size() == 1){
                 q.push(i);
            }
        }
        
        int remainingCoins = n;
        
        // BFS traversal of the graph
        while(!q.empty()){
            int node = q.front();
            q.pop();

            // If the node has coins, add it to the queue of nodes with coins
            if(coins[node]){
                leafWithCoins.push(node);
                continue;
            }

            // If the node does not have coins, delete it and update remaining coins count
            remainingCoins--;

            // Deleting leaf Node
            for(auto &it: adj[node]){
                auto parent = find(adj[node].begin(), adj[node].end(), it);
                auto child = find(adj[it].begin(), adj[it].end(), node);

                adj[it].erase(child);
                adj[node].erase(parent);

                // If a new leaf node is formed after deleting a node, add it to the queue
                if(adj[it].size() == 1){
                    q.push(it);
                }
            }
        }

        // Deleting leaf with coins

        // Perform two passes to delete leaf nodes with coins
        for(int i = 0;i<2;i++){
            int l = leafWithCoins.size();
            while(l--){
                int node = leafWithCoins.front();
                leafWithCoins.pop();

                // Delete the node and update remaining coins count
                remainingCoins--;

                for(auto &it: adj[node]){
                    auto parent = find(adj[node].begin(), adj[node].end(), it);
                    auto child = find(adj[it].begin(), adj[it].end(), node);
                    adj[it].erase(child);
                    adj[node].erase(parent);

                    // If a new leaf node is formed after deleting a node, add it to the queue
                    if(adj[it].size() == 1){
                        leafWithCoins.push(it);
                    }
                }
            }
        }

        // If all nodes have been deleted, return 0. Otherwise, return the minimum number of steps to collect all coins
        return  remainingCoins == 0 ? 0: (remainingCoins-1)*2;
    }
};