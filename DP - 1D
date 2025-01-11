
    Problem Link : https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    // Recursion
    int solve(vector<int>& nums, int i){
        if(i >= nums.size())
            return 0;

        int include = nums[i] + solve(nums, i+2);
        int exclude = 0 + solve(nums, i+1);
        return dp[i] = max(include, exclude);
    }
    // Top - Down
    int solveMem(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];

        int include = nums[i] + solveMem(nums, i+2, dp);
        int exclude = 0 + solveMem(nums, i+1, dp);
        return dp[i] = max(include, exclude);
    }
    // Bottom - Up
    int solveTab(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n+2, 0);  //Memorization 

        for(int i=n-1; i>=0; i--){
            int include = nums[i] + dp[i+2];
            int exclude = 0 + dp[i+1];
            dp[i] = max(include, exclude);
        }
        return dp[0];
    }
    // Space Optimiztion
    int solveSo(vector<int>& nums){
        int n = nums.size();
        int fir = 0, sec = 0;

        for(int i=n-1; i>=0; i--){
            int include = nums[i] + sec;
            int exclude = 0 + fir;
            int ans = max(include, exclude);
            sec = fir;
            fir = ans;
        }
        return fir;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();

        // return solve(nums, 0);  //Recursion
        
        // vector<int> dp(n + 1, -1);  //  Memorization 
        // return solveMem(nums, 0, dp);  //  Top - Down
      
        // return solveTab(nums);  // Bottom - Up
      
        return solveSo(nums);  // Space - Optimiztion
    }
};
