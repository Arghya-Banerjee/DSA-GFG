// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int cnt = 0, ind = 0;
        for(int i = 0; i < arr.size(); i++) {
            int lb = lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin();
            int temp = arr[i].size() - lb;
            if(temp > cnt) {
                cnt = temp;
                ind = i;
            }
        }
        return ind;
    }
};