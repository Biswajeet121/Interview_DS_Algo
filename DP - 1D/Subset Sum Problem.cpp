
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/subset-sum-problem-1611555638
  
class Solution {
  public:
    int n;
    bool solve(vector<int>& arr, int sum, int i, vector<vector<int>>& dp){
        if(sum == 0)    
            return true;
        if(i == n || sum < 0)
            return false;
        if(dp[sum][i] != -1)
            return dp[sum][i];
            
        bool take = solve(arr, sum - arr[i], i+1, dp);
        bool skip = solve(arr, sum, i+1, dp);
        return dp[sum][i] = (take || skip);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        n = arr.size();
        vector<vector<int>> dp(sum+1, vector<int>(n+1, -1));
        return solve(arr, sum, 0, dp);
    }
};
