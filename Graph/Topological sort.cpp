
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/topological-sort

class Solution {
  public:
    void topoSort(int i, vector<bool>& visit, stack<int>& st, unordered_map<int, list<int>>& adj){
        visit[i] = true;
        
        for(auto nbr: adj[i]){
            if(!visit[nbr]){
                topoSort(nbr, visit, st, adj);
            }
        }
        st.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, list<int>> adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> visit(V, false);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!visit[i]){
                topoSort(i, visit, st, adj);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
