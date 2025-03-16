
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/minimum-number-of-jumps-1587115620
  
class Solution {
  public:
    int n;
    int solve(vector<int>& arr, int i, vector<int>& dp){
        if(i >= n-1)
            return 0;
        if(arr[i] == 0)
            return INT_MAX;
        if(dp[i] != -1)
            return dp[i];
        int cnt = INT_MAX;
        for(int j=i+1; j<i+arr[i]+1; j++){
            int ans = solve(arr, j, dp);
            if(ans != INT_MAX)
                cnt = min(cnt, ans + 1);   
        }
        return dp[i] = cnt;
    }
    int minJumps(vector<int>& arr) {
        // code here
        n = arr.size();
        vector<int> dp(n+1, -1);
        int ans = solve(arr, 0, dp) ;
        return ans == INT_MAX ? -1: ans;
    }
};
