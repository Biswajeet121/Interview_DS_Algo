
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/detect-cycle-in-an-undirected-graph

class Solution {
  public:
    bool solve(int i, vector<bool>& visit, vector<list<int>>& edges, 
    unordered_map<int, int>& parent){
        parent[i] = -1;
        visit[i] = true;
        queue<int> q;
        q.push(i);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto x: edges[front]){
                if(visit[x] && x != parent[front]){
                    return true;
                }
                else if(!visit[x]){
                    visit[x] = true;
                    parent[x] = front;
                    q.push(x);
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<bool> visit(V, false);
        unordered_map<int, int> parent;
        vector<list<int>> adj(V);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0; i<V; i++){
            if(visit[i])    continue;
            bool ans = solve(i, visit, adj, parent);
            if(ans) return true;
        }
        return false;
    }
};
