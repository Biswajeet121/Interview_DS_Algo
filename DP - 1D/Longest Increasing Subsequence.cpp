
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-increasing-subsequence-1587115620

class Solution {
  public:
    int solveOptimal(int n, vector<int>& arr){
        vector<int> ans;
        ans.push_back(arr[0]);
        
        for(int i=1; i<n; i++){
            if(arr[i] > ans.back()){
                ans.push_back(arr[i]);
            }
            else{
                int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[idx] = arr[i];
            }
        }
        return ans.size();
    }
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        return solveOptimal(n, arr);
    }
};
