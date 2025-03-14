
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/coin-change2448

class Solution {
  public:
    int solve(vector<int>& coins, int sum, int i, vector<vector<int>>& dp){
        if(sum < 0)
            return 0;
        if(sum == 0)
            return 1;
        if(dp[sum][i] != -1)
            return dp[sum][i];
            
        int ans = 0;
        for(int j=i; j<coins.size(); j++){
            ans += solve(coins, sum-coins[j], j, dp);
        }
        return dp[sum][i] = ans;
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(sum+1, vector<int>(n+1, -1));
        return solve(coins, sum, 0, dp);
    }
};
