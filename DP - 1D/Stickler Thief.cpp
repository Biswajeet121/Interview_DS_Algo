
  Problem Link : https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1

class Solution {
  public:
    int solveMem(vector<int>& arr, int i, vector<int>& dp){
        if(i >= arr.size()){
            return 0;
        }
        if(dp[i] != -1)
            return dp[i];
        int take = arr[i] + solveMem(arr, i+2, dp);
        int skip = solveMem(arr, i+1, dp);
        return dp[i] = max(take, skip);
    }
    int solveTab(vector<int>& arr){
        int n = arr.size();
        vector<int> dp(n+2, 0);
        
        for(int i=n-1; i>=0; i--){
            int take = arr[i] + dp[i+2];
            int skip = dp[i+1];
            dp[i] = max(take, skip);
        }
        return dp[0];
    }
    int solveOp(vector<int>& arr){
        int n = arr.size();
        int curr = 0, next = 0;
        for(int i=n-1; i>=0; i--){
            int take = arr[i] + next;
            int skip = curr;
            int prev = max(take, skip);
            next = curr;
            curr = prev;
        }
        return curr;
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        // vector<int> dp(arr.size() + 2, -1);
        // return solveMem(arr, 0, dp);
        // return solveTab(arr);
        return solveOp(arr);
    }
};
