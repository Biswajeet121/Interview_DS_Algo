
    Problem Link : https://leetcode.com/problems/count-servers-that-communicate/solutions/?envType=daily-question&envId=2025-01-23

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    if(row[i] >= 2 || col[j] >= 2){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
