
  Problem Link : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        int n = edges.size();
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i=0; i<n; i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> st;
        dist[src] = 0;
        st.insert({dist[src], src});
        
        while(!st.empty()){
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;
            
            st.erase(st.begin());
            
            for(auto nbr: adj[topNode]){
                if(nodeDistance + nbr.second < dist[nbr.first]){
                    auto record = st.find({dist[nbr.first], nbr.first});
                    if(record != st.end()){
                        st.erase(record);
                    }
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert({dist[nbr.first], nbr.first});
                }
            }
        }
        return dist;
    }
};
