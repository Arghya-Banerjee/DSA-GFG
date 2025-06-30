class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> indegree(V, 0);
        vector<vector<int>> adj(V);
        for(auto it: edges){
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        // for(auto it: indegree) cout << it << " ";
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int child: adj[node]){
                indegree[child]--;
                if(indegree[child] == 0) q.push(child);
                // cout << indegree[child] << endl;
            }
        }
        // for(auto it: ans) cout << it << " ";
        return ans;
    }
};