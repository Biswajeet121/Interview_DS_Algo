
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/min-cost-climbing-stairs

class Solution {
  public:
    int solve(vector<int>& cost, int i, vector<int>& dp){
        if(i >= cost.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
            
        int oneStep = cost[i] + solve(cost, i+1, dp);
        int twoStep = cost[i] + solve(cost, i+2, dp);
        return dp[i] = min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(solve(cost, 0, dp), solve(cost, 1, dp));
    }
};
