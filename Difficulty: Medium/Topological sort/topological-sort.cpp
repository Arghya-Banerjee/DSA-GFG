class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        for(int child: adj[node]){
            if(!vis[child]) dfs(child, adj, vis, st);
        }
        st.push(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]) dfs(i, adj, vis, st);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};