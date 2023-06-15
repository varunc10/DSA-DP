class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](vector<int> &a,vector<int> &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> dp;
        for (int i = 0; i < v.size(); i++) {
            if (dp.empty() || dp[dp.size() - 1] < v[i][1]) dp.push_back(v[i][1]);
            else {
                auto it = lower_bound(dp.begin(), dp.end(), v[i][1]);
                *it = v[i][1];
            }
        }
        return dp.size();
    }
};