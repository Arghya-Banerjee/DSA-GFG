// User function Template for C++

class Solution {
    public:
    
    void dfs(int row, int col, int p, int q, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &temp){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        temp.push_back({row-p, col-q});
        int d[5] = {1, 0, -1, 0, 1};
        for(int i = 0; i < 4; i++){
            int nrow = row + d[i];
            int ncol = col + d[i+1];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol]){
                dfs(nrow, ncol, p, q, grid, vis, temp);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        vector<pair<int, int>> temp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    temp.clear();
                    dfs(i, j, i, j, grid, vis, temp);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};
