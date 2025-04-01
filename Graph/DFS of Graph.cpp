
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/depth-first-traversal-for-a-graph

class Solution {
  public:
    void solve(int i, vector<vector<int>>& adj, vector<bool>& visit, vector<int>& ans){
        visit[i] = true;
        ans.push_back(i);
        for(auto x : adj[i]){
            if(!visit[x]){
                solve(x, adj, visit, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        vector<bool> visit(n, false);
        for(int i=0; i<n; i++){
            if(!visit[i]){
                solve(i, adj, visit, ans);
            }
        }
        return ans;
    }
};
