
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-palindromic-subsequence-1612327878

    //Top - Down
int solve(string &s, int i, int j, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(s[i] == s[j]){
            if(i == j){
                ans = 1 + solve(s, i+1, j-1, dp);
            }
            else{
                ans = 2 + solve(s, i+1, j-1, dp);
            }
        }
        else{
            ans = max(solve(s, i+1, j, dp), solve(s, i, j-1, dp));
        }
        return dp[i][j] = ans;
    }
    // Bottom - UP
    int solveTab(string &s){
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n+1; j++){
                int ans = 0;
                if(s[i] == s[j-1]){
                    if(i == j-1){
                        ans = 1 + dp[i+1][j-1];
                    }
                    else{
                        ans = 2 + dp[i+1][j-1];
                    }
                }
                else{
                    ans = max(dp[i+1][j], dp[i][j-1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n];
    }
    int longestPalinSubseq(string &s) {
        // code here
        int n = s.size();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // return solve(s, 0, n-1, dp);
        return solveTab(s);
    }
