
  problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/stock-span-problem-1587115621

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n = arr.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, 1);
        
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top().first <= arr[i]){
                int idx = st.top().second;
                ans[i] += ans[idx];
                st.pop();
            }   
            st.push({arr[i], i});
        }
        return ans;
    }
};
