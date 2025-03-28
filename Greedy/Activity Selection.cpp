
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/activity-selection-1587115620

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<vector<int>> v;
        for(int i=0; i<n; i++){
            v.push_back({start[i], finish[i]});
        }
        sort(begin(v), end(v), [](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });
        int take = 1;
        int end = v[0][1];
        for(int i=1; i<n; i++){
            if(v[i][0] > end){
                take++;
                end = v[i][1];
            }
        }
        return take;
    }
};
