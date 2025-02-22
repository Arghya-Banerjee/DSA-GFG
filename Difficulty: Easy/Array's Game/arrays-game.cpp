//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string arrayGame(int N, int A[]) {
        // code here
        int maxi = *max_element(A, A+N);
        int sum = accumulate(A, A+N, 0);
        int rem = (maxi * N) - sum;
        if(rem == 0) return "Draw";
        else if(rem & 1) return "First";
        else return "Second";
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, i;
        cin >> N;
        int A[N];
        for (i = 0; i < N; i++) cin >> A[i];
        Solution ob;
        cout << ob.arrayGame(N, A) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends