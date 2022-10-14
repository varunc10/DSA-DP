class Solution {
public:
    int memo[201][201];
    int helper(vector<vector<int>>& v,int i,int j){
        if(i>=v.size()||j>=v[0].size()){
            return 1e9;
        }
        if(i==v.size()-1&&j==v[0].size()-1){
            return v[i][j]<=0?1-v[i][j]:1;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        int right=helper(v,i,j+1);
        int down=helper(v,i+1,j);
        int ans=min(right,down)-v[i][j];
        return memo[i][j]=ans<=0?1:ans;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(memo,-1,sizeof(memo));
        return helper(dungeon,0,0);
    }
};