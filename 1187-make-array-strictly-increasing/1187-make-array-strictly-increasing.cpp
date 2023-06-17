class Solution {
public:
    unordered_map<int, unordered_map<int, int>> m;
    int helper(vector<int>& arr1, vector<int>& arr2, int i, int prev) {
        if (i == arr1.size()) return 0;
        if (m[i].count(prev)) return m[i][prev];
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        if (arr1[i] <= prev) {
            int k = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
            if (k < arr2.size() && arr2[k] > arr1[i]) {
                a = helper(arr1, arr2, i + 1, arr2[k]);
                if (a != INT_MAX) a++; 
            }
        }
        else {
            int k = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
            if (k < arr2.size() && arr2[k] > prev) {
                b = helper(arr1, arr2, i + 1, arr2[k]);
                if (b != INT_MAX) b++; 
            }
            c = helper(arr1, arr2, i + 1, arr1[i]);
        }
        return m[i][prev] = min({a, b, c});
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int ans = helper(arr1, arr2, 0, -1);
        return ans == INT_MAX ? -1 : ans;
    }
};