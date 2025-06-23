class Solution {
  private:
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]){
                if(dfs(it, node, adj, vis)) return true;
            }
            else if(vis[it] && it != parent) return true;
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<int> vis(V, 0);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {if(dfs(i, -1, adj, vis)) return true;}
        }
        return false;
    }
};