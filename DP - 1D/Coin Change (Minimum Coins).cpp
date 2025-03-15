
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/number-of-coins1824
class Solution {
  public:
    int solve(vector<int>& coins, int sum, int i, vector<vector<int>>& dp){
        if(sum < 0)     return INT_MAX;
        if(sum == 0)    return 0;
        if(dp[sum][i] != -1)    return dp[sum][i];
        int cnt = INT_MAX;
        for(int j=i; j<coins.size(); j++){
            int ans = solve(coins, sum - coins[j], j, dp);
            if(ans != INT_MAX){
                cnt = min(cnt, ans + 1);
            }
        }
        return dp[sum][i] = cnt;
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n = coins.size();
        vector<vector<int>> dp(sum + 1, vector<int>(n + 1, -1));
        int ans = solve(coins, sum, 0, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
