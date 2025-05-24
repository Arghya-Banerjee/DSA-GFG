class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mpp;
        int x = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            x ^= arr[i];
            if(x == k) ans++;
            if(mpp.count(x ^ k) > 0) {
                ans += mpp[x ^ k];
            }
            if(mpp.count(x) > 0) mpp[x]++;
            else mpp[x] = 1;
        }
        return ans;
    }
};