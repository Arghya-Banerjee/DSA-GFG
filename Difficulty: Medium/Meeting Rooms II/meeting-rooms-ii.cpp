//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size();
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int cnt = 0;
        int i = 0, j = 0;
        int ans = 0;
        while(i < n && j < n){
            if(start[i] < end[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};



//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.minMeetingRooms(arr, brr);
        cout << res << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends