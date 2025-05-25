class Solution {
  public:
    using ll = long long;
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        ll n = arr.size();
        ll s = 0, s2 = 0;
        ll sn = (n * (n+1)) / 2;
        ll s2n = (n * (n+1) * ((2*n)+1)) / 6;
        for(auto it: arr) {
            s += (ll)(it);
            s2 += (ll)(it) * (ll)(it);;
        }
        ll val1 = s - sn;
        ll val2 = s2 - s2n;
        val2 = val2 / val1;
        int x = (val1 + val2 )/ 2;
        int y = val2 - x;
        return {(int)x, (int)y};
    }
};