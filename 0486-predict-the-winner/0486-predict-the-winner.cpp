class Solution {
public:
    int memo[21][21];
    int helper(vector<int>& nums, int i, int j){
        if(i > j){
            return 0;
        }
        if(i == j){
            return nums[i];
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        return memo[i][j] = max(nums[i] + min(helper(nums, i + 2, j), helper(nums, i + 1, j - 1)), nums[j] + min(helper(nums, i, j - 2), helper(nums, i + 1, j - 1)));
    }
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        memset(memo, -1, sizeof(memo));
        int total = 0;
        for(auto i: nums){
            total += i;
        }
        int a = helper(nums, 0, nums.size() - 1);
        return a >= total - a;
    }
};