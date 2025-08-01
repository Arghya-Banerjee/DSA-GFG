class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        vector<int> vis(adj.size(), 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int it: adj[node]) {
                if(!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return ans;
    }
};