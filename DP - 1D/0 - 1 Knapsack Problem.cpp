
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/0-1-knapsack-problem0945

class Solution {
  public:
    int solve(int w, vector<int>& val, vector<int>& wt, int i, vector<vector<int>>& dp){
        if(i == wt.size())
            return 0;
        if(dp[w][i] != -1)
            return dp[w][i];
        //take
        int take = 0;
        if(w - wt[i] >= 0){
            take = val[i] + solve(w - wt[i], val, wt, i+1, dp);
        }
        int notTake = solve(w, val, wt, i+1, dp);
        //no-take
        return dp[w][i] = max(take, notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(W+1, vector<int>(n+1, -1));
        return solve(W, val, wt, 0, dp);
    }
};
