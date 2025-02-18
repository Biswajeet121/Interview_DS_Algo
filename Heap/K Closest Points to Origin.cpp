
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/k-closest-points-to-origin--172242

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        int n = points.size();
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<n; i++){
            int cal = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({cal, i});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
