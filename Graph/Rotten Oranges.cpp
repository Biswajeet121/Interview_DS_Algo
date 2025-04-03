
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/rotten-oranges2536

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size(), m = mat[0].size();
        int minutes = 0, freshCnt = 0;
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1)
                    freshCnt++;
                else if(mat[i][j] == 2)
                    q.push({i, j});
            }
        }
        if(freshCnt == 0)
            return 0;
            
        while(!q.empty()){
            int k = q.size();
            while(k--){
                pair<int, int> front = q.front();
                q.pop();
                
                int x = front.first, y = front.second;
                //Top
                if(x-1 >= 0){
                    if(mat[x-1][y] == 1){
                        mat[x-1][y] = 2;
                        q.push({x-1, y});
                        freshCnt--;
                    }
                }
                //Left
                if(y-1 >= 0){
                    if(mat[x][y-1] == 1){
                        mat[x][y-1] = 2;
                        q.push({x, y-1});
                        freshCnt--;
                    }
                }
                //Down
                if(x+1 < n){
                    if(mat[x+1][y] == 1){
                        mat[x+1][y] = 2;
                        q.push({x+1, y});
                        freshCnt--;
                    }
                }
                //Right
                if(y+1 < m){
                    if(mat[x][y+1] == 1){
                        mat[x][y+1] = 2;
                        q.push({x, y+1});
                        freshCnt--;
                    }
                }
            }
            minutes++;
        }
        
        if(freshCnt == 0)
            return minutes - 1;
        return -1;
    }
};
