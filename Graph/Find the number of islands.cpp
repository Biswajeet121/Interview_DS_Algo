
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/find-the-number-of-islands

class Solution {
  public:
    void solve(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visit){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visit[i][j] || grid[i][j] == 'W'){
            return;
        }
        visit[i][j] = true;
        //Top-left
        solve(i-1, j-1, grid, visit);
        //Top
        solve(i-1, j, grid, visit);
        //Top-right
        solve(i-1, j+1, grid, visit);
        //Right
        solve(i, j+1, grid, visit);
        //Bottom-right
        solve(i+1, j+1, grid, visit);
        //Bottom
        solve(i+1, j, grid, visit);
        //Bottom-left
        solve(i+1, j-1, grid, visit);
        //Left
        solve(i, j-1, grid, visit);
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        // queue<pair<int, int>> q;
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'L' && !visit[i][j]){
                    solve(i, j, grid, visit);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
