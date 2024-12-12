//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCostCity(vector<vector<int>>& houses, int n) {
        // code here
        unordered_map<int, vector<pair<int, int>>> adj;
        for(int i = 0; i < houses.size(); i++){
            vector<int> curr = houses[i];
            for(int j = 0; j < houses.size(); j++){
                if(i == j) continue;
                adj[i].push_back({j, abs(curr[0] - houses[j][0]) + abs(curr[1] - houses[j][1])});
            }
        }
        vector<int> vis(houses.size(), 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int sum = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            sum += wt;
            for(auto neigh: adj[node]){
                int adjNode = neigh.first;
                int adjWt = neigh.second;
                if(!vis[adjNode]) pq.push({adjWt, adjNode});
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCostCity(edges, n);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends