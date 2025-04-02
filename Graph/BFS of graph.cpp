
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/bfs-traversal-of-graph

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<int> res;
        vector<bool> visit(n, false);
        queue<int> q;
        
        for(int i=0; i<n; i++){
            if(visit[i])
                continue;
            q.push(i);
            visit[i] = true;
            
            while(!q.empty()){
                int val = q.front();
                res.push_back(val);
                q.pop();
                for(auto x : adj[val]){
                    if(!visit[x]){
                        visit[x] = true;
                        q.push(x);
                    }
                }
            }
            
        }
        return res;
    }
};
