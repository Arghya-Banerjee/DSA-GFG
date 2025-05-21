// User function template for C++

class Solution {
  private:
    int uB(vector<int> &arr, int k) {
        int low = 0, high = arr.size()-1, ans = arr.size();
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] > k) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    
    int getCnt(vector<vector<int>> &mat, int n, int m, int k) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += uB(mat[i], k);
        }
        return cnt;
    }
    
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int low = INT_MAX, high = INT_MIN;
        for(int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }
        int req = (n*m) / 2;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(getCnt(mat, n, m, mid) <= req) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
