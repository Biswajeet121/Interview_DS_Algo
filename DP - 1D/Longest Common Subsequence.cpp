
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-common-subsequence-1587115620
class Solution {
  public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        if(i == s1.size() || j == s2.size())
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int ans = 0;
        if(s1[i] == s2[j])
            ans = 1 + solve(s1, s2, i+1, j+1, dp);
        else
            ans = max(solve(s1, s2, i+1, j, dp), solve(s1, s2, i, j+1, dp));
            
        return dp[i][j] = ans;
    }
    int lcs(string &s1, string &s2) {
        // code here
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return solve(s1, s2, 0, 0, dp);
    }
};
