//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n+2, vector<int>(4, 0));
        // dp[day][last] = max points got by performing the 'last' activity on prev day
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2], arr[0][3]});
        
        for(int i = 1; i < n; i++){
            for(int last = 0; last < 4; last++){
                int maxi = 0;
                for(int activity = 0; activity < 3; activity++){
                    if(activity != last){
                        maxi = max(maxi, arr[i][activity] + dp[i-1][activity]);
                    }
                }
                dp[i][last] = maxi;
            }
        }
        return dp[n-1][3];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends