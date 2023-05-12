class Solution {
public:
    #define ll long long
    ll memo[100001];
    ll helper(vector<vector<int>>& questions, int i){
        if(i >= questions.size()){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        return memo[i] = max((ll)questions[i][0] + helper(questions, i + questions[i][1] + 1), helper(questions, i + 1));
    }

    ll mostPoints(vector<vector<int>>& questions) {
        memset(memo, -1, sizeof(memo));
        return helper(questions, 0);
    }
};