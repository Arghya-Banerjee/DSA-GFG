//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  private:
    void f(int ind, int n, string &t, char prev, vector<string> &ans) {
        if(ind == n) {
            if(t.size() == n) ans.push_back(t);
            return;
        }
        t.push_back('0');
        f(ind + 1, n, t, '0', ans);
        t.pop_back();

        if(prev != '1') {
            t.push_back('1');
            f(ind + 1, n, t, '1', ans);
            t.pop_back();
        }
    }
    
  public:
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string> ans;
        if(!num) return ans;
        string t;
        f(0, num, t, '0', ans);
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends