class Solution {
  public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(int child: adj[node]){
            if(!vis[child]){
                if(dfs(child, adj, vis, pathVis)) return true;
            }
            else{
                if(pathVis[child]) return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> vis(V, 0), pathVis(V, 0);
        vector<vector<int>> adj(V);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis)){
                    return true;
                };
            }
        }
        return false;
    }
};