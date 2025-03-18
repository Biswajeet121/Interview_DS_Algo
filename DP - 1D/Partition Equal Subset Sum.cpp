
  Problem Link : https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

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
        vector<vector<int>> dp(sum+1, vector<int>(n+1, -1));
        return solve(arr, sum, 0, dp);
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        n = arr.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
        }
        if(sum % 2)
            return false;
        return isSubsetSum(arr, sum/2);
    }
};
