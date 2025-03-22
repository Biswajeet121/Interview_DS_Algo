
  Problem Link : https://www.geeksforgeeks.org/problems/house-robber-ii/1

class Solution {
  public:
    int solve(vector<int>& arr, int i, int n, vector<int>& dp){
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int take = arr[i] + solve(arr, i+2, n, dp);
        int skip = solve(arr, i+1, n, dp);
        return dp[i] = max(take, skip);
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);
        return max(solve(arr, 0, n-1, dp1), solve(arr, 1, n, dp2));
    }
};
