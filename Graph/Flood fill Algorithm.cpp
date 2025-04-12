
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/flood-fill-algorithm1856

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n = image.size(), m = image[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int color = image[sr][sc];
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int x = front.first, y = front.second;
            visit[x][y] = true;
            image[x][y] = newColor;
            //UP
            if((x-1 >= 0) && (image[x-1][y] == color) && (!visit[x-1][y])){
                q.push({x-1, y});
            }
            //Left
            if((y-1 >= 0) && (image[x][y-1] == color) && (!visit[x][y-1])){
                q.push({x, y-1});
            }
            //Down
            if((x+1 < n) && (image[x+1][y] == color) && (!visit[x+1][y])){
                q.push({x+1, y});
            }
            //right
            if((y+1 < m) && (image[x][y+1] == color) && (!visit[x][y+1])){
                q.push({x, y+1});
            }
        }
        
        return image;
    }
};
