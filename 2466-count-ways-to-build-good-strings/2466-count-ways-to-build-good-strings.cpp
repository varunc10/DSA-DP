class Solution {
public:
    #define ll long long
    #define mod 1000000007
    ll memo[100001];
    int helper(ll low, ll high, ll len, ll numZeros, ll numOnes){
        if(len > high){
            return 0;
        }
        if(memo[len] != -1){
            return memo[len];
        }
        ll ans = 0;
        if(len >= low && len <= high){
            ans++;
        }
        ans += ((helper(low, high, len + numZeros, numZeros, numOnes)) % mod + (helper(low, high, len + numOnes, numZeros, numOnes)) % mod) % mod;
        return memo[len] = ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(memo, -1, sizeof(memo));
        return helper((ll)low, (ll)high, (ll)0, (ll)zero, (ll)one);
    }
};