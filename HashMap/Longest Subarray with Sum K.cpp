
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/longest-sub-array-with-sum-k0809

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        int sum = 0, maxi = 0;
        
        for(int i=0; i<n; i++){
             sum += arr[i];
             if(sum == k){
                 maxi = i + 1;
             }
             if(mp.find(sum - k) != mp.end()){
                 maxi = max(maxi, i - mp[sum - k]);
             }
             if(mp.find(sum) == mp.end()){
                 mp[sum] = i;
             }
        }
        return maxi;
    }
};
