
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/n-queen-problem0315

class Solution {
  public:
    vector<vector<int>> res;
    
    void store(int n, vector<vector<int>>& ans){
        vector<int> arr;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(ans[i][j] == 1)
                    arr.push_back(j+1);
            }
        }
        res.push_back(arr);
    }
    
    bool isSafe(int row, int col, int n, vector<vector<int>>& ans){
        // same-row
        for(int i=0; i<n; i++){
            if(ans[row][i] == 1)
                return false;
        }
        
        //same-col
        for(int i=0; i<n; i++){
            if(ans[i][col] == 1)
                return false;
        }
        
        //same-diagonal
        int i=row, j=col;
        while(i>=0 && j>=0){
            if(ans[i][j] == 1)  return false;
            i--;    j--;
        }
        i=row, j=col;
        while(i>=0 && j<n){
            if(ans[i][j] == 1)  return false;
            i--;    j++;
        }
        i=row, j=col;
        while(i<n && j>=0){
            if(ans[i][j] == 1)  return false;
            i++;    j--;
        }
        i=row, j=col;
        while(i<n && j<n){
            if(ans[i][j] == 1)  return false;
            i++;    j++;
        }
        return true;
    }
    
    void solve(int col, int n, vector<vector<int>>& ans){
        if(n == col){
            store(n, ans);
            return ;
        }
        
        for(int i=0; i<n; i++){
            if(isSafe(i, col, n, ans)){
                ans[i][col] = 1;
                solve(col+1, n, ans);
                ans[i][col] = 0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans(n, vector<int>(n, 0));
        solve(0, n, ans);
        return res;
    }
};
