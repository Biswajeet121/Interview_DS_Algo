
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/solve-the-sudoku-1587115621

class Solution {
  public:
    // Function to find a solved Sudoku.
    bool isSafe(int row, int col, int val, vector<vector<int>> &mat){
        for(int i=0; i<9; i++){
            if((mat[row][i] == val) || (mat[i][col] == val))  return false;
        }
        int startRow = row - (row % 3), startCol = col - (col % 3);
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(mat[i + startRow][j + startCol] == val)  return false;
            }
        }
        return true;
    }
    bool solve(int row, int col, vector<vector<int>> &mat){
        if(row == 9)    return true;
        if(col == 9)    return solve(row+1, 0, mat);
        
        if(mat[row][col] != 0)  return solve(row, col+1, mat);
        
        for(int i=1; i<10; i++){
            if(isSafe(row, col, i, mat)){
                mat[row][col] = i;
                if(solve(row, col+1, mat))  return true;
                mat[row][col] = 0;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(0, 0, mat);
    }
};
