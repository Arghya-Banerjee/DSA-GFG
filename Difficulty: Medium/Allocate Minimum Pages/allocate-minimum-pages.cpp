//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    bool check(vector<int> &arr, int mid, int k) {
        int cnt = 1;
        int temp = 0;
        for(auto it: arr) {
            if(cnt > k) return false;
            if(it + temp > mid) {
                cnt++;
                temp = it;
            }
            else temp += it;
        }
        return cnt <= k;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int low = *max_element(arr.begin(), arr.end()), high = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        if(k > arr.size()) return -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(arr, mid, k)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends