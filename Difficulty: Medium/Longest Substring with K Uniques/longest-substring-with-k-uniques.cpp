//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int n = s.size();
        int i = 0, j = 0;
        map<char, int> mpp;
        int ans = -1;
        while(i<n && j<n){
            // cout << mpp.size() << endl;
            mpp[s[j]]++;
            if(mpp.size() == k) ans = max(ans, (j-i+1));
            j++;
            while(mpp.size() > k){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends