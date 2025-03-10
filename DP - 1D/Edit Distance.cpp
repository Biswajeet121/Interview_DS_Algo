
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/edit-distance3702

class Solution {
  public:
    int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        if(i == a.size()){
            return b.size() - j;
        }
        if(j == b.size()){
            return a.size() - i;
        }
        if(dp[i][j] != -1){
            return dp[i][j]
        }
        int ans = 0;
        if(a[i] == b[j]){
            return solve(a, b, i+1, j+1, dp);
        }
        else{
            //insert
            int ins = 1 + solve(a, b, i, j+1, dp);
            //remove
            int rem = 1 + solve(a, b, i+1, j, dp);
            //update
            int rep = 1 + solve(a, b, i+1, j+1, dp);
            
            ans = min(ins, min(rem, rep));
        }
        return dp[i][j] = ans;
    }
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return solve(s1, s2, 0, 0, dp);
    }
};
