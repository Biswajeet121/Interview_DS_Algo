
  Problem Link : https://www.geeksforgeeks.org/problem-of-the-day?itm_source=geeksforgeeks&itm_medium=main_header&itm_campaign=practice_header

class Solution {
  public:
    bool solve(int i, int j, vector<vector<char>>& mat, string& word, vector<vector<bool>>& visited, int idx){
        
        int n = mat.size(), m = mat[0].size();
        if(idx == word.size())  return true;
        
        //left
        if(j-1 >= 0 && mat[i][j-1] == word[idx] && visited[i][j-1]){
            visited[i][j-1] = false;
            bool check = solve(i, j-1, mat, word, visited, idx+1);
            if(check)   return true;
            visited[i][j-1] = true;
        }
        //up
        if(i-1 >= 0 && mat[i-1][j] == word[idx] && visited[i-1][j]){
            visited[i-1][j] = false;
            bool check = solve(i-1, j, mat, word, visited, idx+1);
            if(check)   return true;
            visited[i-1][j] = true;
        }
        //right
        if(j+1 < m && mat[i][j+1] == word[idx] && visited[i][j+1]){
            visited[i][j+1] = false;
            bool check = solve(i, j+1, mat, word, visited, idx+1);
            if(check)   return true;
            visited[i][j+1] = true;
        }
        //down
        if(i+1 < n && mat[i+1][j] == word[idx] && visited[i+1][j]){
            visited[i+1][j] = false;
            bool check = solve(i+1, j, mat, word, visited, idx+1);
            if(check)   return true;
            visited[i+1][j] = true;
        }
        return false;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n = mat.size(), m = mat[0].size(), idx = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, true));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == word[idx]){
                    visited[i][j] = false;
                    bool check = solve(i, j, mat, word, visited, idx + 1);
                    if(check)   return true;
                    visited[i][j] = true;
                }
            }
        }
        return false;
    }
};
